#include "stdafx.h"
#include "Pacman.h"

Pacman::Pacman() : Unit(PACMAN_POS_X, PACMAN_POS_Y, PACMAN, yellow) {
	live = 3;
	direction = right;
	waste = false;
	Unit::setPacman();
}

Pacman::~Pacman() {}

void Pacman::chooseWay(int key) {
	int new_way = direction;
	
	switch (key) {
	case KEY_UP:
		new_way = up;
		break;
	case KEY_DOWN:
		new_way = down;
		break;
	case KEY_LEFT:
		new_way = left;
		break;
	case KEY_RIGHT:
		new_way = right;
		break;
	default:
		break;
	}

	if (Unit::checkMoveAbility(new_way)) {
		direction = new_way;
	}

}

void Pacman::movePacman() {

	while (Unit::checkMoveAbility(direction) != true) {
		direction = rand() % 4;
	}

	switch (direction) {
	case up:
		moveUp();
		break;
	case down:
		moveDown();
		break;
	case left:
		moveLeft();
		break;
	case right:
		moveRight();
		break;
	}
}

void Pacman::moveUp() {
	Unit::moveUp();
	Unit::getLevel()->updateHiScore();
}
void Pacman::moveDown() {
	Unit::moveDown();
	Unit::getLevel()->updateHiScore();
}
void Pacman::moveLeft() {
	Unit::moveLeft();
	Unit::getLevel()->updateHiScore();
}
void Pacman::moveRight() {
	Unit::moveRight();
	Unit::getLevel()->updateHiScore();
}

void Pacman::reset() {
	Unit::reset();
	Unit::getLevel()->updateLives(this->live);
}

bool Pacman::isWasted() {
	if (live == 0) {
		waste = true;
	}
	return waste;
}

bool Pacman::isCatched(Ghosts& ghost) {
	if (getPositionX() == ghost.getPositionX() && getPositionY() == ghost.getPositionY()) {
		live -= 1;
		return true;
	}
	return false;
}
