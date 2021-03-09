#include "Method.h"
#include "../Functions/ExecuteMethod.h"
#include "Frame.h"


Method::Method(const String& name, const String& dataType, const String& declClassName, const vector<Parameter>& parameters,
	const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: IMethod(name, dataType, declClassName, parameters, accessModifier, isStatic), code(code)
{
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
