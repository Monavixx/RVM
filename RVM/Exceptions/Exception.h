#pragma once
#include "../Libs/String.h"

class Exception
{
public:
	Exception(const String& message);

	String What() const;

protected:
	String message;
};