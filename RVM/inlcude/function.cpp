#include "function.h"

void Function::call() const
{
	Frame frame(*this);
	while (frame.get_pos() != opcodes.size()) {
		opcodes[frame.get_pos()]->run(&frame);
		frame.inc_pos();
	}
}