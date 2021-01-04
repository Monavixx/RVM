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

	while (!stack.isEmpty()) 
	{
		delete stack.pop();
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
		ProccesInstructionCreating(instruction);
	}
	
}

void VirtualMachine::ProcessInstructionExecuting(Instruction instruction)
{
	switch (instruction)
	{
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
			QString stringFromFile = ByteArrayRead::ReadSizeAndString(executableFile);
			RelaxString* pushingString = new RelaxString(stringFromFile);
			stack.push(pushingString);

			break;
		}
		case RETURN:
		{
			break;
		}
	}
}
void VirtualMachine::ProccesInstructionCreating(Instruction instruction)
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
			bool isStatic = ByteArrayRead::ReadByte(executableFile);

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
			QByteArray code = ByteArrayRead::ReadSizeAndString(executableFile).toUtf8();

			Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);

			classes.FindClassByName(nameClass)->AddMethod(method);

			break;
		}
	}
}

