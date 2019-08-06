#pragma once

#include <SFML/Graphics.hpp>

#include "Event/GUIEvent.h"

class Button
	: public GUIEvent, public sf::RectangleShape
{
public:

	Button(const unsigned int id)
		:GUIEvent(EventType::ButtonPressed,id) {};

	~Button() {};

	inline bool IsMouseInside(const sf::Vector2i& mouse)
	{
		const sf::Vector2f& boxo = this->getPosition();
		const sf::Vector2f& boxs = this->getSize();

		if (mouse.x < boxo.x || mouse.x > boxs.x+boxo.x)
			return false;
		if (mouse.y < boxo.y || mouse.y > boxs.y+boxo.y)
			return false;
		//else
		return true;
	}
};

