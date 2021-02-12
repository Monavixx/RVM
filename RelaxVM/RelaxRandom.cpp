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
