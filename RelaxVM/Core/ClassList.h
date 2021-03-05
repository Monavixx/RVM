#pragma once
#include "Class.h"

class ClassList : public vector<Class*>
{
public:
	ClassList();
	ClassList(const vector<Class*>& classList);
	ClassList(const ClassList& classList);

	Class* FindClassByName(const String& name);
};

