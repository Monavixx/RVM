#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const QStringList& argv) : arguments(argv), mainClass(nullptr)
{
	filename = argv[1];
	executableFile.setFileName(filename);
}

VirtualMachine::~VirtualMachine()
{
	executableFile.close();
	delete mainClass;
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
		ProcessInstruction(instruction);
	}
}

void VirtualMachine::ProcessInstruction(Instruction instruction)
{
	switch (instruction)
	{
		case CREATE_MAIN_CLASS:
		{
			QString nameMainClass = ByteArrayRead::ReadSizeAndString(executableFile);
			mainClass = new Class(nameMainClass);
			break;
		}
		case CREATE_CLASS:
		{
			break;
		}
		case CREATE_METHOD:
		{
			AccessModifier accessModifier = static_cast<AccessModifier>(ByteArrayRead::ReadByte(executableFile));
			bool isStatic = ByteArrayConvert::byteArrayToByte(executableFile.read(1));

			QString dataType = ByteArrayRead::ReadSizeAndString(executableFile);
			QString nameClass = ByteArrayRead::ReadSizeAndString(executableFile);
			QString name = ByteArrayRead::ReadSizeAndString(executableFile);

			int amountParameters = ByteArrayRead::ReadInt(executableFile);
			QList<Parameter> parameters;

			for (int i = 0; i < amountParameters; ++i)
			{
				QString parameterDataType = ByteArrayRead::ReadSizeAndString(executableFile);
				QString parameterName = ByteArrayRead::ReadSizeAndString(executableFile);
				Parameter parameter(parameterName, parameterDataType);
				parameters.push_back(parameter);
			}

			Method method(name, dataType, nameClass, parameters, accessModifier, isStatic);
			//TODO: добавление метода в класс

			break;
		}
		case CALL_METHOD:
		{
			break;
		}
		case PUSH:
		{
			break;
		}
		case PUSH_STR:
		{
			break;
		}
		case RETURN:
		{
			break;
		}
		case END_METHOD:
		{
			break;
		}
	}
}
