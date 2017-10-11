#include "RNG.h"

std::minstd_rand RNG::gen;

RNG::RNG()
{
}


RNG::~RNG()
{
}

void RNG::init()
{
	gen.seed(std::time(nullptr));
}

int RNG::RNDintRNG(int low, int high)
{
	std::uniform_int_distribution<int> dist(low, high);
	return dist(gen);
}

float RNG::RNGfloatRNG(float low, float high)
{
	std::uniform_real_distribution<float> dist(low, high);
	return dist(gen);
}
