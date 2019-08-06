#include "pch.h"
#include "EventStack.h"


EventStack::EventStack()
	:UserEvents(128, UserEvent()), SFMLEvents(32, sf::Event())
{
}


EventStack::~EventStack()
{
}

void EventStack::ReceiveGUIEvent(GUIEvent* guievent)
{
	for (UserEvent& ue : UserEvents)
	{
		if (ue.Handeld)
			ue.SetGUIEvent(guievent);
	}
}

void EventStack::PollSFMLEvents(sf::RenderWindow & window)
{
	auto ueb = UserEvents.begin();
	for(sf::Event& event: SFMLEvents)
	{
		if (window.pollEvent(event) && ueb->Handeld)
			ueb->SetSFMLEvent(&event);
		++ueb;
	}
}

void EventStack::DiscardEvents()
{
	for (UserEvent& ue : UserEvents)
	{
		ue.Handeld = true;
		ue.Disconncet();
	}
}
