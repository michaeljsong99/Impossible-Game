#include "Collider.h"
 
Collider::Collider(sf::RectangleShape &a_oBody, bool a_bCanCollideTop) :
m_oBody(a_oBody), m_bCanCollideTop(a_bCanCollideTop),
m_oTriangleBody2(sf::ConvexShape()), m_oShape(Rectangle)
{

}

Collider::Collider(sf::ConvexShape &a_oTriangleBody, sf::Vector2f a_oPosition) :
m_oBody(sf::RectangleShape()), m_bCanCollideTop(false),
m_oTriangleBody2(a_oTriangleBody), m_oShape(Triangle), m_oPosition(a_oPosition)
{

}

Collider::~Collider()
{

}

void Collider::Move(float a_dX, float a_dY) {
	if (m_oShape == Rectangle)
		m_oBody.move(a_dX, a_dY);
	else
		m_oTriangleBody2.move(a_dX, a_dY);
}

sf::Vector2f Collider::GetPosition() { 
	if (m_oShape == Rectangle)
		return m_oBody.getPosition();
	else
		return m_oPosition;
}

sf::Vector2f Collider::GetSize() {
	if (m_oShape == Rectangle)
		return m_oBody.getSize();
	else {
		sf::FloatRect oDimensions = m_oTriangleBody2.getLocalBounds();
		return sf::Vector2f(oDimensions.width, oDimensions.height);
	}
}

CollisionType Collider::CheckCollision(Collider &a_oOther) {
	
	sf::Vector2f oThisPosition = GetPosition();

	// Top and Bottom of the Block.
	float dTop = oThisPosition.y;
	float dBottom = dTop + GetSize().y;
	// Right and Left of the Block.
	float dLeft = oThisPosition.x;
	float dRight = dLeft + GetSize().x;

	sf::Vector2f oOtherPosition = a_oOther.GetPosition();

	
	// Top and Bottom of the other object.
	float dOtherTop = oOtherPosition.y;
	float dOtherBottom = oOtherPosition.y + a_oOther.GetSize().y;
	float dOtherLeft = oOtherPosition.x;
	float dOtherRight = dOtherLeft + a_oOther.GetSize().x;

	// Collision Variables.
	bool bXCollision = ((dLeft >= dOtherLeft && dLeft <= dOtherRight) ||
		(dRight >= dOtherLeft && dRight <= dOtherRight));

	// The top of the block collided with the bottom of the other object.
	bool bTopCollision = (dTop >= dOtherTop && dTop <= dOtherBottom);

	// The bottom of the block collided with the top of the other object.
	bool bBottomCollision = (dBottom <= dOtherBottom && dBottom >= dOtherTop);

	
	// If the other object is a rectangle, check for collisions:
	if (a_oOther.m_oShape == Rectangle) {

		if (bXCollision) {
			if (bTopCollision)
				return Death;
			else if (bBottomCollision) {
				if (dBottom > dOtherTop +3)	// The block isn't "on top of the CRectObject". It should die.
                                           	return Death;
				else if (!a_oOther.m_bCanCollideTop)
					return Death;
				else
					m_oBody.move(0, -(abs(dOtherTop - dBottom)));	// To adjust it so that it is on the platform.
					return AllowedBottomCollision;
			}
			else
				return XCollision;
		}

		else
			return None;
	}

	// Otherwise, the shape is a triangle.
	else {
		if (bXCollision) {

 			if (bTopCollision)
  				return Death;

			else if (bBottomCollision) {

				// We will have to calculate if the left or right vertice of the block is in the triangle.
				// Calculate how "far up" the block is the triangle.
				float dElevation = (dOtherBottom - dBottom) / a_oOther.GetSize().y;
				float dHalfSideLength = a_oOther.GetSize().x / 2;
				float dTriangleLeft = dOtherLeft + (dElevation * dHalfSideLength);
				float dTriangleRight = dOtherLeft + dHalfSideLength + ((1 - dElevation) * dHalfSideLength);

				bool bBlockLeftofTriangle = dRight < dTriangleLeft;
				bool bBlockRightofTriangle = dLeft > dTriangleRight;
				if (!(bBlockLeftofTriangle || bBlockRightofTriangle))	// The block is within the triangle.
					return Death;
				else
					return XCollision;
			}

			else
				return XCollision;
		}
		else
			return None;
	}
}