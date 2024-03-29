﻿#include "vm.h"
#include "function.h"


void VirtualMachine::parse()
{
	if (const auto vers = reader.readNum<int>(); vers != version) {
		throw bytecode_exception("bytecode versions do not match");
	}
	assembly.name = reader.readString();
	assembly.version = reader.readString();
	
	const size_t amountIncludeAssembly = reader.readNum<size_t>();
	includeAssebly.reserve(amountIncludeAssembly);

	for (size_t i = 0; i < amountIncludeAssembly; ++i) {
		includeAssebly.push_back(reader.readString());
	}

	const size_t amountFunctions = reader.readNum<size_t>();
	for (size_t i = 0; i < amountFunctions; ++i) {
		std::string name = reader.readString();

		size_t amountParameters = reader.readNum<size_t>();
		std::vector<IFunction::MetaParameter> parameters;
		parameters.reserve(amountParameters);
		for (size_t j = 0; j < amountParameters; ++j) {
			std::string dataType{ reader.readString() };
			const size_t id = reader.readNum<size_t>();
			parameters.emplace_back(std::move(dataType), id);
		}

		size_t amountLocals = reader.readNum<size_t>();
		std::vector<IFunction::MetaLocal> locals;
		locals.reserve(amountLocals);
		for (size_t j = 0; j < amountLocals; ++j) {
			std::string dataType{ reader.readString() };
			const size_t id = reader.readNum<size_t>();
			locals.emplace_back(std::move(dataType), id);
		}

		size_t maxstack = reader.readNum<size_t>();
		
		size_t amountOpcodes = reader.readNum<size_t>();
		std::vector<OpCode*> opcodes;
		opcodes.reserve(amountOpcodes);
		for (size_t j = 0; j < amountOpcodes; ++j) {
			OpCode::Type type = static_cast<OpCode::Type>(reader.readNum<byte>());

			OpCode* oc = opcode_build(type);
			oc->parse(reader);
			opcodes.push_back(oc);
		}

		functions.push_back(new Function(name, std::move(parameters), std::move(locals), maxstack, std::move(opcodes)));
	}
}

void VirtualMachine::run()
{
	auto mainFunc = std::ranges::find_if(functions, [](IFunction* func) {return func->get_name() == "main" && func->get_parameters().size() == 0; });
	if (mainFunc == functions.end()) {
		throw "main not found";
	}
	(*mainFunc)->call(nullptr);
}