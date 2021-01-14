#pragma once
#include <QtCore>

class Element
{
public:
	Element(const QString& _codeElement, const QString& _designation);
	QString GetCodeElement() const;
	QString GetDesignation() const;

	void SetCodeElement(const QString& _codeElement);
	void SetDesignation(const QString& _designation);
private:
	QString codeElement;
	QString designation;
};

