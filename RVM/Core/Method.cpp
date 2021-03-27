#include "Method.h"
#include "../Functions/ExecuteMethod.h"
#include "Frame.h"
#include "FieldObject.h"


Method::Method(const String& name, const String& dataType, const String& declClassName, const vector<Parameter>& parameters,
	const vector<OpBase*>& code, const AccessModifier& accessModifier, bool isStatic)
	: IMethod(name, dataType, declClassName, parameters, accessModifier, isStatic), code(code)
{
}

void Method::CallMethod(Frame* frame)
{
	Frame* newFrame = new Frame(this);

	if (!isStatic)
	{
		Object* objectThis = frame->GetStack().pop()->value.object;
		if (objectThis->GetDataType() != newFrame->GetMethod()->GetDeclClassName())
			Exit("call method: data types do not match");
		newFrame->SetObjectThis(objectThis);
	}

	size_t i = 0;
	for (auto& item : this->GetParameters())
	{
		Value* data = frame->GetStack().pop();
		if(data->valueType==ValueType::OBJECT)
			data->value.object->IncAmountUsers();

		if (Value::GetDataType(data) != item.GetDataType())
			Exit("Error parameters type");

		newFrame->CreateVariable(i, item.GetDataType());
		newFrame->GetVariable(i)->SetValue(data);
		++i;
	}

	GlobalVariables::frameStack.push(newFrame);
	ExecuteMethod();
}
