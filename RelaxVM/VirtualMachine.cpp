#include "VirtualMachine.h"

VirtualMachine::VirtualMachine() : mainClass(nullptr)
{
	filename = Args::args[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	executableFile.close();

	for (auto& item : heap)
	{
		if(item != nullptr)
			delete item;
	}
	
}

void VirtualMachine::Start()
{
	if (!executableFile.open(QIODevice::ReadOnly))
	{
		Exit("File open error!");
	}

	int versionCode = ByteArrayRead::ReadInt(executableFile);
	if (versionCode != version)
		Exit("version " + QString::number(version) + " is required to run this code");

	while (executableFile.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(executableFile));
		ProccesInstructionCreating(instruction, executableFile);
	}
	

	if (mainClass == nullptr)
	{
		Exit("main class not found");
	}

	Method* mainMethod = mainClass->GetMethod("Main", {});
	Frame* frame = new Frame(mainMethod);
	frame->GetStack().SetMaxSize(30);
	frameStack.push(frame);
	ExecuteMethod();

}

void VirtualMachine::ProcessInstructionExecuting(Instruction instruction, QIODevice& device, Frame& frame)
{
	switch (instruction)
	{
		case CALL_METHOD:
		{
			CallMethod(device, frame);
			break;
		}
		case PUSH_STR:
		{
			PushStr(device, frame);
			break;
		}
		case PUSH_INT32:
		{
			PushInt32(device, frame);
			break;
		}
		case RETURN:
		{
			Return(device, frame);
			break;
		}
		case NEW:
		{
			New(device, frame);
			break;
		}
		case SET:
		{
			Set(device, frame);
			break;
		}
		case GET:
		{
			Get(device, frame);
			break;
		}
		case LOCAL:
		{
			Local(device, frame);
			break;
		}
		case DUP:
		{
			Dup(device, frame);
			break;
		}
		case ADD:
		{
			Add(device, frame);
			break;
		}
		case JMP:
		{
			Jmp(device, frame);
			break;
		}
		case JMPIF:
		{
			Jmpif(device, frame);
			break;
		}
		case GC:
		{
			Gc(device, frame);
			break;
		}
		case NEWARR:
		{
			Newarr(device, frame);
			break;
		}
		case GETARR:
		{
			Getarr(device, frame);
			break;
		}
		case SETARR:
		{
			Setarr(device, frame);
			break;
		}
		case PUSH_BOOL:
		{
			PushBool(device, frame);
			break;
		}
		case PUSH_FLOAT:
		{
			PushFloat(device, frame);
			break;
		}
		case SUB:
		{
			Sub(device, frame);
			break;
		}
		case MUL:
		{
			Mul(device, frame);
			break;
		}
		case DIV:
		{
			Div(device, frame);
			break;
		}
	}
}
void VirtualMachine::ProccesInstructionCreating(Instruction instruction, QIODevice& device)
{
	switch (instruction)
	{
		case CREATE_MAIN_CLASS:
		{
			CreateMainClass(device);
			break;
		}
		case CREATE_CLASS:
		{
			CreateClass(device);
			break;
		}
		case CREATE_METHOD:
		{
			CreateMethod(device);
			break;
		}
	}
}

void VirtualMachine::ExecuteMethod()
{
	Frame* frame = frameStack.top();
	Method* method = frame->GetMethod();

	if (method == nullptr)
	{
		Exit("main method not found");
	}

	QByteArray mainMethodCode = method->GetCode();
	QBuffer bufferMainMethodCode(&mainMethodCode);
	if (!bufferMainMethodCode.open(QIODevice::ReadOnly))
	{
		Exit("buffer main method error!");
	}

	while (bufferMainMethodCode.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(bufferMainMethodCode));
		ProcessInstructionExecuting(instruction, bufferMainMethodCode, *frame);
	}
}

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
	bool isStatic = ByteArrayRead::ReadByte(device);
	bool isStd = ByteArrayRead::ReadByte(device);
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

		/* parameters */
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
	int index = dynamic_cast<RelaxInt32*>(currentFrame.GetStack().pop())->GetData();
	RelaxArray* arr = dynamic_cast<RelaxArray*>(currentFrame.GetStack().pop());
	currentFrame.GetStack().push(arr->GetByIndex(index));
}

void VirtualMachine::Setarr(QIODevice& device, Frame& currentFrame)
{
	Object* data = currentFrame.GetStack().pop();
	int index = dynamic_cast<RelaxInt32*>(currentFrame.GetStack().pop())->GetData();
	RelaxArray* arr = dynamic_cast<RelaxArray*>(currentFrame.GetStack().pop());
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
