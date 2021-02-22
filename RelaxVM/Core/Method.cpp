#include "Method.h"
#include "../Functions/ExecuteMethod.h"
#include "Frame.h"

Method::Method(const MethodSignature& signature, const QVector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
}

Method::Method(const QString& name, const QString& dataType, const QString& nameClass, const QVector<Parameter>& parameters,
	const QVector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(name, dataType, nameClass, parameters), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
}

bool Method::IsStatic() const
{
	return isStatic;
}

AccessModifier Method::GetAccessModifier() const
{
	return accessModifier;
}

QVector<OpBase*>& Method::GetCode()
{
	return (this->code);
}

void Method::SetIsStatic(bool isStatic)
{
	this->isStatic = isStatic;
}

void Method::SetAccessModifier(const AccessModifier& accessModifier)
{
	this->accessModifier = accessModifier;
}

void Method::SetCode(const QVector<OpBase*>& code)
{
	this->code = code;
}

bool Method::operator==(Method& other) const
{
	if (!MethodSignature::operator==(dynamic_cast<const MethodSignature&>(other))) return false;
	if (isStatic != other.IsStatic()) return false;
	if (accessModifier != other.GetAccessModifier()) return false;
	return true;
}

void Method::CallMethod(Frame* frame)
{
	Frame* newFrame = new Frame(this);

	int i = 0;
	for (auto& item : this->GetParameters())
	{
		Object* data = frame->GetStack().pop();
		if (data->GetDataType() != item.GetDataType())
			Exit("Error parameters type");
		newFrame->CreateVariable(i, item.GetDataType());
		newFrame->GetVariable(i)->SetAddress(data->GetAddress());
		++i;
	}

	GlobalVariables::frameStack.push(newFrame);
	ExecuteMethod();
}
