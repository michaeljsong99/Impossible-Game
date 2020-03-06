#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SFML\Graphics.hpp"
#include "Collider.h"

class Obstacle {

public:
	Obstacle() {};
	virtual ~Obstacle() {};

	virtual Collider GetCollider() = 0;
	virtual float GetLeft() = 0;
	virtual float GetRight() = 0;
	virtual void Draw(sf::RenderWindow &a_oWindow) = 0;
	virtual void Fade() = 0;
	virtual void ResetFillColor() = 0;
	virtual Shape GetShape() = 0;

protected:
	sf::Color m_oEndColor = sf::Color::White;
	float m_dLeft;
	float m_dRight;

};





#endif