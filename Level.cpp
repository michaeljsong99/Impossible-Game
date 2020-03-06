#include "Level.h"


Level::Level() {

}

Level::~Level() {
	// Maybe have to delete the objects?
}

void Level::RestartLevel() {

	m_vec_poPointersToObstacles.clear();
	for (auto &Rect : m_vec_oRectObstacles) {
		CRectObject *Object = &Rect;
		m_vec_poPointersToObstacles.emplace_back(Object);
	}

	for (auto &Spikes : m_vec_oSpikes) {
		Spike *Object = &Spikes;
		m_vec_poPointersToObstacles.emplace_back(Object);
	}

	for (auto &Obstacle : m_vec_poPointersToObstacles) {
		Obstacle->ResetFillColor();
	}
}

void Level::StartPlayingMusic() {
	m_oLevelMusic.play();
}

void Level::StopPlayingMusic() {
	m_oLevelMusic.stop();
}

void Level::DrawObstacles(sf::RenderWindow &a_oWindow) {
	for (auto &oObstacle : m_vec_poPointersToObstacles) {
		if (oObstacle != nullptr)
			oObstacle->Draw(a_oWindow);
	}
}

void Level::DeletePassedObstacles(float a_dWindowLeft) {

	for (auto i = m_vec_poPointersToObstacles.begin(); i != m_vec_poPointersToObstacles.end(); ++i)
	{
		if (*i == nullptr) {
			continue;
		}
		if (a_dWindowLeft > (*i)->GetRight()) {
			*i = nullptr;
		}
	}
}

