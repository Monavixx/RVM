#include "function.h"

void Function::call(Frame* frame) const
{
	Frame newFrame(*this);
	while (newFrame.get_pos() != opcodes.size()) {
		opcodes[newFrame.get_pos()]->run(&newFrame);
		newFrame.inc_pos();
	}
}