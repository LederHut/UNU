#include "Particle.h"


Particle::Particle()
{
	PositionData.resize(MAX_PARTICLES * 3);

	CreateVertexArray(1);

	CreateVertexBuffer(1, MAX_PARTICLES * (3 * sizeof(float)), NULL, GL_STREAM_DRAW);
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
	//2. update lifetime of particles
	if (!Particles.empty())
	{
		for (particle& p : Particles)
		{
			//2.update and check for dead ones and save them as free
			if (p.lifetime > 0)
			{
				p.lifetime--;
				if (p.pos.y < 599.0f)
				{
					p.pos += p.velocity * p.mass;
				}
					

				PositionData[p.index * 3] = p.pos.x;
				PositionData[(p.index * 3) + 1] = p.pos.y;
				PositionData[(p.index * 3) + 2] = p.pos.z;

			}
			else if (p.lifetime == 0)
			{
				DeadParticles.push_back(p.index);
				p.lifetime--;
				//std::cout << "dead" << std::endl;
			}
		}
	}

	//4. buffer the data
	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * PositionData.size(), PositionData.data());
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

	//1. create new particle
	if (Particles.size() + points.size() / 3 < MAX_PARTICLES)
	{
		if (!points.empty())
		{
			for (size_t i = 0; i < points.size();)
			{
				particle p;

				p.pos.x = points[i++];
				p.pos.y = points[i++];
				p.pos.z = points[i++];
				p.index = Particles.size();

				Particles.push_back(p);
				AliveParticles.push_back(p.index);

				PositionData[p.index * 3] = p.pos.x;
				PositionData[(p.index * 3) + 1] = p.pos.y;
				PositionData[(p.index * 3) + 2] = p.pos.z;
			}
			std::cout << Particles.size() << std::endl;
		}
	}
	else if (!DeadParticles.empty() && DeadParticles.size() >= points.size() / 3)
	{
		if (!points.empty())
		{
			for (size_t i = 0; i < points.size();)
			{
				particle& p = Particles[DeadParticles.back()];

				p.pos.x = points[i++];
				p.pos.y = points[i++];
				p.pos.z = points[i++];
				p.lifetime = i;

				DeadParticles.pop_back();
				AliveParticles.push_back(p.index);

				PositionData[p.index * 3] = p.pos.x;
				PositionData[(p.index * 3) + 1] = p.pos.y;
				PositionData[(p.index * 3) + 2] = p.pos.z;
			}
		}
	}
}
