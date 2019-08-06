#pragma once

#include <SFML/Graphics.hpp>
#include "UserEvent.h"

class EventStack
{
public:
	EventStack();
	~EventStack();

	inline std::vector<UserEvent>& GetUserEvents() { return UserEvents; }

	void ReceiveGUIEvent(GUIEvent* guievent);
	void PollSFMLEvents(sf::RenderWindow& window);
	void DiscardEvents();

private:

	std::vector<UserEvent> UserEvents;
	std::vector<sf::Event> SFMLEvents;
	//std::vector<EntityEvent> EntityEvents;
};

