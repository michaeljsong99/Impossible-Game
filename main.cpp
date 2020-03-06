#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "SFML\Graphics.hpp"
#include "Game.h"

int main() {
	CGame game(800, 1000);
	game.PlayGame();
	return 0;
}
