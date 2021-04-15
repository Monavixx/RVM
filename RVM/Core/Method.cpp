#include "Method.h"
#include "../Functions/ExecuteMethod.h"
#include "Frame.h"
#include "FieldObject.h"


Method::Method(const String& name, const String& dataType, const vector<Parameter>& parameters,
	const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: IMethod(name, dataType, parameters, accessModifier, isStatic), code(code)
{
}

void Method::CallMethod(Frame* frame)
{
	Frame* newFrame = new Frame(this);

	if (!isStatic)
	{
		Object* objectThis = GlobalVariables::heap[get<size_t>(frame->GetStack().pop()->value)];
		objectThis->IncAmountUsers();
		newFrame->SetObjectThis(objectThis);
	}

	size_t i = 0;
	for (auto& item : this->GetParameters())
	{
		Value* data = frame->GetStack().pop();
		if(data->valueType==ValueType::OBJECT)
			GlobalVariables::heap[get<size_t>(data->value)]->IncAmountUsers();

		newFrame->CreateVariable(i, item.GetDataType());
		newFrame->GetVariable(i)->SetValue(data);
		++i;
	}

	GlobalVariables::frameStack.push(newFrame);
	ExecuteMethod();
}
