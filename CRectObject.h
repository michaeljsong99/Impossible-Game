#ifndef PLATFORM_H
#define PLATFORM_H
#include "Collider.h"
#include "Obstacle.h"

class CRectObject : public Obstacle {
public:
	CRectObject() {}
	CRectObject(sf::Vector2f a_oSize, sf::Vector2f a_oPosition, bool a_bOutline = false);
	~CRectObject(){}

	void Draw(sf::RenderWindow &a_oWindow);
	void SetFillColor(sf::Color &a_oColor);
	void ResetFillColor();
	void SetPosition(sf::Vector2f &a_oPosition);
	void SetXSpeed(float a_dSpeed);
	void UpdateMovement(float a_dDeltaTime);

	void Fade();

	Collider GetCollider() { return Collider(m_oBody, m_bIsPlatform); }

	float GetLeft();
	float GetRight();

	Shape GetShape() { return Rectangle; }

private:
	
	sf::RectangleShape m_oBody;
	float m_dXSpeed = 0;

	// For fading away.
	float m_dDefaultColor = 0;
	float m_dStartingColor = 0;
	sf::Clock m_oFadeTimer;
	bool m_bIsFading = false;
	bool m_bIsPlatform;
};

#endif