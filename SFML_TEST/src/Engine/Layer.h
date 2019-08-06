#pragma once

#include "Event/EventStack.h"

class Layer
{
public:
	Layer();
	virtual ~Layer() = default;

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void OnUpdate() {} // exmp: render ,process mechanics, other updates perframe.
	virtual void OnEvent(EventStack& evstack) {}
	//virtual void OnEvent(std::vector<EntityEvent> entityevents) {}
};

