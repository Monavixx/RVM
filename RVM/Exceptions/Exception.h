#pragma once
#include <string>

class Exception
{
public:
	Exception(const std::string& message);

	std::string What() const;

protected:
	std::string message;
};