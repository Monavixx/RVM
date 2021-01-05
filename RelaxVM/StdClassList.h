#pragma once
#include "StdClass.h"

class StdClassList : public QList<StdClass>
{
public:
	StdClass* FindClassByName(const QString& name);
	static StdClassList& GetInstance();

private:
	StdClassList();

	static StdClassList stdClassList;
};

