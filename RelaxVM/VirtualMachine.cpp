#include "VirtualMachine.h"

VirtualMachine::VirtualMachine() : gv(new GlobalVariables)
{
	gv->mainClass = nullptr;
	gv->filename = Args::args[1];
	gv->executableFile.setFileName(gv->filename);
}

VirtualMachine::~VirtualMachine()
{
	gv->executableFile.close();

	for (auto& item : gv->heap)
	{
		if(item != nullptr)
			delete item;
	}
	
}

void VirtualMachine::Start()
{
	if (!gv->executableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error!");
	}

	int versionCode = ByteArrayRead::ReadInt(gv->executableFile);
	if (versionCode != gv->version)
		Exit("version " + QString::number(gv->version) + " is required to run this code");

	while (gv->executableFile.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(gv->executableFile));
		ParseCode(instruction);
	}

	if (gv->mainClass == nullptr)
	{
		Exit("main class not found");
	}

	Method* mainMethod = gv->mainClass->GetMethod("Main", {});
	Frame* frame = new Frame(mainMethod);
	gv->frameStack.push(frame);
	ExecuteMethod();

}

void VirtualMachine::ParseCode(Instruction instruction)
{
	OpBase* op;
	switch (instruction)
	{
	case CREATE_MAIN_CLASS:
	{
		op = new OpMclass;
		break;
	}
	case CREATE_CLASS:
	{
		op = new OpClass;
		break;
	}
	case CREATE_METHOD:
	{
		op = new OpMethod;
		break;
	}
	default:
		Exit("Opcode not exists!");
	}

	op->SetGlobalVariables(gv);
	op->Parse(gv->executableFile);
	op->Run();
	opCodes.push_back(op);
}


