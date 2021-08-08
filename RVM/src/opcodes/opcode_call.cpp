#include "opcodes/opcode_call.h"
#include "vm.h"

void OpCall::parse(const ByteArrayReader& reader)
{
	std::string assemblyName = reader.readString();
	std::string functionName = reader.readString();

	size_t amountParameters = reader.readNum<size_t>();
	std::vector<std::string> parameters;
	parameters.reserve(amountParameters);
	for (size_t i = 0; i < amountParameters; ++i) {
		parameters.push_back(reader.readString());
	}

	func = VirtualMachine::get_instance().get_function(assemblyName, functionName, parameters);
}