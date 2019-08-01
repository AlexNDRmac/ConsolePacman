#pragma once

#include "Unit.h"
#include "Ghosts.h"
#include "GameBoard.h"

class Pacman :
	public Unit {
private:
	int live;
	int direction;
	bool waste;
public:
	Pacman();
	~Pacman();

	void chooseWay(int key);
	void movePacman();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void reset();

	bool isWasted();
	bool isCatched(Ghosts& ghost);
};
