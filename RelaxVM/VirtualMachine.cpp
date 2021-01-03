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
			QString data = ByteArrayRead::ReadSizeAndString(executableFile);
			String* str = new String(data);
			stack.push(str);
			
			break;
		}
		case RETURN:
		{
			break;
		}
	}
}


/*
	Relax-код:


//test.re
from Relax import *;
namespace TestNamespace
{
	class Test
	{
		publ stat void Main()
		{
			Console.Write("hello world");
		}
	}
}



	Читаемый байт-код:

create_main_class NameMainClass;
create_method public static void NameMainClass.Main():
	push_str "Hello world";
	call_method static void Relax.Console.Write(Relax.String);
	end;


		Продакшен:

<byte 1><int 13>NameMainClass
<byte 4><byte 1><byte 1><int 4>void<int 13>NameMainClass<int 4>Main<int 0>
	<byte 7><int 11>Hello world
	<byte 5><byte 1><int 4>void<int 13>Relax.Console<int 5>Print<int 1><int 11>Relax.String
	<byte 9>
*/