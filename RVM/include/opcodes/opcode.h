#pragma once

#include <string>
#include <vector>
#include "frame.h"

class OpCode
{
public:
	enum class Type : unsigned char
	{
		PSTR = 1,
		CALL
	};

public:
	OpCode(Type type) : type{type}
	{
	}

	virtual void parse(const std::vector<unsigned char>& data) = 0;
	virtual void run(Frame* frame) = 0;

	Type get_type() const noexcept { return type; }

private:
	Type type;
};