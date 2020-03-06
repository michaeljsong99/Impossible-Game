#ifndef LEVEL_H
#define LEVEL_H

#include "CRectObject.h"
#include "Spike.h"
#include "SFML\Audio.hpp"
#include <vector>

class Level {

public:
	Level();
	~Level();

	void RestartLevel();
	void StartPlayingMusic();
	void StopPlayingMusic();

	void DrawObstacles(sf::RenderWindow &a_oWindow);

	void SetLevel1();
	void DeletePassedObstacles(float a_dWindowLeft);
	std::vector<Obstacle*> m_vec_poPointersToObstacles;

private:
	
	float m_dLevelSpeed = 300.0f;
	sf::Music m_oLevelMusic;

	std::vector<CRectObject> m_vec_oRectObstacles;
	std::vector<Spike> m_vec_oSpikes;

	const float m_dBlockSize = 50.0f;
	const float m_dSpikeLength = 50.0f;
	const float m_dVerticalFloor = 528.0f;
	const float m_dPitThickness = 25.0f;

};

#endif