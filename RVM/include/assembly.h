#pragma once

#include "ifunction.h"

class Assembly
{
public:
	Assembly(std::vector<IFunction*>&& functions) : functions(std::move(functions))
	{
	}
	~Assembly()
	{
		for (auto& item : functions) {
			delete item;
		}
	}

	Assembly() noexcept = default;

	IFunction* find_function(std::string_view name, const std::vector<std::string>& parameters)
	{
		auto it = std::ranges::find_if(functions, [&parameters, &name](IFunction* func) {
			return parameters == func->get_parameters() && name == func->get_name();
		});
		if (it == functions.end()) {
			return nullptr;
		}
		return *it;
	}

private:
	std::vector<IFunction*> functions;
};