#pragma once
#include "Exception.h"

class ExitException : public Exception
{
public:
	ExitException(const QString& message) : Exception(message) {}
};