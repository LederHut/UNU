#pragma once

#define MAX_PARTICLES 10000
#define PARTICLE_LIFETIME 10000.0f //equals 1000 frames

#include "data.h"

// the Particle class is like a handler for one particle effect thingy.


struct particle
{
	glm::fvec3 pos;
	//glm::fvec4 color; //not in use yet
	float lifetime = PARTICLE_LIFETIME;
	unsigned int index = 0;
};

class Particle:
	public data
{
public:

	Particle();
	~Particle();

	void Update(double mousex, double mousey);

	size_t Amount() { return Particles.size(); }

private:

	float Theta;

	std::vector<particle> Particles;

	std::vector<float> ParticlePointCoords;

	std::vector<unsigned int> DeadParticles;

};

