#pragma once

#include "ifunction.h"
#include "opcodes/opcode.h"
#include "frame.h"

class Function : public IFunction
{
public:
	Function(std::string_view name, std::vector<MetaParameter>&& parameters,
		std::vector<MetaLocal>&& locals, size_t maxstack, std::vector<OpCode*>&& opcodes) noexcept
		: IFunction(name, std::move(parameters), std::move(locals), maxstack), opcodes{std::move(opcodes)}
	{
	}

	~Function()
	{
		for (auto& item : opcodes) {
			delete item;
		}
	}

	void call(Frame* frame) const override;

private:
	std::vector<OpCode*> opcodes;
};