#include "Method.h"
#include "../Functions/ExecuteMethod.h"
#include "Frame.h"

Method::Method(const MethodSignature& signature, const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(signature), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
}

Method::Method(const String& name, const String& dataType, const String& nameClass, const vector<Parameter>& parameters,
	const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: MethodSignature(name, dataType, nameClass, parameters), accessModifier(accessModifier), isStatic(isStatic), code(code)
{
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

	size_t i = 0;
	for (auto& item : this->GetParameters())
	{
		Object* data = frame->GetStack().pop();
		data->IncAmountUsers();
		if (data->GetDataType() != item.GetDataType())
			Exit("Error parameters type");
		newFrame->CreateVariable(i, item.GetDataType());
		newFrame->GetVariable(i)->SetAddress(data->GetAddress());
		++i;
	}

	GlobalVariables::frameStack.push(newFrame);
	ExecuteMethod();
}
