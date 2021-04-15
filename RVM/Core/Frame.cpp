#include "Frame.h"
#include "../GlobalVariables.h"
#include "Method.h"
#include "FieldObject.h"

Frame::Frame(IMethod* method, Object* objectThis, const VariableList& variableList) : method(method), variables(variableList), objectThis(objectThis)
{
}

Frame::~Frame()
{
	for (auto& item : values)
	{
		delete item;
	}
}

void Frame::CreateVariable(size_t id, Class* dataType)
{
    variables[id] = Variable(nullptr, dataType);
}

OpBase* Frame::Next()
{
    return dynamic_cast<Method*>(method)->GetCode()[index++];
}

bool Frame::IsEnd()
{
    return index >= dynamic_cast<Method*>(method)->GetCode().size();
}