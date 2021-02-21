#pragma once
#include "Object.h"
#include "RelaxBool.h"
#include "../StdClass.h"

class RelaxInt32 : public Object
{
public:
	RelaxInt32(int data);
	QString GetDataType() override;
	int GetData();
	void SetData(int data);
	
	RelaxBool* operator==(RelaxInt32* other);

	RelaxInt32* operator+(RelaxInt32* other);
	RelaxInt32* operator-(RelaxInt32* other);
	RelaxInt32* operator*(RelaxInt32* other);
	RelaxInt32* operator/(RelaxInt32* other);

	static RelaxInt32* cast(class RelaxFloat* data);

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
private:
	int data;
};

