#pragma once

#include <string>

class Exception
{
public:
	Exception(const std::string& message) : message(message)
	{
	}

	const std::string& What() const
	{
		return message;
	}

protected:
	std::string message;
};