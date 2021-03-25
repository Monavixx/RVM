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
	inline int GetData()
	{
		return data;
	}
	inline void SetData(int data)
	{
		this->data = data;
	}

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	int data;
};

