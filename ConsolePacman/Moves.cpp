#include "stdafx.h"
#include "Moves.h"

Moves::Moves(int pos_x, int pos_y, char avatar) {
	this->pos_x   = pos_x;
	this->pos_y   = pos_y;
	this->start_x = pos_x;
	this->start_y = pos_y;
	this->prev_x  = this->pos_x;
	this->prev_y  = this->pos_y;
	this->avatar  = avatar;
}

Moves::~Moves() {}

int Moves::getPositionX() {
	return pos_x;
}
int Moves::getPositionY() {
	return pos_y;
}
int Moves::getPreviousX() {
	return prev_x;
}
int Moves::getPreviousY() {
	return prev_y;
}

char Moves::getAvatar() {
	return this->avatar;
}

void Moves::setPacman() {
	this->is_pacman = !is_pacman;
}

void Moves::setPositionX(int new_pos) {
	this->pos_x = new_pos;
}
void Moves::setPositionY(int new_pos) {
	this->pos_y = new_pos;
}
void Moves::saveCurrentPosition() {
	this->prev_x = pos_x;
	this->prev_y = pos_y;
}

void Moves::reset() {
	this->pos_x  = this->start_x;
	this->pos_y  = this->start_y;
	this->prev_x = this->start_x;
	this->prev_y = this->start_y;
}

bool Moves::isCanMove(GameBoard& level, int direction) {
	int target_x = pos_x;
	int target_y = pos_y;

	switch (direction) {
	case up:
		target_y -= 1;
		break;
	case down:
		target_y += 1;
		break;
	case left:
		target_x -= 1;
		break;
	case right:
		target_x += 1;
		break;
	default:
		break;
	}

	if (target_x < 0 || target_x >= level.getLevelWidth()) {
		return true;
	}

	char next_pos = level.getPosition(target_x, target_y);
	
	if (next_pos != MAP_WALL && next_pos != MAP_DOOR) {
		return true;
	}
	return false;
}

void Moves::moveUp(GameBoard& level) {
	int next_x = pos_x;
	int next_y = pos_y - 1;

	if (next_y > 0) {
		bool moved = moveUnit(level, next_x, next_y, up);

		if (moved) {
			setPositionY(next_y);
		}
	}
}
void Moves::moveDown(GameBoard& level) {
	int next_x = pos_x;
	int next_y = pos_y + 1;

	if (next_y < level.getLevelHeight()) {
		bool moved = moveUnit(level, next_x, next_y, down);

		if (moved) {
			setPositionY(next_y);
		}
	}
}
void Moves::moveLeft(GameBoard& level) {
	int next_x = pos_x - 1;
	int next_y = pos_y;

	if (next_x >= 0) {
		bool moved = moveUnit(level, pos_x, next_y, left);

		if (moved) {
			setPositionX(next_x);
		}
	}
	if (next_x < 0) {
		setPositionX(level.getLevelWidth() - 1);
	}
}
void Moves::moveRight(GameBoard& level) {
	int next_x = pos_x + 1;
	int next_y = pos_y;

	if (next_x < level.getLevelWidth()) {
		bool moved = moveUnit(level, next_x, next_y, right);
		
		if (moved) {
			setPositionX(next_x);
		}
	}

	if (next_x >= level.getLevelWidth()) {
		setPositionX(0);
	}
}

bool Moves::moveUnit(GameBoard& level, int new_x, int new_y, int direction) {
	if (isCanMove(level, direction)) {
		char next_item = level.getPosition(new_x, new_y);
		this->eatItems(level, next_item);

		return true;
	}

	return false;
}

void Moves::eatItems(GameBoard& level, char item) {
	if (is_pacman) {
		int points = 0;
		
		switch (item) {
		case MAP_DOTS:
			points = DOTS_POINTS;
			level.updateDots();
			break;
		case MAP_ENRG:
			points = ENRG_POINTS;
		default:
			break;
		}

		level.setHiScore(points);
		level.setPosition(pos_x, pos_y, MAP_NONE);
	}
}