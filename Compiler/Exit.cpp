#include "Exit.h"

void Exit(const QString& message)
{
	throw ExitException(message);
}