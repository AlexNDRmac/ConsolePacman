// ConsolePacman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameBoard.h"
#include "Pacman.h"
#include "Ghosts.h"
#include "Timer.h"

using namespace std;

int main() {
	int	enemyCounter = 0;
	bool isPacmanCatched = false;

	Timer* gameTime = new Timer(GAME_SPEED, DOOR_DELAY);

	GameBoard* level = new GameBoard();
	Pacman* pacman   = new Pacman();
	Ghosts* blinky   = new Ghosts(GHOST_POS_X,     GHOST_POS_Y - 3, GHOST, red);
	Ghosts* pinky    = new Ghosts(GHOST_POS_X - 1, GHOST_POS_Y,     GHOST, magenta);
	Ghosts* inky     = new Ghosts(GHOST_POS_X,     GHOST_POS_Y,     GHOST, cyan);
	Ghosts* clyde    = new Ghosts(GHOST_POS_X + 1, GHOST_POS_Y,     GHOST, darkYellow);

	vector<Ghosts*>* enemy = new vector<Ghosts*>();
	enemy->push_back(blinky);
	enemy->push_back(pinky);
	enemy->push_back(inky);
	enemy->push_back(clyde);
	enemyCounter = enemy->size();

	pacman->initUnit(level);
	for (int i = 0; i < enemyCounter; i++) {
		(*enemy)[i]->initUnit(level);
	}

	level->loadLevel();
	level->setWindowSize(level->getLevelHeight(), level->getLevelWidth(), SCREEN_OFFSET);
	level->displayIntro();
	level->render();
	
	gameTime->start();

	while (level->getEatenDots() != DOTS_HISCORE && pacman->isWasted() == false) {
		gameTime->update();

		if ( gameTime->ghostTime() ) {	
			if ( gameTime->doorTime() && level->isDoorOpen() == false) {
				level->openDoors();
			}

			pacman->movePacman();

			for (int i = 0; i < enemyCounter; i++) {
				if (pacman->isCatched(*(*enemy)[i])) {
					isPacmanCatched = true;
				}

				(*enemy)[i]->setTarget(pacman->getPositionX(), pacman->getPositionY());
				
				if (i == 0) {
					(*enemy)[i]->chasePacman();
				}

				(*enemy)[i]->move_ghost();

				if (pacman->isCatched(*(*enemy)[i])) {
					isPacmanCatched = true;
				}
			}
		}

		if (isPacmanCatched) {
			
			Sleep(3000);

			level->closeDoors();
			level->render();
			
			pacman->reset();
			pacman->draw();
			
			for (int i = 0; i < enemyCounter; i++) {
				(*enemy)[i]->reset();
				(*enemy)[i]->draw();
			}

			gameTime->speedUp();
			gameTime->reset();
			isPacmanCatched = !isPacmanCatched;
		}

		if (_kbhit()) {
			int key_input = _getch();
			pacman->chooseWay(key_input);
		}

		pacman->draw();
		
		for (int i = 0; i < enemyCounter; i++) {
			(*enemy)[i]->draw();
		}
	}

	level->gameOver();
	
	delete enemy;
	delete blinky;
	delete pinky;
	delete inky;
	delete clyde;
	delete pacman;
	delete level;

    return 0;
}
