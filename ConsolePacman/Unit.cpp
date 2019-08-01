#include "stdafx.h"
#include "Unit.h"

Unit::Unit(int pos_x, int pos_y, char avatar, int color) {
	way = new Moves(pos_x, pos_y, avatar);
	level_ptr = nullptr;
	this->color = color;
}

Unit::~Unit() {
	delete way;
	level_ptr = nullptr;
	delete level_ptr;
}

GameBoard* Unit::getLevel() {
	return level_ptr;
}

void Unit::initUnit(GameBoard* level) {
	this->level_ptr = level;
}

int Unit::getPositionX() {
	return way->getPositionX();
}
int Unit::getPositionY() {
	return way->getPositionY();
}
char Unit::getAvatar() {
	return way->getAvatar();
}

void Unit::setPacman() {
	way->setPacman();
}

void Unit::setPositionX(int new_pos) {
	way->setPositionX(new_pos);
}
void Unit::setPositionY(int new_pos) {
	way->setPositionY(new_pos);
}

bool Unit::checkMoveAbility(int direction) {
	if ( way->isCanMove(*level_ptr, direction) ) {
		return true;
	}
	return false;
}

void Unit::moveUp() {
	way->saveCurrentPosition();
	way->moveUp(*level_ptr);
}

void Unit::moveDown() {
	way->saveCurrentPosition();
	way->moveDown(*level_ptr);
}

void Unit::moveLeft() {
	way->saveCurrentPosition();
	way->moveLeft(*level_ptr);
}

void Unit::moveRight() {
	way->saveCurrentPosition();
	way->moveRight(*level_ptr);
}

void Unit::reset() {
	way->saveCurrentPosition();
	way->reset();
}

void Unit::draw() {
	int prev_x = way->getPreviousX();
	int prev_y = way->getPreviousY();
	char prev_item = level_ptr->getPosition(prev_x, prev_y);

	level_ptr->drawUnit(prev_x, prev_y, prev_item, ITEM_COLOR);
	level_ptr->drawUnit(way->getPositionX(), way->getPositionY(), way->getAvatar(), color);
}