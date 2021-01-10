#pragma once
#include <QtCore>
#include "Method.h"
#include "VariableList.h"

class Frame
{
public:
	Frame(Method* method = nullptr, const VariableList& variableList = {});

	Variable* FindVariableById(int id);

	Method* GetMethod() const;
	VariableList GetVariableList() const;
	QMap<QString, qint64> GetTags() const;

	void SetMethod(Method* method);
	void SetVariableList(const VariableList& variables);
	void CreateVariable(int id);

	int GetIndexTagByTag(const QString& tag) const;

	void AddTag(const QString& tag, qint64 index);

private:
	QMap<QString, qint64> tags;
	VariableList variables;
	Method* method;
};

