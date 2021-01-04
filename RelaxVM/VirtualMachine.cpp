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
	while (bufferMainMethodCode.bytesAvailable() > 0)
	{
		Instruction instruction = static_cast<Instruction>(ByteArrayRead::ReadByte(executableFile));
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

			//TODO: create constructors
			Variable* variable = new Variable(variableId);
			heap.push_back(variable);

			break;
		}
		case CALL_METHOD:
		{
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
			int variableId = ByteArrayRead::ReadInt(device);

			QString stringFromFile = ByteArrayRead::ReadSizeAndString(device);
			RelaxString* pushingString = new RelaxString(stringFromFile);
			Variable* pushingVariable = new Variable(variableId, pushingString);

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
			mainClass = new Class(nameMainClass);
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
			QByteArray code = ByteArrayRead::ReadSizeAndString(device).toUtf8();

			Method method(name, dataType, nameClass, parameters, code, accessModifier, isStatic);

			classes.FindClassByName(nameClass)->AddMethod(method);

			break;
		}
		
	}
}

