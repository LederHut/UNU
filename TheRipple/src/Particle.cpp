#include "Particle.h"


Particle::Particle()
{

	CreateVertexArray(1);
	CreateVertexBuffer(1, MAX_PARTICLES * (3 * sizeof(float)) , NULL, GL_DYNAMIC_DRAW);

	AddAttribPointer(3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	LoadShader(std::string("VShader"), GL_VERTEX_SHADER);
	LoadShader(std::string("FShader"), GL_FRAGMENT_SHADER);

	LinkShader();
}

Particle::~Particle()
{
}

void Particle::Update()
{
	//1. update lifetime of particles
	if (!Particles.empty())
	{
		for(particle& p: Particles)
		{
			//2.update and check for dead ones and save them as free
			if (p.lifetime > 0)
				p.lifetime--;
			else if (p.lifetime == 0)
			{
				DeadParticles.push_back(p.index);

				p.lifetime--;
				p.pos.z = 1.0f;

				std::vector<float> pos{ p.pos.x,p.pos.y,p.pos.z };

				glBufferSubData(GL_ARRAY_BUFFER, p.index * (3 * sizeof(float)), 3 * sizeof(float), pos.data());
			}
		}
	}
	//3. create new particle
	if (Particles.size() + BrushPoints.size() / 3 < MAX_PARTICLES)
	{
		if (!BrushPoints.empty())
		{
			for (size_t i = 0; i < BrushPoints.size();)
			{
				particle p;

				p.pos.x = BrushPoints[i++];
				p.pos.y = BrushPoints[i++];
				p.pos.z = 0.0f;
				i++;

				p.lifetime += (3 * i);

				std::vector<float> pos{ p.pos.x,p.pos.y,p.pos.z };

				p.index = Particles.size();

				Particles.push_back(p);
				glBufferSubData(GL_ARRAY_BUFFER, p.index * (3 * sizeof(float)), 3 * sizeof(float), pos.data());
			}
			BrushPoints = std::vector<float>();
			std::cout << Particles.size() << std::endl;
		}
	}
	else if(!DeadParticles.empty() && DeadParticles.size() >= BrushPoints.size() / 3)
	{
		if (!BrushPoints.empty())
		{
			for (size_t i = 0; i < BrushPoints.size();)
			{
				particle p;

				p.pos.x = BrushPoints[i++];
				p.pos.y = BrushPoints[i++];
				p.pos.z = 0.0f;
				i++;

				p.lifetime += (3 * i);

				std::vector<float> pos{ p.pos.x,p.pos.y,p.pos.z };

				p.index = Particles[DeadParticles.back()].index;
				Particles[DeadParticles.back()] = p;

				DeadParticles.pop_back();

				glBufferSubData(GL_ARRAY_BUFFER, p.index * (3 * sizeof(float)), 3 * sizeof(float), pos.data());
			}
			BrushPoints = std::vector<float>();
		}
	}
	//4. buffer the data
	
}

void Particle::Brush(glm::fvec3 pressed,float range)
{
	std::vector<float> points;

	for (float x = 0; x < range; x++)
	{
		for (float y = 0; y < range; y++)
		{
			std::vector<float> p{	pressed.x + x, pressed.y + y, 0.0f,
									pressed.x + x, (pressed.y - range) + y, 0.0f,
									(pressed.x - range) + x, pressed.y + y, 0.0f,
									(pressed.x - range) + x, (pressed.y - range) + y, 0.0f	};
			points.insert(std::end(points),std::begin(p),std::end(p));
		}
	}

	BrushPoints = points;
}
