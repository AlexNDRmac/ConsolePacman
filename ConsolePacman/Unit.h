#pragma once

#include "GameBoard.h"
#include "Moves.h"

class Unit {
private:
	Moves* way;
	GameBoard* level_ptr;
	int color;
protected:
	enum ways { up, down, left, right };
public:
	Unit(int pos_x, int pos_y, char avatar, int color);
	virtual ~Unit();

	int  getPositionX();
	int  getPositionY();
	char getAvatar();

	GameBoard* getLevel();

	virtual void initUnit(GameBoard* level);
	virtual void setPacman();
	virtual void setPositionX(int new_pos);
	virtual void setPositionY(int new_pos);

	virtual bool checkMoveAbility(int direction);
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();

	virtual void reset();

	virtual void draw();
};
