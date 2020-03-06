#include "Block.h"
#include "Collider.h"

CBlock::CBlock() {
	m_oBody.setFillColor(m_oColor);
}

CBlock::~CBlock() {}


void CBlock::Initialize(double a_dSideLength, int a_nBottomLocation, sf::RenderWindow *a_poGameWindow) {
	m_dSideLength = a_dSideLength;
	m_nBottomLocation = a_nBottomLocation;
	m_poGameWindow = a_poGameWindow;
	m_oBody.setSize(sf::Vector2f(a_dSideLength, a_dSideLength));
	m_bCanJump = true;
}


void CBlock::onCollision(CollisionType a_oCollisionStatus) {
	if (a_oCollisionStatus == Death) {
		m_oVelocity.x = 0.0f;
		m_oVelocity.y = 0.0f;
	}
	else if (a_oCollisionStatus == AllowedBottomCollision) {
		m_oVelocity.y = 0.0f;
	}
	else {	// There is no collision. The block is "floating". Gravity should pull it down. this is handled in the loop.
		;
	}
}

void CBlock::UpdateMovement(float a_dDeltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bCanJump) {
		m_bCanJump = false;
		m_oVelocity.y = -sqrtf(2.0f * 3981.0f * m_nJumpHeight);
	}

	// Add Gravity
	if (m_bCanJump == false) {
		m_oVelocity.y += 3981.0f * a_dDeltaTime;
		m_oBody.move(m_oVelocity * a_dDeltaTime);
	}
	else
		m_oBody.move(m_oVelocity * a_dDeltaTime);
}

void CBlock::Draw(sf::RenderWindow &a_oWindow) {
	a_oWindow.draw(m_oBody);
}

void CBlock::SetPosition(sf::Vector2f a_oPosition){
	m_oBody.setPosition(a_oPosition);
}

void CBlock::SetXSpeed(float a_dSpeed) {
	m_oVelocity.x = a_dSpeed;
}

void CBlock::SetCanJump(bool a_bStatus) {
	m_bCanJump = a_bStatus;
}

void CBlock::SetFillColor(sf::Color a_oColor) {
	m_oBody.setFillColor(a_oColor);
}