#include "Exception.h"

Exception::Exception(const String& message) : message(message)
{
}

String Exception::What() const
{
	return message;
}