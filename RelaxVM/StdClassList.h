#pragma once
#include "StdClass.h"
#include "RelaxString.h"
#include "RelaxInt32.h"
#include "RelaxBool.h"
#include "RelaxFloat.h"
#include "RelaxArray.h"
#include "ConsoleTextStream.h"
#include "Args.h"

class StdClassList : public QList<StdClass>
{
public:
	StdClass* FindClassByName(const QString& name);
	static StdClassList* GetInstance();

private:
	StdClassList();

	static inline StdClassList* stdClassList;
};

