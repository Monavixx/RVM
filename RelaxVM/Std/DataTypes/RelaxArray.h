#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"
#include "../RelaxNull.h"

class RelaxArray : public Object
{
public:
	RelaxArray(const QString& dataType, int size);
	~RelaxArray();
	QString GetDataType() override;
	int* GetArr();
	void SetArr(int* arr);
	void SetByIndex(int index, int address);
	int GetByIndex(int index);

	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;

private:
	QString dataType;
	int size;
	int* arr;
};

