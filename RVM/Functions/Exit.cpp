#include "Exit.h"
#include "../Libs/String.h"

void Exit(const std::string& message)
{
	throw ExitException(message);
}

