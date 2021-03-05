#pragma once
#include "Exception.h"

class ExitException : public Exception
{
public:
	ExitException(const std::string& message) : Exception(message) {}
};