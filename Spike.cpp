#include "Spike.h"

Spike::Spike(float a_dSpikeHeight, sf::Vector2f &a_oPosition) {
	m_dSpikeHeight = a_dSpikeHeight;

	m_oPosition = a_oPosition;
	m_oTriangle.setPointCount(3);

	m_oTriangle.setPoint(0, sf::Vector2f(m_oPosition.x + (m_dSpikeHeight / 2), m_oPosition.y));
	m_oTriangle.setPoint(1, sf::Vector2f(m_oPosition.x, m_oPosition.y + m_dSpikeHeight));
	m_oTriangle.setPoint(2, sf::Vector2f(m_oPosition.x + m_dSpikeHeight, m_oPosition.y + m_dSpikeHeight));
	m_oTriangle.setFillColor(sf::Color(m_dStartingColor, m_dStartingColor, m_dStartingColor));
	m_oTriangle.setOutlineThickness(1);

	m_dLeft = m_oPosition.x - m_oTriangle.getLocalBounds().width;
	m_dRight = m_oPosition.x + m_oTriangle.getLocalBounds().width;
}

Spike::~Spike() {}

void Spike::Draw(sf::RenderWindow &a_oWindow) {
	a_oWindow.draw(m_oTriangle);
}

float Spike::GetLeft() {
	return m_dLeft;
}

float Spike::GetRight() {
	return m_dRight;
}

void Spike::SetFillColor(sf::Color &a_oColor) {
	m_oTriangle.setFillColor(a_oColor);
}

void Spike::ResetFillColor() {
	m_oTriangle.setFillColor(sf::Color(m_dDefaultColor, m_dDefaultColor, m_dDefaultColor));
}

void Spike::Fade() {
	if (m_oTriangle.getFillColor() == m_oEndColor)
		return;
	m_dStartingColor += 0.5;
	m_oTriangle.setFillColor(sf::Color(m_dStartingColor, m_dStartingColor, m_dStartingColor));
}