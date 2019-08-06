#pragma once

#include <SFML/Window/Event.hpp>
#include "EventTypes.h"
#include "GUIEvent.h"

class UserEvent 
{
public:

	UserEvent() = default;
	~UserEvent() = default;

	inline sf::Event& GetSFMLEvent() { return *m_SFMLEvent; }
	inline GUIEvent& GetGUIEvent() { return *m_GUIEvent; }

	inline void SetGUIEvent(GUIEvent* guievent) { m_GUIEvent = guievent; Handeld = false;}
	inline void SetSFMLEvent(sf::Event* sfmlevent) { m_SFMLEvent = sfmlevent; Handeld = false;}
	inline void Disconncet() { m_SFMLEvent = nullptr; m_GUIEvent = nullptr; }

public:

	bool Handeld = true;

private:

	sf::Event* m_SFMLEvent = nullptr;
	GUIEvent* m_GUIEvent = nullptr;
	
};