void VirtualMachine::ExecuteMethod()
{
	Frame* frame = gv->frameStack.top();
	Method* method = frame->GetMethod();
	if (method == nullptr)
	{
		Exit("main method not found");
	}

	frame->GetStack().SetMaxSize(30);

	clock_t start, end, ReResult;
	start = clock();
	while(!frame->IsEnd())
	{
		OpBase* op = frame->Next();
		op->SetFrame(frame);
		op->Run();
		if (dynamic_cast<OpReturn*>(op) != nullptr) return;
	}
	end = clock();
	ReResult = end - start;
	std::cout << "\n\n\nRelax: " << ReResult << "ms\n";
}
/*
void VirtualMachine::CreateMainClass(QIODevice& device)
{
	QString nameMainClass = ByteArrayRead::ReadSizeAndString(device);
	classes.push_back(Class(nameMainClass));
	mainClass = &classes.back();
}

void VirtualMachine::CreateClass(QIODevice& device)
{
	QString nameClass = ByteArrayRead::ReadSizeAndString(device);
	classes.push_back(Class(nameClass));
}

void VirtualMachine::CreateMethod(QIODevice& device)
{
	AccessModifier accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(device));
	bool isStatic = ByteArrayRead::ReadByte(device);

	QString dataType = ByteArrayRead::ReadSizeAndString(device);
	QString nameClass = ByteArrayRead::ReadSizeAndString(device);
	QString name = ByteArrayRead::ReadSizeAndString(device);

	int amountParameters = ByteArrayRead::ReadInt(device);
	QList<Parameter> parameters;

	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		QString parameterName = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameter.SetName(parameterName);
		parameters.push_back(parameter);
	}
	QByteArray code = ByteArrayRead::ReadSizeAndByteArray(device);

	Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);

	Class* _class = classes.FindClassByName(nameClass);
	_class->AddMethod(method);
}

void VirtualMachine::CallMethod(QIODevice& device, Frame& currentFrame)
{
	bool isStd = ByteArrayRead::ReadByte(device);
	bool isStatic = ByteArrayRead::ReadByte(device);
	QString nameClass = ByteArrayRead::ReadSizeAndString(device);
	QString nameMethod = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	QList<Parameter> parameters;
	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}

	if (isStd)
	{
		StdClass* stdClass = StdClassList::GetInstance()->FindClassByName(nameClass);
		if (stdClass == nullptr)
			Exit("std class not exists");

		StdMethod* callableStdMethod = stdClass->GetMethod(nameMethod, parameters);
		if (callableStdMethod == nullptr)
			Exit("std method not exists");

		Object* returnedObject = callableStdMethod->CallFunction(currentFrame.GetStack());
		if (returnedObject != nullptr)
		{
			heap.push_back(returnedObject);
			currentFrame.GetStack().push(returnedObject);
		}
	}
	else
	{
		Class* declClass = classes.FindClassByName(nameClass);
		if (declClass == nullptr)
			Exit("Callm: class not found");

		Method* callableMethod = declClass->GetMethod(nameMethod, parameters);
		if (callableMethod == nullptr)
			Exit("Callm: method not found");

		Frame* frame = new Frame(callableMethod);
		frame->GetStack().SetMaxSize(30);

		// parameters 
		for (auto& item : callableMethod->GetParameters())
		{
			Object* data = currentFrame.GetStack().pop();
			if (data->GetDataType() != item.GetDataType())
				Exit("Error parameters type");
			frame->GetStack().push(data);
		}


		frameStack.push(frame);
		ExecuteMethod();
	}
}

void VirtualMachine::PushStr(QIODevice& device, Frame& currentFrame)
{
	QString stringFromFile = ByteArrayRead::ReadSizeAndString(device);
	RelaxString* pushingString = new RelaxString(stringFromFile);
	heap.push_back(pushingString);
	currentFrame.GetStack().push(pushingString);
}

void VirtualMachine::PushInt32(QIODevice& device, Frame& currentFrame)
{
	int numberFromFile = ByteArrayRead::ReadInt(device);
	RelaxInt32* pushingInt32 = new RelaxInt32(numberFromFile);
	heap.push_back(pushingInt32);
	currentFrame.GetStack().push(pushingInt32);
}

void VirtualMachine::Return(QIODevice& device, Frame& currentFrame)
{
	Object* data = currentFrame.GetStack().pop();
	if (currentFrame.GetMethod()->GetDataType() != data->GetDataType())
		Exit("Error return data type");
	delete frameStack.pop();
	frameStack.top()->GetStack().push(data);
}

void VirtualMachine::New(QIODevice& device, Frame& currentFrame)
{
	bool isStd = ByteArrayRead::ReadByte(device);
	QString dataType = ByteArrayRead::ReadSizeAndString(device);
	int amountParameters = ByteArrayRead::ReadInt(device);

	QList<Parameter> parameters;
	for (int i = 0; i < amountParameters; ++i)
	{
		QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}

	Object* object = nullptr;
	if (isStd)
	{
		StdClass* _class = StdClassList::GetInstance()->FindClassByName(dataType);
		if (_class == nullptr)
			Exit("Std class not exists");

		StdMethod* construction = _class->GetMethod(dataType, parameters);
		if (construction == nullptr)
			Exit("Construction not exists");

		Object* newObject = construction->CallFunction(currentFrame.GetStack());
		heap.push_back(newObject);
		currentFrame.GetStack().push(newObject);
	}
}

void VirtualMachine::Set(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	Object* data = currentFrame.GetStack().pop();
	Variable* variable = currentFrame.FindVariableById(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + QString::number(id) + " not exists");

	if (data->GetDataType() == variable->GetData()->GetDataType()) // <-----
	{
		data->IncAmountUsers();
		variable->SetData(data);
	}
}

void VirtualMachine::Get(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	Variable* variable = currentFrame.FindVariableById(id);

	if (variable == nullptr)
		Exit("get: local variable with id " + QString::number(id) + " not exists");

	Object* data = variable->GetData();
	currentFrame.GetStack().push(data);
}

void VirtualMachine::Local(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	QString dataType = ByteArrayRead::ReadSizeAndString(device);
	currentFrame.CreateVariable(id, dataType);
}

void VirtualMachine::Dup(QIODevice& device, Frame& currentFrame)
{
	Object* data = currentFrame.GetStack().pop();
	currentFrame.GetStack().push(data);
	currentFrame.GetStack().push(data);
}

void VirtualMachine::Add(QIODevice& device, Frame& currentFrame)
{
	Object* firstData = currentFrame.GetStack().pop();
	Object* secondData = currentFrame.GetStack().pop();
	currentFrame.GetStack().push(secondData);
	currentFrame.GetStack().push(firstData);

	StdClass* declClass = StdClassList::GetInstance()->FindClassByName(firstData->GetDataType());
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	StdMethod* operatorAdd = declClass->GetMethod("operator+", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator+ not found");
	
	Object* returnedObject = operatorAdd->CallFunction(currentFrame.GetStack());
	if (returnedObject != nullptr)
	{
		heap.push_back(returnedObject);
		currentFrame.GetStack().push(returnedObject);
	}
}

void VirtualMachine::Jmp(QIODevice& device, Frame& currentFrame)
{
	int offset = ByteArrayRead::ReadInt(device);
	device.seek(offset);
}

void VirtualMachine::Jmpif(QIODevice& device, Frame& currentFrame)
{
	int offset = ByteArrayRead::ReadInt(device);
	bool isTrue = dynamic_cast<RelaxBool*>(currentFrame.GetStack().pop())->GetData();
	if(isTrue)
	{
		device.seek(offset);
	}
}

void VirtualMachine::Gc(QIODevice& device, Frame& currentFrame)
{
	for (auto& item : heap)
	{
		if (item != nullptr)
		{
			if (item->GetAmountUsers() <= 0)
			{
				delete item;
				item = nullptr;
			}
		}
	}
	heap.removeAll(nullptr);
}

void VirtualMachine::Newarr(QIODevice& device, Frame& currentFrame)
{
	int arraySize = dynamic_cast<RelaxInt32*>(currentFrame.GetStack().pop())->GetData();
	QString dataType = ByteArrayRead::ReadSizeAndString(device);
	RelaxArray* newArray = new RelaxArray(dataType, arraySize);
	heap.push_back(newArray);
	currentFrame.GetStack().push(newArray);
}

void VirtualMachine::Getarr(QIODevice& device, Frame& currentFrame)
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(currentFrame.GetStack().pop());
	int index = dynamic_cast<RelaxInt32*>(currentFrame.GetStack().pop())->GetData();
	currentFrame.GetStack().push(arr->GetByIndex(index));
}

void VirtualMachine::Setarr(QIODevice& device, Frame& currentFrame)
{
	RelaxArray* arr = dynamic_cast<RelaxArray*>(currentFrame.GetStack().pop());
	int index = dynamic_cast<RelaxInt32*>(currentFrame.GetStack().pop())->GetData();
	Object* data = currentFrame.GetStack().pop();
	
	arr->SetByIndex(index, data);
}

void VirtualMachine::PushBool(QIODevice& device, Frame& currentFrame)
{
	bool data = (bool)ByteArrayRead::ReadByte(device);
	RelaxBool* pushingData = new RelaxBool(data);
	heap.push_back(pushingData);
	currentFrame.GetStack().push(pushingData);
}

void VirtualMachine::PushFloat(QIODevice& device, Frame& currentFrame)
{
	float data = ByteArrayRead::ReadFloat(device);
	RelaxFloat* pushingData = new RelaxFloat(data);
	heap.push_back(pushingData);
	currentFrame.GetStack().push(pushingData);
}

void VirtualMachine::Sub(QIODevice& device, Frame& currentFrame)
{
	Object* firstData = currentFrame.GetStack().pop();
	Object* secondData = currentFrame.GetStack().pop();
	currentFrame.GetStack().push(secondData);
	currentFrame.GetStack().push(firstData);

	StdClass* declClass = StdClassList::GetInstance()->FindClassByName(firstData->GetDataType());
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	StdMethod* operatorAdd = declClass->GetMethod("operator-", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator+ not found");

	Object* returnedObject = operatorAdd->CallFunction(currentFrame.GetStack());
	if (returnedObject != nullptr)
	{
		heap.push_back(returnedObject);
		currentFrame.GetStack().push(returnedObject);
	}
}

void VirtualMachine::Mul(QIODevice& device, Frame& currentFrame)
{
	Object* firstData = currentFrame.GetStack().pop();
	Object* secondData = currentFrame.GetStack().pop();
	currentFrame.GetStack().push(secondData);
	currentFrame.GetStack().push(firstData);

	StdClass* declClass = StdClassList::GetInstance()->FindClassByName(firstData->GetDataType());
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	StdMethod* operatorAdd = declClass->GetMethod("operator*", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator+ not found");

	Object* returnedObject = operatorAdd->CallFunction(currentFrame.GetStack());
	if (returnedObject != nullptr)
	{
		heap.push_back(returnedObject);
		currentFrame.GetStack().push(returnedObject);
	}
}

void VirtualMachine::Div(QIODevice& device, Frame& currentFrame)
{
	Object* firstData = currentFrame.GetStack().pop();
	Object* secondData = currentFrame.GetStack().pop();
	currentFrame.GetStack().push(secondData);
	currentFrame.GetStack().push(firstData);

	StdClass* declClass = StdClassList::GetInstance()->FindClassByName(firstData->GetDataType());
	if (declClass == nullptr)
		Exit("Add: decl class not found");
	StdMethod* operatorAdd = declClass->GetMethod("operator/", { Parameter(secondData->GetDataType()) });
	if (operatorAdd == nullptr)
		Exit("Add: operator+ not found");

	Object* returnedObject = operatorAdd->CallFunction(currentFrame.GetStack());
	if (returnedObject != nullptr)
	{
		heap.push_back(returnedObject);
		currentFrame.GetStack().push(returnedObject);
	}
}
*/