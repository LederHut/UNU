#pragma once

#include "data.h"

// the Particle class is like a handler for one particle effect thingy.


class Particle:
	public data
{
public:

	Particle(TR_FLAG flag, float theta = 0.0f);
	~Particle();

	void GeneratePatricles(unsigned int count, glm::fvec3 pos, unsigned int effect = 0);


private:

	float Theta;

	std::vector<float> UnitDirections;

	void GetDirections();

};

