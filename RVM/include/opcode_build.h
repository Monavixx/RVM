#pragma once

#include "opcodes/opcode.h"

inline OpCode* opcode_build(OpCode::Type type) noexcept
{
	using OT = OpCode::Type;
	OpCode* oc;
	switch (type) {
	case OT::CALL: 
	}
}