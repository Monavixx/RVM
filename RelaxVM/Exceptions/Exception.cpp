#include "Exception.h"

Exception::Exception(const std::string& message) : message(message)
{
}

std::string Exception::What() const
{
	return message;
}