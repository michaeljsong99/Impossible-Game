#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

enum CollisionType {
	Death,
	AllowedBottomCollision,
	XCollision,
	None
};

enum Shape {
	Rectangle,
	Triangle
};


class Collider {
public:
	Collider(sf::RectangleShape &a_oRectBody, bool a_bCanCollideTop);
	Collider(sf::ConvexShape &a_oTriangleBody, sf::Vector2f a_oPosition);
	~Collider();

	void Move(float a_dX, float a_dY);

	CollisionType CheckCollision(Collider &a_oOther);
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();

	bool m_bCanCollideTop;
	Shape m_oShape;
	sf::Vector2f m_oPosition;


private:
	sf::RectangleShape &m_oBody;
	sf::ConvexShape &m_oTriangleBody2;
};

#endif