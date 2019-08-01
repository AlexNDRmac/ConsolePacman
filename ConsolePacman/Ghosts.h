#pragma once

#include "Unit.h"
#include "GameBoard.h"

class Ghosts :
	public Unit {
private:
	int target_x, target_y;
	queue<int>* direction = new queue<int>();
	enum GhostWay {up, down, left, right};
public:
	Ghosts(int pos_x, int pos_y, char avatar, int color);
	~Ghosts();

	int getDirection();
	void setTarget(int target_x, int target_y);

	void reset();
	void chasePacman();
	void choose_rnd_way();
	void move_ghost();
};
