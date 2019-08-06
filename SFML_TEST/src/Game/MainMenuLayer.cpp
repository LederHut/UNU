
#include "pch.h"

#include "MainMenuLayer.h"

MainMenuLayer::MainMenuLayer(sf::RenderWindow& window)
	:GUILayer(window), mover(3)
{
}

MainMenuLayer::~MainMenuLayer()
{
}

void MainMenuLayer::OnAttach()
{

	Buttons.at(0).setPosition(0.0, 0.0);
	Buttons.at(0).setSize(sf::Vector2f(50.0,50.0));
	Buttons.at(0).setFillColor(sf::Color::Blue);

	Buttons.at(1).setPosition(200.0, 0.0);
	Buttons.at(1).setSize(sf::Vector2f(50.0, 50.0));
	Buttons.at(1).setFillColor(sf::Color::Blue);

	mover.setPosition(100.0, 0.0);
	mover.setSize(sf::Vector2f(50.0, 50.0));
	mover.setFillColor(sf::Color::Blue);
}

void MainMenuLayer::OnDetach()
{
}

void MainMenuLayer::OnUpdate()
{
	for (Button& b : Buttons)
	{
		r_Window.draw(b);
	}
	r_Window.draw(mover);
}

void MainMenuLayer::OnEvent(EventStack& evstack)
{
	for (UserEvent& ue : evstack.GetUserEvents())
	{
		if (!ue.Handeld)
		{
			if (&ue.GetSFMLEvent() != nullptr)
			{
				sf::Event& event = ue.GetSFMLEvent();
				for (Button& b : Buttons)
				{
					const sf::Vector2i& mouse = sf::Mouse::getPosition(r_Window);
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (b.IsMouseInside(mouse))
						{
							evstack.ReceiveGUIEvent(&b);
							ue.Handeld = true;
						}

					}
				}
			}
			else if (&ue.GetGUIEvent() != nullptr)
			{
				GUIEvent& event = ue.GetGUIEvent();
				if (event.GetType() == EventType::ButtonPressed)
				{
					if (event.GetElementID() == 1 && mover.getPosition().x >= 100.0)
						mover.move(-50.0, 0.0);
					else if (event.GetElementID() == 2 && mover.getPosition().x <= 100.0)
						mover.move(50.0, 0.0);
					ue.Handeld = true;
				}
			}
		}
	}
}