void Level::SetLevel1() {
	const std::string m_strSoundTrack = "Phazd.ogg";
	if (!m_oLevelMusic.openFromFile(m_strSoundTrack))
		throw "Could not open music";

	CRectObject obs(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3200, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs2(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3250, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs3(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3425, m_dVerticalFloor - 3 * m_dBlockSize), true);
	CRectObject obs4(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3600, m_dVerticalFloor - 5 * m_dBlockSize), true);
	CRectObject obs5(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3775, m_dVerticalFloor - 7 * m_dBlockSize), true);
	CRectObject obs6(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4250, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs7(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(3950, m_dVerticalFloor - 9 * m_dBlockSize), true);
	CRectObject obs8(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4125, m_dVerticalFloor - 11 * m_dBlockSize), true);
	CRectObject obs9(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4300, m_dVerticalFloor - 13 * m_dBlockSize), true);
	CRectObject obs10(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4475, m_dVerticalFloor - 15 * m_dBlockSize), true);
	CRectObject obs11(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4650, m_dVerticalFloor - 17 * m_dBlockSize), true);
	CRectObject obs12(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4800, m_dVerticalFloor - 15.5 * m_dBlockSize), true);
	CRectObject obs13(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(4950, m_dVerticalFloor - 14 * m_dBlockSize), true);
	CRectObject obs14(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(5100, m_dVerticalFloor - 12.5 * m_dBlockSize), true);
	CRectObject obs15(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(5250, m_dVerticalFloor - 11 * m_dBlockSize), true);

	CRectObject obs16(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6400, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs17(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6625, m_dVerticalFloor - 3 *m_dBlockSize), true);
	CRectObject obs18(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6800, m_dVerticalFloor - 5 * m_dBlockSize), true);
	CRectObject obs19(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6975, m_dVerticalFloor - 3.5 * m_dBlockSize), true);
	CRectObject obs20(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6975, m_dVerticalFloor - 7 * m_dBlockSize), true);
	CRectObject obs21(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(6975, m_dVerticalFloor - 9.3 * m_dBlockSize), true);
	CRectObject obs22(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7150, m_dVerticalFloor - 3.5 * m_dBlockSize), true);
	CRectObject obs23(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7325, m_dVerticalFloor - 5.7 * m_dBlockSize), true);
	CRectObject obs24(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7325, m_dVerticalFloor - 8 * m_dBlockSize), true);
	CRectObject obs25(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7550, m_dVerticalFloor - 4.5 * m_dBlockSize), true);
	CRectObject obs26(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7600, m_dVerticalFloor - 4.5 * m_dBlockSize), true);
	CRectObject obs27(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(7850, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs28(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(8200, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs29(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(8375, m_dVerticalFloor - 3 * m_dBlockSize), true);
	CRectObject obs30(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(8550, m_dVerticalFloor - 5 * m_dBlockSize), true);

	CRectObject obs31(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(9260, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs32(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(9310, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs33(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(9500, m_dVerticalFloor - m_dBlockSize), true);
	CRectObject obs34(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(9675, m_dVerticalFloor - 3 * m_dBlockSize), true);
	CRectObject obs35(sf::Vector2f(m_dBlockSize, m_dBlockSize), sf::Vector2f(9850, m_dVerticalFloor - 5 * m_dBlockSize), true);



	Spike oSpike(50.0f, sf::Vector2f(1200, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike1(50.0f, sf::Vector2f(1800, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike2(50.0f, sf::Vector2f(1800 +m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike3(50.0f, sf::Vector2f(4250, m_dVerticalFloor - 2*m_dBlockSize));
	Spike oSpike4(50.0f, sf::Vector2f(5900, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike5(50.0f, sf::Vector2f(7500, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike6(50.0f, sf::Vector2f(7500 + m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike7(50.0f, sf::Vector2f(7500, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike8(50.0f, sf::Vector2f(7500 + 2 *m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike9(50.0f, sf::Vector2f(7600, m_dVerticalFloor - 5.5 * m_dBlockSize));
	Spike oSpike10(50.0f, sf::Vector2f(7850, m_dVerticalFloor - 2 * m_dBlockSize));
	Spike oSpike11(50.0f, sf::Vector2f(8850, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike12(50.0f, sf::Vector2f(8850 + m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike13(50.0f, sf::Vector2f(9310, m_dVerticalFloor - 2 * m_dBlockSize));
	Spike oSpike14(50.0f, sf::Vector2f(10000, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike15(50.0f, sf::Vector2f(10000 + m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike16(50.0f, sf::Vector2f(10000 + 2 *m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike17(50.0f, sf::Vector2f(10000 + 3 * m_dSpikeLength, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike18(50.0f, sf::Vector2f(10500, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike19(50.0f, sf::Vector2f(10615, m_dVerticalFloor - m_dBlockSize));
	Spike oSpike20(50.0f, sf::Vector2f(10735, m_dVerticalFloor - m_dBlockSize));



	CRectObject pit1(sf::Vector2f(1500, m_dPitThickness), sf::Vector2f(3500, m_dVerticalFloor), false);
	CRectObject pit2(sf::Vector2f(100, m_dPitThickness), sf::Vector2f(5600, m_dVerticalFloor), false);
	CRectObject pit3(sf::Vector2f(950, m_dPitThickness), sf::Vector2f(6400, m_dVerticalFloor), false);
	CRectObject pit4(sf::Vector2f(500, m_dPitThickness), sf::Vector2f(8250, m_dVerticalFloor), false);


	m_vec_oRectObstacles = { obs, obs2, obs3, obs4, obs5, obs6, obs7, obs8, obs9, obs10, obs11, obs12,
							 obs13, obs14, obs15, obs16, obs17, obs18, obs19, obs20, obs21, obs22, obs23, obs24,
							 obs25, obs26, obs27, obs28, obs29, obs30, obs31, obs32, obs33, obs34, obs35,
		 pit1, pit2, pit3, pit4};

	m_vec_oSpikes = { oSpike, oSpike1, oSpike2, oSpike3, oSpike4, oSpike6, oSpike7, oSpike8, oSpike9, oSpike10,
						oSpike11, oSpike12, oSpike13, oSpike14, oSpike15, oSpike16, oSpike17, oSpike18,
						oSpike19, oSpike20};

	for (auto &Rect : m_vec_oRectObstacles) {
		CRectObject *Object = &Rect;
		m_vec_poPointersToObstacles.emplace_back(Object);
	}

	for (auto &Spikes : m_vec_oSpikes) {
		Spike *Object = &Spikes;
		m_vec_poPointersToObstacles.emplace_back(Object);
	}

}

