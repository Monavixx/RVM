#pragma once

#include <string>
#include <vector>


class IFunction
{
public:
	class MetaParameter;
	class MetaLocal;
	
	IFunction(std::string_view name, std::vector<MetaParameter>&& parameters, std::vector<MetaLocal>&& locals, size_t maxstack) noexcept
		: name{ name }, parameters{ std::move(parameters) }, locals{ locals }, maxstack{ maxstack }
	{
	}

	std::string& get_name() noexcept { return name; }
	std::vector<MetaParameter>& get_parameters() noexcept { return parameters; }
	std::vector<MetaLocal>& get_locals() noexcept { return locals; }
	size_t get_maxstack() const noexcept { return maxstack; }

	virtual void call() const = 0;

public:

	class MetaParameter
	{
	public:
		MetaParameter(std::string_view dataType, size_t id) : dataType{ dataType }, id{ id }
		{
		}
	private:
		size_t id;
		std::string dataType;
	};

	class MetaLocal
	{
	public:
		MetaLocal(std::string_view dataType, size_t id) : dataType{ dataType }, id{ id }
		{
		}
	private:
		size_t id;
		std::string dataType;
	};

protected:
	std::string name;
	std::vector<MetaParameter> parameters;
	std::vector<MetaLocal> locals;
	size_t maxstack;
};