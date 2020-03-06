#ifndef SPIKE_H
#define SPIKE_H

#include "SFML\Graphics.hpp"
#include "Collider.h"
#include "Obstacle.h"

// A Spike is just a triangle.
class Spike : public Obstacle {
public:
	Spike() {}
	Spike(float a_dSpikeHeight, sf::Vector2f &a_oPosition);	// Equilateral triangle, use this to calculate the side length.
	~Spike();

	void Draw(sf::RenderWindow &a_oWindow);
	void SetFillColor(sf::Color &a_oColor);
	void ResetFillColor();

	Collider GetCollider() { return Collider(m_oTriangle, m_oPosition); }

	float GetLeft();
	float GetRight();

	void Fade();
	Shape GetShape() { return Triangle; }

	sf::Vector2f m_oPosition;

private:
	float m_dSpikeHeight;
	float m_dDefaultColor = 66;
	float m_dStartingColor = 66;
	
	sf::ConvexShape m_oTriangle;
};

#endif