#include "pch.h"

#include "Engine/Layer.h"
#include "Engine/Event/EventStack.h"
#include "Engine/LayerSatck.h"

#include "Game/MainMenuLayer.h"

#include <SFML/Graphics.hpp>



bool sortbyhandeld(UserEvent& i, UserEvent& j)
{
	return (i.Handeld < j.Handeld);
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	EventStack EvStack;

	std::vector<UserEvent> UserEvents(64, UserEvent());
	std::vector<sf::Event> SFMLEvents(32, sf::Event());

	LayerStack* Layers = new LayerStack;

	MainMenuLayer* MML = new MainMenuLayer(window);

	Layers->PushLayer(MML);

	sf::Event event;

	decltype(SFMLEvents.begin()) end;

	while (window.isOpen())
	{
		EvStack.PollSFMLEvents(window);

		for (auto it = Layers->end(); it != Layers->begin(); )
		{
			(*--it)->OnEvent(EvStack);
		}
		EvStack.DiscardEvents();
		window.clear();
		for (auto begin = Layers->begin(); begin != Layers->end(); begin++)
		{
			(*begin)->OnUpdate();
		}
		window.display();
		
	}

	delete MML;

	return 0;
}