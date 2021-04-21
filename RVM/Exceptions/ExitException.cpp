#include "ExitException.h"
#include "../Libs/String.h"


ExitException::ExitException(const String& message) : Exception(message) {}