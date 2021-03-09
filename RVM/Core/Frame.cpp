#include "Frame.h"
#include "../GlobalVariables.h"
#include "Method.h"

Frame::Frame(IMethod* method, const VariableList& variableList) : method(method), variables(variableList)
{
}

Variable* Frame::GetVariable(size_t id)
{
    return &variables[id];
}

IMethod* Frame::GetMethod() const
{
    return method;
}

VariableList Frame::GetVariableList() const
{
    return variables;
}

void Frame::SetMethod(IMethod* method)
{
    this->method = method;
}

void Frame::SetVariableList(const VariableList& variables)
{
    this->variables = variables;
}

void Frame::CreateVariable(size_t id, const String& dataType)
{
    Object* data = new RelaxNull;
    data->IncAmountUsers();
    variables[id] = Variable(GlobalVariables::heap.push_back(data), dataType);
}

Stack& Frame::GetStack()
{
    return stack;
}

OpBase* Frame::Next()
{
    return dynamic_cast<Method*>(method)->GetCode()[index++];
}

bool Frame::IsEnd()
{
    return index >= dynamic_cast<Method*>(method)->GetCode().size();
}

void Frame::SetIndex(size_t index)
{
    this->index = index;
}
