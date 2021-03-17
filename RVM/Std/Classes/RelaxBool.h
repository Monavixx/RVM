#pragma once
#include "Object.h"

class RelaxBool : public Object
{
public:
	RelaxBool(bool data);
	constexpr String GetDataType() override
	{
		return "Relax.Bool"_ss;
	}
	bool GetData();
	void SetData(bool data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	bool data;
};

