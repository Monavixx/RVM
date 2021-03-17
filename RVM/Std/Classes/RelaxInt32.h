#pragma once
#include "Object.h"
#include "RelaxBool.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

class RelaxInt32 : public Object
{
public:
	RelaxInt32(int data);
	constexpr String GetDataType() override
	{
		return "Relax.Int32"_ss;
	}
	int GetData();
	void SetData(int data);
	
	RelaxBool* operator==(RelaxInt32* other);

	RelaxInt32* operator+(RelaxInt32* other);
	RelaxInt32* operator-(RelaxInt32* other);
	RelaxInt32* operator*(RelaxInt32* other);
	RelaxInt32* operator/(RelaxInt32* other);

	static RelaxInt32* cast(class RelaxFloat* data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	int data;
};

