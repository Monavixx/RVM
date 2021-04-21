#include "Exit.h"
#include "../Libs/String.h"


void ExitFunc(const String& message)
{
	throw ExitException(message);
}

