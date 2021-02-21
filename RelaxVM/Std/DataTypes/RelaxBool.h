#pragma once
#include "Object.h"

class RelaxBool : public Object
{
public:
	RelaxBool(bool data);
	QString GetDataType() override;
	bool GetData();
	void SetData(bool data);

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;
private:
	bool data;
};

