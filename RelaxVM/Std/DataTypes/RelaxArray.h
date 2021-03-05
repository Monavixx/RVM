#pragma once
#include "Object.h"
#include "../../Functions/Exit.h"
#include "../RelaxNull.h"
#include "RelaxInt32.h"

class RelaxArray : public Object
{
public:
	typedef int asizet;

	RelaxArray(const QString& dataType, asizet size);
	~RelaxArray();
	QString GetDataType() override;
	int* GetArr();
	void SetArr(int* arr);
	void SetByIndex(asizet index, int address);
	int GetByIndex(asizet index);
	RelaxInt32* GetSize() { return new RelaxInt32(size); }


	static void GenerateMetaInfo();
	static inline class StdClass* metaClass = nullptr;

private:
	QString dataType;
	asizet size;
	int* arr;
};

