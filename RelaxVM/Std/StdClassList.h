#pragma once
#include "StdClass.h"
#include "DataTypes/RelaxString.h"
#include "DataTypes/RelaxInt32.h"
#include "DataTypes/RelaxBool.h"
#include "DataTypes/RelaxFloat.h"
#include "DataTypes/RelaxArray.h"
#include "DataTypes/RelaxRandom.h"
#include "DataTypes/RelaxConsole.h"
#include "DataTypes/RelaxConverter.h"
#include "../Libs/ConsoleTextStream.h"
#include "../Args.h"

class StdClassList : public QHash<QString, StdClass*>
{
public:
	static StdClassList* GetInstance();

private:
	StdClassList();

	static inline StdClassList* stdClassList;
};

