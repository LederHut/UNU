#include "Particle.h"


Particle::Particle(TR_FLAG flag, float theta)
{
	if (flag == TR_PATTERN_PACKED)
	{
		Theta = 10.0f; // 36 points on the
	}
	else if (flag == TR_PATTERN_LOOSE)
	{
		Theta = 20.0f; // 18 points
	}
	else
	{
		Theta = theta;
	}

	GetDirections();

	CreateVertexArray(1);
	CreateVertexBuffer(1, UnitDirections, GL_STATIC_DRAW);

	AddAttribPointer(3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), (void*)0);

	LoadShader(std::string("VShader"), GL_VERTEX_SHADER);
	LoadShader(std::string("FShader"), GL_FRAGMENT_SHADER);

	LinkShader();
}

Particle::~Particle()
{
}

void Particle::GeneratePatricles(unsigned int count, glm::fvec3 pos, unsigned int effect)
{

	if (effect == 1)
	{

	}
	else
	{
		while (count--)
		{

		}
	}

}

void Particle::GetDirections()
{
	float alpha = 0.0f;
	glm::fvec3 unitdir;

	if (!Theta)
	{
		return;
	}

	for (float points = 360 / Theta; points && alpha <= 360; points--)
	{
		unitdir = glm::normalize(glm::fvec3(glm::cos(alpha += Theta), glm::sin(alpha += Theta), 0.0f));
		unitdir = unitdir * 0.5f;

		UnitDirections.push_back(unitdir.x);
		UnitDirections.push_back(unitdir.y);
		UnitDirections.push_back(unitdir.z);
	}

}
