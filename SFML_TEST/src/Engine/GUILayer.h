#pragma once

#include "Engine/Layer.h"

#include <SFML/Graphics.hpp>

class GUILayer
	:public Layer
{
protected:

	sf::RenderWindow& r_Window;

	GUILayer(sf::RenderWindow& window)
		:r_Window(window) {};

	~GUILayer() {};
};

