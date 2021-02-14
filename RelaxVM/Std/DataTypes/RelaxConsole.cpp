#include "RelaxConsole.h"

QString RelaxConsole::GetDataType()
{
    return "Relax.Console";
}

Object* RelaxConsole::Write(RelaxString* data)
{
	if (Args::args.contains("-iostd"))
		std::cout << data->GetData().toStdString();
	else
		qout << data->GetData();
	return nullptr;
}

Object* RelaxConsole::Write(RelaxInt32* data)
{
	if (Args::args.contains("-iostd"))
		std::cout << data->GetData();
	else
		qout << QString::number(data->GetData());
	return nullptr;
}

Object* RelaxConsole::Write(RelaxFloat* data)
{
	if (Args::args.contains("-iostd"))
		std::cout << data->GetData();
	else
		qout << QString::number(data->GetData());
	return nullptr;
}

Object* RelaxConsole::Write(RelaxBool* data)
{
	if (Args::args.contains("-iostd"))
		std::cout << (data->GetData() ? "true" : "false");
	else
		qout << (data->GetData() ? "true" : "false");
	return nullptr;
}

RelaxString* RelaxConsole::Read()
{
	return new RelaxString(qin.readLine());
}
