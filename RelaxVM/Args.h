#pragma once
#include "Libs/String.h"
#include <vector>

struct Args
{
	static inline std::vector<String> args = {};

	static inline bool contains(const String& arg)
	{
		return std::find(args.begin(), args.end(), arg) != args.end();
	}
};