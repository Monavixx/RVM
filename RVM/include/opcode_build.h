#pragma once

#include "opcodes/opcode.h"
#include "opcodes/opcode_call.h"

inline OpCode* opcode_build(OpCode::Type type) noexcept
{
	using OT = OpCode::Type;
	switch (type) {
		case OT::CALL: return new OpCall;
		default: return nullptr;
	}
}