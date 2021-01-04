#pragma once
#include "Object.h"

class Variable
{
public:
	Variable(int id, Object* data = nullptr);
	~Variable();

	int GetId() const;
	Object* GetData() const;

	void SetId(int id);
	void SetData(Object* data);

private:
	Object* data;
	int id;
};

