#pragma once
#include "Class.h"
#include "../Std/Classes/RelaxString.h"
#include "../Std/Classes/RelaxInt32.h"
#include "../Std/Classes/RelaxBool.h"
#include "../Std/Classes/RelaxFloat.h"
#include "../Std/Classes/RelaxArray.h"
#include "../Std/Classes/RelaxRandom.h"
#include "../Std/Classes/RelaxConsole.h"
#include "../Std/Classes/RelaxConverter.h"

class ClassList : public std::unordered_map<String, Class*>
{
public:
	inline ClassList() {}
	ClassList(const std::unordered_map<String, Class*>& classList);
	ClassList(const ClassList& classList);

	void CreateStdClasses();
	inline void AddClass(Class* _class){ (*this)[_class->GetName()] = _class; }
};

