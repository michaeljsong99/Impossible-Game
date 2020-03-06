#ifndef GAME_H
#define GAME_H

#include "SFML\Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Block.h"
#include "CRectObject.h"
#include "Spike.h"
#include "Level.h"
#include <vector>
#include <iostream>

using namespace std;


class CGame : public sf::RenderWindow {

public:
	CGame(float a_dWindowHeight, float a_dWindowWidth);
	~CGame();

	void ResizeView(sf::View &a_View);
	void PlayGame();
	void RestartGame();
	

private:
	float m_dStartingPosition = 100.0f;
	float m_dBuffer = 100.0f;
	float m_dBlockSize = 50.0f;
	float m_dWindowHeight;
	float m_dWindowWidth;
	int m_nAttemptNumber = 1;
	int m_nLevel;
	float m_dVerticalFloor;
	bool m_bIsBlockAlive = true;
	float m_dGameSpeed = 510.0f;
	CRectObject m_oFloor;
	sf::Color m_oBackgroundColor = sf::Color(35, 102, 209); // Turquoise
	sf::Music m_oSoundtrack;
	sf::SoundBuffer m_oDeathSoundBuffer;
	sf::Sound m_oDeathSound;
	sf::Music m_oDeath;
	CBlock m_oBlock;
	sf::View m_oView;

	Level m_oLevel;

	sf::Text m_oAttemptLabel;
	sf::Font m_oFont;

	float m_dBlockBottom;

};

#endif