#include "RelaxRandom.h"
#include <random>
#include "../../Core/Class.h"
#include "../../Core/StdMethod.h"

RelaxInt32* RelaxRandom::GenerateInt32()
{
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist;
    return new RelaxInt32(uniform_dist(e1));
}

RelaxInt32* RelaxRandom::GenerateInt32(RelaxInt32* min, RelaxInt32* max)
{
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(min->GetData(), max->GetData());
	return new RelaxInt32(uniform_dist(e1));
}

void RelaxRandom::GenerateMetaInfo()
{
	metaClass = new Class("Relax.Random", {
		// GenerateInt32
		new StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {}, [&](Stack& stack) -> Object*
		{
			return RelaxRandom::GenerateInt32();
		},AccessModifier::PUBLIC, true),

		new StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {Parameter("Relax.Int32"), Parameter("Relax.Int32")}, [&](Stack& stack)->Object*
		{
			RelaxInt32* min = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* max = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxRandom::GenerateInt32(min, max);
		},AccessModifier::PUBLIC, true)
	});
}

