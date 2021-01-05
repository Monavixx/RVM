#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv), mainClass(nullptr)
{
	filename = argv[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	executableFile.close();
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

	QBuffer bufferMainMethodCode(&(mainMethod->GetCode()));
	if (!bufferMainMethodCode.open(QIODevice::ReadOnly))
	{
		Exit("buffer main method error!");
	}

	while (bufferMainMethodCode.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(bufferMainMethodCode));
		ProcessInstructionExecuting(instruction, bufferMainMethodCode);
	}
}

void VirtualMachine::ProcessInstructionExecuting(Instruction instruction, QIODevice& device)
{
	switch (instruction)
	{
		case CREATE_VAR: 
		{
			int variableId = ByteArrayRead::ReadInt(device);
			bool isStd = ByteArrayRead::ReadByte(device);
			QString dataType = ByteArrayRead::ReadSizeAndString(device);
			int amountParameters = ByteArrayRead::ReadInt(device);

			QList<Parameter> parameters;
			for (int i = 0; i < amountParameters; ++i)
			{
				QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
				QString parameterName = ByteArrayRead::ReadSizeAndString(device);
				Parameter parameter(parameterName, parameterDataType);
				parameters.push_back(parameter);
			}

			Object* object = nullptr;
			if(isStd)
				object = StdTypesConstructors::CreateObject(dataType, parameters, stack);

			Variable* variable = new Variable(variableId, object);
			heap.push_back(variable);

			break;
		}
		//TODO: отделить call std от call noStd путём создания интрукций call и callstd
		case CALL_METHOD:
		{
			bool isStatic = ByteArrayRead::ReadByte(device);
			if (isStatic)
			{
				bool isStd = ByteArrayRead::ReadByte(device);
				QString dataType = ByteArrayRead::ReadSizeAndString(device);
				QString nameClass = ByteArrayRead::ReadSizeAndString(device);
				QString nameMethod = ByteArrayRead::ReadSizeAndString(device);
				int amountParameters = ByteArrayRead::ReadInt(device);

				QList<Parameter> parameters;
				for (int i = 0; i < amountParameters; ++i)
				{
					QString parameterDataType = ByteArrayRead::ReadSizeAndString(device);
					QString parameterName = ByteArrayRead::ReadSizeAndString(device);
					Parameter parameter(parameterName, parameterDataType);
					parameters.push_back(parameter);
				}

				if (isStd)
				{
					StdClass* stdClass = StdClassList::GetInstance()->FindClassByName(nameClass);

					if (stdClass == nullptr)
						Exit("std class not exists");

					StdMethod* callableStdMethod = stdClass->GetMethod(nameMethod, dataType, parameters);

					callableStdMethod->CallFunction(stack);
				}
			}
			break;
		}
		case PUSH:
		{
			int variableId = ByteArrayRead::ReadInt(device);

			Variable* variable = heap.FindVariableById(variableId);

			if (variable == nullptr)
				Exit("Push: id " + QString::number(variableId) + " not exitst");
			
			stack.push(variable);

			break;
		}
		case PUSH_STR:
		{
			QString stringFromFile = ByteArrayRead::ReadSizeAndString(device);
			RelaxString* pushingString = new RelaxString(stringFromFile);
			Variable* pushingVariable = new Variable(2, pushingString);

			stack.push(pushingVariable);

			break;
		}
		case RETURN:
		{
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
			QString nameMainClass = ByteArrayRead::ReadSizeAndString(device);
			classes.push_back(Class(nameMainClass));
			mainClass = &classes.back();

			break;
		}
		case CREATE_CLASS:
		{
			break;
		}
		case CREATE_METHOD:
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
				Parameter parameter(parameterName, parameterDataType);
				parameters.push_back(parameter);
			}
			QByteArray code = ByteArrayRead::ReadSizeAndByteArray(device);

			Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);

			Class* _class = classes.FindClassByName(nameClass);
			_class->AddMethod(method);

			break;
		}
		
	}
}

