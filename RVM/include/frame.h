#pragma once

#include <string>
#include "ifunction.h"

class Frame
{
public:
	Frame(const IFunction& func) : func(func)
	{
	}


	size_t get_pos() const noexcept { return pos; }
	void set_pos(size_t pos) noexcept { this->pos = pos; }
	void inc_pos() noexcept { ++pos; }
private:
	const IFunction& func;
	size_t pos = 0;
};