#include "Exit.h"

void Exit(const std::string& message)
{
	throw ExitException(message);
}