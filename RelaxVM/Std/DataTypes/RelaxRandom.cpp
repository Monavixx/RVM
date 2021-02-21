#include "RelaxRandom.h"

QString RelaxRandom::GetDataType()
{
    return "Relax.Random";
}

RelaxInt32* RelaxRandom::GenerateInt32()
{
    return new RelaxInt32(QRandomGenerator::global()->generate());
}

RelaxInt32* RelaxRandom::GenerateInt32(int min, int max)
{
    return new RelaxInt32(QRandomGenerator::global()->generate() % (max - min) + min);
}

void RelaxRandom::GenerateMetaInfo()
{
	metaClass = new StdClass("Relax.Random", {
		// GenerateInt32
		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", {}, [&](Stack& stack) -> Object*
		{
			return RelaxRandom::GenerateInt32();
		},AccessModifier::PUBLIC, true),

		StdMethod("GenerateInt32", "Relax.Int32", "Relax.Random", QVector<Parameter>{Parameter("Relax.Int32"), Parameter("Relax.Int32")}, [&](Stack& stack)->Object*
		{
			RelaxInt32* min = dynamic_cast<RelaxInt32*>(stack.pop());
			RelaxInt32* max = dynamic_cast<RelaxInt32*>(stack.pop());
			return RelaxRandom::GenerateInt32(min->GetData(), max->GetData());
		},AccessModifier::PUBLIC, true)
	});
}

