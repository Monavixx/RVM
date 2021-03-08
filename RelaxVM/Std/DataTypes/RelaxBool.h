#pragma once
#include "Object.h"

class RelaxBool : public Object
{
public:
	RelaxBool(bool data);
	inline String GetDataType() override
	{
		static String dataType = "Relax.Bool";
		return dataType;
	}
	bool GetData();
	void SetData(bool data);

	static void GenerateMetaInfo();
	static inline class Class* metaClass = nullptr;
private:
	bool data;
};

