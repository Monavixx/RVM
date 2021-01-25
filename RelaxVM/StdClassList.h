#pragma once
#include "StdClass.h"
#include "RelaxString.h"
#include "RelaxInt32.h"
#include "RelaxBool.h"
#include "ConsoleTextStream.h"

class StdClassList : public QList<StdClass>
{
public:
	StdClass* FindClassByName(const QString& name);
	static StdClassList* GetInstance();

private:
	StdClassList();

	static inline StdClassList* stdClassList;
};

