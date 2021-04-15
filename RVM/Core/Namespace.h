#pragma once
#include "../Libs/String.h"
#include "ClassList.h"

class Namespace
{
public:
	inline Namespace(const String& name, const ClassList& classes = {}) : name(name), classes(classes) {}
	inline String GetName() const { return name; }
	inline String& GetName() { return name; }
	inline ClassList GetClasses() const { return classes; }
	inline ClassList& GetClasses() { return classes; }
	inline void SetClasses(const ClassList& classes) { this->classes = classes; }
	inline void SetName(const String& name) { this->name = name; }
	inline void AddClass(Class* _class) { _class->SetNamespace(this); classes.AddClass(_class); }
	inline Class* GetClass(const String& name) { return classes[name]; }
private:
	String name;
	ClassList classes;
};