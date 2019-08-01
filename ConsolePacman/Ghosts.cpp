#include "stdafx.h"
#include "Ghosts.h"

Ghosts::Ghosts(int pos_x, int pos_y, char avatar, int color) : 
	Unit(pos_x, pos_y, avatar, color) {
}

Ghosts::~Ghosts() {
	delete direction;
}

int Ghosts::getDirection() {
	int way = direction->front();
	direction->pop();
	return way;
}

void Ghosts::setTarget(int target_x, int target_y) {
	this->target_x = target_x;
	this->target_y = target_y;
}

void Ghosts::reset() {
	Unit::reset();
	while (!direction->empty()) {
		direction->pop();
	}
}

void Ghosts::chasePacman() {

	if (!direction->empty()) {
		return;
	}
	
	int diff_x, diff_y;
	int route_x = getPositionX();
	int route_y = getPositionY();
	int next_step;
	double min_cost = 100;
	double cost = 100;

	for (int step = 0; step < 3; step++) {

		for (int move = up; move <= right; move++) {
			if (checkMoveAbility(move) == true) {
				switch (move) {
				case up:
					diff_x = target_x - route_x;
					diff_y = target_y - (route_y - 1);
					break;
				case down:
					diff_x = target_x - route_x;
					diff_y = target_y - (route_y + 1);
					break;
				case left:
					diff_x = target_x - (route_x - 1);
					diff_y = target_y - route_y;
					break;
				case right:
					diff_x = target_x - (route_x + 1);
					diff_y = target_y - route_y;
					break;
				}

				cost = hypot(diff_x, diff_y);
			}

			if (cost < min_cost) {
				min_cost = cost;
				next_step = move;
				route_x = target_x - diff_x;
				route_y = target_y - diff_y;
			}
		}
		direction->push(next_step);
	}
}

void Ghosts::choose_rnd_way() {
	int ai_logic = rand() % 4;

	direction->push(ai_logic);
}

void Ghosts::move_ghost() {
	if (direction->empty()) {
		choose_rnd_way();
	}
	int way = getDirection();
	
	switch (way) {
	case up:
		Unit::moveUp();
		break;
	case down:
		Unit::moveDown();
		break;
	case left:
		Unit::moveLeft();
		break;
	case right:
		Unit::moveRight();
		break;
	}
}
