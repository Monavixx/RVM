#pragma once

#include "opcode.h"

class OpCall : public OpCode
{
public:
	OpCall() : OpCode(OpCode::Type::CALL)
	{
	}

	void parse(const std::vector<unsigned char>& data) override
	{

	}
	void run(Frame* frame) override
	{

	}

private:
};