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
#include <unordered_map>

class StdClassList : public std::unordered_map<String, StdClass*>
{
public:
	static StdClassList* GetInstance();

private:
	StdClassList();

	void AddClass(StdClass* stdClass);

	static inline StdClassList* stdClassList;
};

