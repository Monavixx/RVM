#pragma once

#include "opcode.h"
#include "bytearray_reader.h"

class OpCall : public OpCode
{
public:
	OpCall() : OpCode(OpCode::Type::CALL)
	{
	}

	void parse(const ByteArrayReader& reader) override;

	void run(Frame* frame) override
	{
		func->call(frame);
	}

private:
	IFunction* func;
};