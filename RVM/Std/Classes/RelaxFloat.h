#pragma once
#include "Object.h"
#include "RelaxBool.h"

class RelaxFloat : public Object
{
public:
	RelaxFloat(float data);
	inline String GetDataType() override
	{
		static String dataType = "Relax.Float";
		return dataType;
	}
	float GetData();
	void SetData(float data);

	RelaxFloat* operator+(RelaxFloat* other);
	RelaxFloat* operator-(RelaxFloat* other);
	RelaxFloat* operator*(RelaxFloat* other);
	RelaxFloat* operator/(RelaxFloat* other);
	RelaxBool* operator==(RelaxFloat* other);

	static RelaxFloat* cast(class RelaxInt32* data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	float data;
};

