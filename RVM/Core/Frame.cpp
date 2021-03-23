#include "Frame.h"
#include "../GlobalVariables.h"
#include "Method.h"

Frame::Frame(IMethod* method, size_t objectThis, const VariableList& variableList) : method(method), variables(variableList), objectThis(objectThis)
{
}

void Frame::CreateVariable(size_t id, const String& dataType)
{
    Object* data = new RelaxNull;
    data->IncAmountUsers();
    variables[id] = Variable(GlobalVariables::heap.push_back(data), dataType);
}

OpBase* Frame::Next()
{
    return dynamic_cast<Method*>(method)->GetCode()[index++];
}

bool Frame::IsEnd()
{
    return index >= dynamic_cast<Method*>(method)->GetCode().size();
}