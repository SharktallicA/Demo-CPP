#pragma once

/*
	Mersenne Twister 19937 64-Bit pseudorandom number generator
	Khalid Ali 2018
	http://khalidali.co.uk/
*/

#include <random>

int gen(int min, int max)
{
	//purpose: Mersenne Twister 19937 RNG (integer version)
	//parameters: (min) minimum bound for range, (max) maximum bound for range

	int result;
	random_device randG;
	mt19937_64 mersenne(randG());
	uniform_int_distribution<int> distInt(min, max);
	result = distInt(mersenne);
	return result;
}

float gen(float min, float max)
{
	//purpose: Mersenne Twister 19937 RNG (float version)
	//parameters: (min) minimum bound for range, (max) maximum bound for range

	float result;
	random_device randG;
	mt19937_64 mersenne(randG());
	uniform_real_distribution<float> distFlt(min, max);
	result = distFlt(mersenne);
	return result;
}