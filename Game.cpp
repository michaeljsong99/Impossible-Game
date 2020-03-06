#include "Game.h"


// Constructor
CGame::CGame(float a_nWindowHeight, float a_nWindowWidth) 
{
	this->create(sf::VideoMode(a_nWindowWidth, a_nWindowHeight), "Impossible Game", sf::Style::Close | sf::Style::Resize);
	m_dWindowWidth = a_nWindowWidth;
	m_dWindowHeight = a_nWindowHeight;
	m_dVerticalFloor = (a_nWindowHeight * (0.66));
	m_dBlockBottom = m_dVerticalFloor;
	CRectObject ground(sf::Vector2f(m_dWindowWidth - (2*m_dBuffer), 2), sf::Vector2f(m_dStartingPosition, m_dVerticalFloor));
	m_oFloor = ground;
	m_oFloor.SetFillColor(sf::Color(200, 200, 200)); // Grey
	m_oFloor.SetPosition(sf::Vector2f(m_dStartingPosition, m_dVerticalFloor));
	m_oFloor.SetXSpeed(m_dGameSpeed);

	if (!m_oSoundtrack.openFromFile("Phazd.ogg"))
		throw "Could not open music";
	m_oBlock.Initialize(m_dBlockSize, m_dVerticalFloor, this);
	m_oBlock.SetPosition({ m_dStartingPosition + m_dBuffer, float(m_dVerticalFloor - m_dBlockSize) });
	m_oBlock.SetXSpeed(m_dGameSpeed);


	this->setKeyRepeatEnabled(true);
	m_oView.setSize(sf::Vector2f({ m_dWindowWidth, m_dWindowHeight }));
	m_oView.setCenter(sf::Vector2f({ m_dWindowWidth/2, m_dWindowHeight/2}));

	if (!m_oDeathSoundBuffer.loadFromFile("GlassBreak.ogg")) {
		throw "Could not open death sound";
	}
	m_oDeathSound.setBuffer(m_oDeathSoundBuffer);

	if (!m_oDeath.openFromFile("GlassBreak.ogg")) {
		throw "Could not open death sound";
	}

	if (!m_oFont.loadFromFile("Raleway.ttf"))
		throw "Could not open font.";
	m_oAttemptLabel.setFont(m_oFont);
	m_oAttemptLabel.setFillColor(sf::Color::White);
	m_oAttemptLabel.setCharacterSize(50);

	m_oLevel.SetLevel1();
}

// Destructor
CGame::~CGame()
{

}

void CGame::ResizeView(sf::View& a_oView) {
	float dAspectRatio = float(this->getSize().x) / float(this->getSize().y);
	a_oView.setSize(m_dWindowWidth * dAspectRatio, m_dWindowHeight);
}

void CGame::PlayGame()
{
	m_oAttemptLabel.setString("Attempt " + to_string(m_nAttemptNumber));
	float dTextWidth = m_oAttemptLabel.getLocalBounds().width;
	// Center the text.
	m_oAttemptLabel.setPosition({ m_dWindowWidth / 2 - (dTextWidth / 2), 50 });

	m_oLevel.StartPlayingMusic();

	float dDeltaTime = 0.0f;
	sf::Clock oClock;

	while (this->isOpen())
	{
		dDeltaTime = oClock.restart().asSeconds();
		 //check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;

		while (this->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->close();
				break;

			case sf::Event::KeyReleased:
				break;

			case sf::Event::Resized:
				ResizeView(m_oView);
				break;
			}
		}

		// Check Collision with Floor.
		bool bCanJump = false;
		CollisionType oFloorCollision = m_oBlock.GetCollider().CheckCollision(m_oFloor.GetCollider());
		if (oFloorCollision == AllowedBottomCollision) {
			m_oBlock.onCollision(oFloorCollision);
			bCanJump = true;
		}

		m_oBlock.UpdateMovement(dDeltaTime);
		m_oFloor.UpdateMovement(dDeltaTime);	// So CRectObject and Floor and Text all move together.
		
		// These two may have to move if the block continues to go up.
		float dBlockBottom = m_oBlock.GetPosition().y + m_dBlockSize;
		float dYMovement = 0;
		if (dBlockBottom <= m_dVerticalFloor - (0.2 * m_dWindowHeight))	{// Move the view and block up.
			dYMovement = dBlockBottom - m_dBlockBottom;	// Remember: smaller values are higher up on screen!
			int x = 1;
		}
		m_dBlockBottom = dBlockBottom;

		m_oAttemptLabel.move(sf::Vector2f(m_dGameSpeed * dDeltaTime, dYMovement));
		m_oView.move(sf::Vector2f(m_dGameSpeed * dDeltaTime, dYMovement));
 
		// Now check for collisions.
		if (dBlockBottom > m_dVerticalFloor) {
			m_oBlock.SetPosition({ m_oBlock.GetPosition().x, m_dVerticalFloor - m_dBlockSize });
			bCanJump = true;
		}

		float dRight = m_oView.getCenter().x + (m_dWindowWidth / 2);
		for (auto &Object : m_oLevel.m_vec_poPointersToObstacles) {

			
			if (Object == nullptr) { // The object has already passed the screen.
				continue;
			}

			if (Object->GetLeft() > dRight) { // The object is not yet on the screen.
				continue;
			}

			CollisionType oCollisionStatus = m_oBlock.GetCollider().CheckCollision(Object->GetCollider());
			if (oCollisionStatus == Death) {
				//m_bIsBlockAlive = false;
				m_oBlock.SetFillColor(sf::Color::Red);
				break;
			}
			else if (oCollisionStatus == AllowedBottomCollision) {
				m_oBlock.onCollision(oCollisionStatus);
				bCanJump = true;
				Object->Fade();
			}
			else if (oCollisionStatus == XCollision) {
				Object->Fade();
			}
			
			else  {
				continue;
			}
		}
		m_oBlock.SetCanJump(bCanJump);
		m_oLevel.DeletePassedObstacles(m_oView.getCenter().x - (m_dWindowWidth/2));

		this->clear(m_oBackgroundColor);
		this->setView(m_oView);

		// draw everything here...
		m_oFloor.Draw(*this);
		m_oLevel.DrawObstacles(*this);
		this->draw(m_oAttemptLabel);
		                                                     
		if (m_bIsBlockAlive) {
			m_oBlock.Draw(*this);
		}

		// The block has died.
		else {
			//m_oSoundtrack.stop();
			m_oLevel.StopPlayingMusic();
			m_oDeath.play();
			while (m_oDeath.getStatus() == sf::SoundSource::Playing) {
				;
			}
			m_oDeath.stop();
			sf::Clock oDelay;
			sf::sleep(sf::seconds(1));
			m_nAttemptNumber++;
			RestartGame();
		}

		// end the current frame
		this->display();

	}
}


void CGame::RestartGame() {
	m_oBlock.Initialize(m_dBlockSize, m_dVerticalFloor, this);
	m_bIsBlockAlive = true;
	m_oBlock.SetPosition({ m_dStartingPosition + m_dBuffer, m_dVerticalFloor - m_dBlockSize});

	m_oFloor.SetPosition(sf::Vector2f(m_dStartingPosition, m_dVerticalFloor));

	m_oView.setSize(sf::Vector2f({ m_dWindowWidth, m_dWindowHeight }));
	m_oView.setCenter(sf::Vector2f({ m_dWindowWidth/2, m_dWindowHeight/2 }));

	m_oLevel.RestartLevel();

	PlayGame();
}