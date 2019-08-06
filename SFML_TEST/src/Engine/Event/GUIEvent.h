#pragma once

class GUIEvent
{
public:

	GUIEvent() = default;
	inline GUIEvent(unsigned int type, unsigned int elementid) : m_EventType(type), m_ElementID(elementid) {}
	~GUIEvent() = default;

	inline const unsigned int& GetElementID() { return m_ElementID; }
	inline const unsigned int& GetType() { return m_EventType; }

	GUIEvent& operator=(const GUIEvent & rhs)
	{
		return *this;
	}

private:

	const unsigned int m_EventType;
	const unsigned int m_ElementID;

};