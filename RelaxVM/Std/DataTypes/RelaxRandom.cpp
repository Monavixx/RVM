#include "RelaxRandom.h"
#include <random>

String RelaxRandom::GetDataType()
{
    return "Relax.Random";
}

RelaxInt32* RelaxRandom::GenerateInt32()
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist;
    return new RelaxInt32(uniform_dist(e1));
}

RelaxInt32* RelaxRandom::GenerateInt32(int min, int max)
{
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(min, max);
	return new RelaxInt32(uniform_dist(e1));
}

void RelaxRandom::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Random", {
		// GenerateInt32
		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {}, [&](Stack& stack) -> Object*
		{
			return RelaxRandom::GenerateInt32();
		},AccessModifier::PUBLIC, true),

		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {Parameter("Relax.Int32"), Parameter("Relax.Int32")}, [&](Stack& stack)->Object*
		{
			RelaxInt32* min = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* max = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxRandom::GenerateInt32(min->GetData(), max->GetData());
		},AccessModifier::PUBLIC, true)
	});
}

