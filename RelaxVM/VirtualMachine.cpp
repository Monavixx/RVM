#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv), mainClass(nullptr)
{
	filename = argv[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	executableFile.close();
	
	while(!stack.isEmpty())
	{
		auto item = stack.pop();
		heap.removeAll(item);
		if (item != nullptr)
		{
			delete item;
		}
	}
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

	while (executableFile.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(executableFile));
		ProccesInstructionCreating(instruction, executableFile);
	}
	

	if (mainClass == nullptr)
	{
		Exit("main class not found");
	}

	Method* mainMethod = mainClass->GetMethod("Main", "void", {});
	if (mainMethod == nullptr)
	{
		Exit("main method not found");
	}
	Frame mainFrame(mainMethod);

	QBuffer bufferMainMethodCode(&(mainMethod->GetCode()));
	if (!bufferMainMethodCode.open(QIODevice::ReadOnly))
	{
		Exit("buffer main method error!");
	}

	while (bufferMainMethodCode.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(bufferMainMethodCode));
		ProcessInstructionExecuting(instruction, bufferMainMethodCode, mainFrame);
	}
}

void VirtualMachine::ProcessInstructionExecuting(Instruction instruction, QIODevice& device, Frame& frame)
{
	switch (instruction)
	{
		case CALL_METHOD:
		{
			CallMethod(device);
			break;
		}
		case PUSH_STR:
		{
			PushStr(device);
			break;
		}
		case PUSH_INT32:
		{
			PushInt32(device);
			break;
		}
		case RETURN:
		{
			Return(device);
			break;
		}
		case NEW:
		{
			New(device);
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
			Dup(device);
			break;
		}
		case ADD:
		{
			Add(device);
			break;
		}
		case JMP:
		{
			Jmp(device);
			break;
		}
		case JMPIF:
		{
			Jmpif(device);
			break;
		}
		case GC:
		{
			Gc(device);
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

void VirtualMachine::CreateMainClass(QIODevice& device)
{
	QString nameMainClass = ByteArrayRead::ReadSizeAndString(device);
	classes.push_back(Class(nameMainClass));
	mainClass = &classes.back();
}

void VirtualMachine::CreateClass(QIODevice& device)
{
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
		Parameter parameter(parameterDataType);
		parameters.push_back(parameter);
	}
	QByteArray code = ByteArrayRead::ReadSizeAndByteArray(device);

	Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);

	Class* _class = classes.FindClassByName(nameClass);
	_class->AddMethod(method);
}

void VirtualMachine::CallMethod(QIODevice& device)
{
	bool isStatic = ByteArrayRead::ReadByte(device);
	bool isStd = ByteArrayRead::ReadByte(device);
	QString dataType = ByteArrayRead::ReadSizeAndString(device);
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

		StdMethod* callableStdMethod = stdClass->GetMethod(nameMethod, dataType, parameters);
		if (callableStdMethod == nullptr)
			Exit("std method not exists");

		Object* returnedObject = callableStdMethod->CallFunction(stack);
		if (returnedObject != nullptr)
		{
			heap.push_back(returnedObject);
			stack.push(returnedObject);
		}
	}
}

void VirtualMachine::PushStr(QIODevice& device)
{
	QString stringFromFile = ByteArrayRead::ReadSizeAndString(device);
	RelaxString* pushingString = new RelaxString(stringFromFile);
	heap.push_back(pushingString);
	stack.push(pushingString);
}

void VirtualMachine::PushInt32(QIODevice& device)
{
	int numberFromFile = ByteArrayRead::ReadInt(device);
	RelaxInt32* pushingInt32 = new RelaxInt32(numberFromFile);
	heap.push_back(pushingInt32);
	stack.push(pushingInt32);
}

void VirtualMachine::Return(QIODevice& device)
{
}
void VirtualMachine::New(QIODevice& device)
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

		StdMethod* construction = _class->GetMethod(dataType, dataType, parameters);
		if (construction == nullptr)
			Exit("Construction not exists");

		Object* newObject = construction->CallFunction(stack);
		heap.push_back(newObject);
		stack.push(newObject);
	}
}

void VirtualMachine::Set(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	Object* data = stack.pop();

	Variable* variable = currentFrame.FindVariableById(id);
	if (variable == nullptr)
		Exit("set: local variable with id " + QString::number(id) + " not exists");

	data->IncAmountUsers();
	variable->SetData(data);
}

void VirtualMachine::Get(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	Variable* variable = currentFrame.FindVariableById(id);

	if (variable == nullptr)
		Exit("get: local variable with id " + QString::number(id) + " not exists");

	Object* data = variable->GetData();
	stack.push(data);
}

void VirtualMachine::Local(QIODevice& device, Frame& currentFrame)
{
	int id = ByteArrayRead::ReadInt(device);
	currentFrame.CreateVariable(id);
}

void VirtualMachine::Dup(QIODevice& device)
{
	Object* data = stack.pop();
	stack.push(data);
	stack.push(data);
}

void VirtualMachine::Add(QIODevice& device)
{
	Object* secondData = stack.pop();
	Object* firstData = stack.pop();
	if (firstData->GetDataType() == "Relax.Int32" && secondData->GetDataType() == "Relax.Int32")
	{
		RelaxInt32* firstNumber = dynamic_cast<RelaxInt32*>(firstData);
		RelaxInt32* secondNumber = dynamic_cast<RelaxInt32*>(secondData);
		int result = firstNumber->GetData() + secondNumber->GetData();
		RelaxInt32* resultNumber = new RelaxInt32(result);
		heap.push_back(resultNumber);
		stack.push(resultNumber);
	}
	else
	{
		Exit("add: on stack non number value");
	}
}

void VirtualMachine::Jmp(QIODevice& device)
{
	int offset = ByteArrayRead::ReadInt(device);
	device.seek(offset);
}

void VirtualMachine::Jmpif(QIODevice& device)
{
	int offset = ByteArrayRead::ReadInt(device);
	bool isTrue = dynamic_cast<RelaxBool*>(stack.pop())->GetData();
	if(isTrue)
	{
		device.seek(offset);
	}
}

void VirtualMachine::Gc(QIODevice& device)
{
	for (auto& item : heap)
	{
		if (item->GetAmountUsers() <= 0)
		{
			delete item;
			item = nullptr;
		}
	}
	heap.removeAll(nullptr);
}
