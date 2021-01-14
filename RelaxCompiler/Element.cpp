#include "Element.h"

Element::Element(const QString& _codeElement, const QString& _designation) 
    : codeElement(_codeElement), designation(_designation)
{
}

QString Element::GetCodeElement() const
{
    return this->codeElement;
}

QString Element::GetDesignation() const
{
    return this->designation;
}

void Element::SetCodeElement(const QString& _codeElement)
{
    this->codeElement = _codeElement;
}

void Element::SetDesignation(const QString& _designation)
{
    this->designation = _designation;
}
