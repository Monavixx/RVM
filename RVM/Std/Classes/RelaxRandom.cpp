#include "RelaxRandom.h"
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

int RelaxRandom::GenerateInt32()
{
	static std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist;
    return uniform_dist(e1);
}

int RelaxRandom::GenerateInt32(int min, int max)
{
	static std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(min, max);
	return uniform_dist(e1);
}

void RelaxRandom::GenerateMetaClass()
{
	metaClass = new Class("Random", true);
}

void RelaxRandom::GenerateMetaMethods()
{
	metaClass->AddMethods({
		// GenerateInt32
		new StdMethod("GenerateInt32", "Relax.Int32", {}, [&](Stack& stack) -> Value*
		{
			return new Value(ValueType::INT32,  UValue(RelaxRandom::GenerateInt32()));
		},AccessModifier::PUBLIC, true),

		new StdMethod("GenerateInt32", "Relax.Int32", {Parameter("Relax", "Int32"), Parameter("Relax", "Int32")},[&](Stack& stack)->Value*
		{
			return new Value(ValueType::INT32,  UValue(RelaxRandom::GenerateInt32(get<int>(stack.pop()->value), get<int>(stack.pop()->value))));
		},AccessModifier::PUBLIC, true)
	});
}

