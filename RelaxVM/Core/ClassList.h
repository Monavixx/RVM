#pragma once
#include "Class.h"
#include "../Std/DataTypes/RelaxString.h"
#include "../Std/DataTypes/RelaxInt32.h"
#include "../Std/DataTypes/RelaxBool.h"
#include "../Std/DataTypes/RelaxFloat.h"
#include "../Std/DataTypes/RelaxArray.h"
#include "../Std/DataTypes/RelaxRandom.h"
#include "../Std/DataTypes/RelaxConsole.h"
#include "../Std/DataTypes/RelaxConverter.h"

class ClassList : public std::unordered_map<String, Class*>
{
public:
	inline ClassList() {}
	ClassList(const std::unordered_map<String, Class*>& classList);
	ClassList(const ClassList& classList);

	void CreateStdClasses();
	inline void AddClass(Class* _class){ (*this)[_class->GetName()] = _class; }
};

