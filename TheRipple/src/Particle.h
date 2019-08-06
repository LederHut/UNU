#pragma once

#define MAX_PARTICLES 1000000
#define PARTICLE_LIFETIME 1000.0f //equals 1000 frames
#define PARTICLE_MASS 0.753f // equal to the mass of 5 billion dust particles

#include "data.h"

// the Particle class is like a handler for one particle effect thingy.


struct particle
{
	glm::fvec3 pos = { 0.0f, 0.0f, 0.0f };
	glm::fvec3 velocity = { 0.0f, 0.2123f, 0.0f };
	//glm::fvec4 color; //not in use yet

	float lifetime = PARTICLE_LIFETIME;
	float mass = PARTICLE_MASS;

	unsigned int index = 0;
};

class Particle:
	public data
{
public:

	Particle();
	~Particle();

	void Update();

	void Brush(glm::fvec3 pressed, float range);

	size_t Amount() { return Particles.size(); }

private:

	float Theta;

	std::vector<particle> Particles;

	std::vector<float> PositionData;
	std::vector<float> BrushPoints;

	std::vector<unsigned int> AliveParticles;
	std::vector<unsigned int> DeadParticles;



};

