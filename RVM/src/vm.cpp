#include "vm.h"
#include <iostream>
void VirtualMachine::parse()
{
	if (int vers = reader.readNum<int>(); vers != version) {
		std::cout << vers;
		throw "bytecode versions do not match";
	}
}

void VirtualMachine::run()
{

}