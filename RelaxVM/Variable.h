#pragma once
#include "Object.h"

class Variable
{
public:
	Variable(Object* data = nullptr);
	~Variable();

	Object* GetData() const;

	void SetData(Object* data);

private:
	Object* data;
};

