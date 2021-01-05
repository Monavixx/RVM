#pragma once
#include "StdClass.h"
#include "RelaxString.h"
#include "Int32.h"
#include "../Libs/ConsoleTextStream.h"

class StdClassList : public QList<StdClass>
{
public:
	StdClass* FindClassByName(const QString& name);
	static StdClassList* GetInstance();

private:
	StdClassList();

	static inline StdClassList* stdClassList;
};

