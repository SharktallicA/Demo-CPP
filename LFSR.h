#pragma once

/*
	Linear-feedback shift register based pseudorandom number generator
	Khalid Ali 2018
	http://khalidali.co.uk/
*/

class LFSR
{
	//purpose: P-RNG based on linear-feedback shift register
	//based on: https://en.wikipedia.org/wiki/Linear_feedback_shift_register

private:
	unsigned short lfsr = 0xACE1u; //state
	unsigned bit;
public:
	LFSR() {};
	int gen(int min, int max)
	{
		//params: (min) minimum desired number, (max) maximum desired number
		do
		{
			bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1; //gen bit
			lfsr = (lfsr >> 1) | (bit << 15); //calc state
		} while (lfsr < min || lfsr > max); //check if result is desired
		return lfsr;
	}
};
