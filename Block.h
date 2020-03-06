#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include "Collider.h"

class CBlock {

public:
	CBlock();
	~CBlock();

	void Initialize(double a_dSideLength, int a_nBottomLocation, sf::RenderWindow *a_poGameWindow);
	void MoveUpOrDown(int a_nDeltaY);
	void onCollision(CollisionType);

	void Draw(sf::RenderWindow &a_oWindow);
	void SetPosition(sf::Vector2f a_oPosition);

	void SetCanJump(bool a_bStatus);

	void SetXSpeed(float a_dSpeed);

	sf::Vector2f GetPosition() { return m_oBody.getPosition(); }
	Collider GetCollider() { return Collider(m_oBody, true); }

	sf::Vector2f m_oVelocity = sf::Vector2f(0.0f, 0.0f);

	void UpdateMovement(float a_dDeltaTime);
	float m_dBlockSize = 50.0f;

	void SetFillColor(sf::Color a_oColor);

private:
	sf::RectangleShape m_oBody;
	double m_dSideLength;
	int m_nJumpHeight = 120;
	int m_nBottomLocation;
	sf::Color m_oColor = sf::Color(252, 153, 25); // Orange
	int m_nDegreeRotated = 0;
	bool m_bCanJump = true;
	sf::RenderWindow *m_poGameWindow;
	
};

#endif