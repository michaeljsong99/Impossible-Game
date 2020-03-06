#include "CRectObject.h"

CRectObject::CRectObject(sf::Vector2f a_oSize, sf::Vector2f a_oPosition, bool a_bOutline) {
	m_oBody.setSize(a_oSize);
	m_oBody.setPosition(a_oPosition);
	m_oBody.setFillColor(sf::Color(m_dDefaultColor, m_dDefaultColor, m_dDefaultColor));
	m_bIsPlatform = a_bOutline;
	if (m_bIsPlatform)
		m_oBody.setOutlineThickness(1);
	m_dLeft = m_oBody.getPosition().x - m_oBody.getLocalBounds().width;
	m_dRight = m_oBody.getPosition().x + m_oBody.getLocalBounds().width;
}

void CRectObject::Draw(sf::RenderWindow &a_oWindow) {
	a_oWindow.draw(m_oBody);
}

float CRectObject::GetLeft() {
	return m_dLeft;
}

float CRectObject::GetRight() {
	return m_dRight;
}


void CRectObject::SetFillColor(sf::Color &a_oColor) {
	m_oBody.setFillColor(a_oColor);
}

void CRectObject::ResetFillColor() {
	m_oBody.setFillColor(sf::Color(m_dDefaultColor, m_dDefaultColor, m_dDefaultColor));
}

void CRectObject::SetPosition(sf::Vector2f &a_oPosition){
	m_oBody.setPosition(a_oPosition);
}

void CRectObject::SetXSpeed(float a_dSpeed) {
	m_dXSpeed = a_dSpeed;
}

void CRectObject::UpdateMovement(float a_dDeltaTime) {
	m_oBody.move(sf::Vector2f(m_dXSpeed, 0) * a_dDeltaTime);
}


void CRectObject::Fade() {
	if (!m_bIsPlatform)
		return;
	if (m_oBody.getFillColor() == m_oEndColor)
		return;
	m_dStartingColor += 1;
	m_oBody.setFillColor(sf::Color(m_dStartingColor, m_dStartingColor, m_dStartingColor));
}

