#pragma once
#include "Object.h"
#include "RelaxBool.h"

class RelaxString : public Object
{
public:
	RelaxString(const QString& data);
	QString GetDataType() override;
	QString GetData();
	void SetData(const QString& data);

	RelaxString* Concat(RelaxString* other);

	RelaxString* operator+(RelaxString* other);
	RelaxBool* operator==(RelaxString* other);
	
	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;

private:
	QString data;
};

