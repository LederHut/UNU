#pragma once

#include "Engine/GUILayer.h"
#include "Engine/Button.h"

class MainMenuLayer
	:public GUILayer
{
public:

	void OnAttach() override;
	void OnDetach() override;

	void OnUpdate() override; // exmp: render ,process mechanics, other updates perframe.

	void OnEvent(EventStack& evstack) override;

	MainMenuLayer(sf::RenderWindow& window);
	~MainMenuLayer();

private:

	Button mover;
	std::vector<Button> Buttons{1,2};
};

