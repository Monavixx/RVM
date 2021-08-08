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

	virtual void call(class Frame* frame) const = 0;

public:

	class MetaParameter
	{
	public:
		MetaParameter(std::string_view dataType, size_t id) : dataType{ dataType }, id{ id }
		{
		}

		auto operator<=>(const MetaParameter& mp) const { return dataType <=> mp.dataType; }

		std::string& get_data_type() noexcept { return dataType; }
	private:
		size_t id;
		std::string dataType;


		friend inline bool operator==(const std::vector<std::string>&, const std::vector<IFunction::MetaParameter>&) noexcept;
	};

	class MetaLocal
	{
	public:
		MetaLocal(std::string_view dataType, size_t id) : dataType{ dataType }, id{ id }
		{
		}

		auto operator<=>(const MetaLocal& mp) const { return dataType <=> mp.dataType; }

		std::string& get_data_type() noexcept { return dataType; }
	private:
		size_t id;
		std::string dataType;


		friend inline bool operator==(const std::vector<std::string>&, const std::vector<IFunction::MetaLocal>&) noexcept;
	};

protected:
	std::string name;
	std::vector<MetaParameter> parameters;
	std::vector<MetaLocal> locals;
	size_t maxstack;
};

inline bool operator==(const std::vector<std::string>& dataTypes, const std::vector<IFunction::MetaParameter>& parameters) noexcept
{
	if (dataTypes.size() != parameters.size()) {
		return false;
	}
	for (size_t i = 0; i < dataTypes.size(); ++i) {
		if (dataTypes[i] != parameters[i].dataType) {
			return false;
		}
	}
	return true;
}
inline bool operator==(const std::vector<std::string>& dataTypes, const std::vector<IFunction::MetaLocal>& locals) noexcept
{
	if (dataTypes.size() != locals.size()) {
		return false;
	}
	for (size_t i = 0; i < dataTypes.size(); ++i) {
		if (dataTypes[i] != locals[i].dataType) {
			return false;
		}
	}
	return true;
}