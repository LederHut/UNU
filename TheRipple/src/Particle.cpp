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

void Particle::Update(double mousex, double mousey)
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
				std::cout << "dead" << std::endl;
				p.lifetime--;
			}
		}
	}
	//3. create new particle
	if (Particles.size() != MAX_PARTICLES)
	{
		if (mousex >= 0 && mousey >= 0)
		{
			particle p;

			p.pos.x = mousex;
			p.pos.y = mousey;
			p.pos.z = 0.0f;
			
			glm::normalize(p.pos);

			std::vector<float> pos{ p.pos.x,p.pos.y,p.pos.z };

			p.index = Particles.size();

			Particles.push_back(p);
			GLCall(glBufferSubData(GL_ARRAY_BUFFER, p.index * (3 * sizeof(float)), 3 * sizeof(float), pos.data()));

		}
	}
	else if(!DeadParticles.empty())
	{
		if (mousex >= 0 && mousey >= 0)
		{
			particle p;

			p.pos.x = mousex;
			p.pos.y = mousey;
			p.pos.z = 1.0f;
			p.index = DeadParticles.back();

			std::vector<float> pos{ p.pos.x,p.pos.y,p.pos.z };

			Particles[DeadParticles.back()] = p;

			DeadParticles.pop_back();

			//bind the buffer before
			glBufferSubData(GL_ARRAY_BUFFER, p.index * (3 * sizeof(float)), 3 * sizeof(float), pos.data());
		}
	}
	//4. buffer the data
	
}
