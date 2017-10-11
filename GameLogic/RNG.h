#pragma once

#include <random>
#include <ctime>

class RNG
{
public:
	RNG();
	~RNG();

	static void init();

	static int RNDintRNG(int low, int high);

	static float RNGfloatRNG(float low, float high);

	static std::minstd_rand gen;



};

