#include "Frame.h"

Frame::Frame(Method* method, const VariableList& variableList) : method(method), variables(variableList)
{
}

Variable* Frame::FindVariableById(int id)
{
    return variables.FindVariableById(id);
}

Method* Frame::GetMethod() const
{
    return method;
}

VariableList Frame::GetVariableList() const
{
    return variables;
}

QMap<QString, qint64> Frame::GetTags() const
{
    return tags;
}

void Frame::SetMethod(Method* method)
{
    this->method = method;
}

void Frame::SetVariableList(const VariableList& variables)
{
    this->variables = variables;
}

void Frame::CreateVariable(int id)
{
    variables.push_back(Variable(id));
}

int Frame::GetIndexTagByTag(const QString& tag) const
{
    return tags[tag];
}

void Frame::AddTag(const QString& tag, qint64 index)
{
    tags[tag] = index;
}
