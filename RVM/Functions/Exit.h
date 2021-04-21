#pragma once
#include "../Exceptions/ExitException.h"

#ifdef _DEBUG
#define Exit(data, code) (ExitFunc(data))
#else
#define Exit(data, code) exit(code);
#endif

void ExitFunc(const class String& message);