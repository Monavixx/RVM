#pragma once
#include "Object.h"
#include "RelaxFloat.h"
#include "RelaxBool.h"

class RelaxInt32 : public Object
{
public:
	RelaxInt32(int data);
	QString GetDataType() override;
	int GetData();
	void SetData(int data);

	RelaxBool* operator==(RelaxInt32* other);
	RelaxBool* operator==(RelaxFloat* other);

	RelaxInt32* operator+(RelaxInt32* other);
	RelaxInt32* operator-(RelaxInt32* other);
	RelaxInt32* operator*(RelaxInt32* other);
	RelaxInt32* operator/(RelaxInt32* other);

	RelaxInt32* operator+(RelaxFloat* other);
	RelaxInt32* operator-(RelaxFloat* other);
	RelaxInt32* operator*(RelaxFloat* other);
	RelaxInt32* operator/(RelaxFloat* other);
private:
	int data;
};

