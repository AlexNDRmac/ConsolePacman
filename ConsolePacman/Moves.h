#pragma once

#include "GameBoard.h"

class Moves {
protected:
	int pos_x, pos_y;
	int prev_x, prev_y;
	int start_x, start_y;
	bool is_pacman = false;
	char avatar;

	enum ways { up, down, left, right };
public:
	Moves(int pos_x, int pos_y, char avatar);
	virtual ~Moves();

	virtual int getPositionX();
	virtual int getPositionY();
	virtual int getPreviousX();
	virtual int getPreviousY();

	virtual char getAvatar();

	virtual void setPacman();
	virtual void setPositionX(int new_pos);
	virtual void setPositionY(int new_pos);
	virtual void saveCurrentPosition();

	virtual void reset();

	virtual bool isCanMove(GameBoard& level, int direction);
	virtual void moveUp(GameBoard& level);
	virtual void moveDown(GameBoard& level);
	virtual void moveLeft(GameBoard& level);
	virtual void moveRight(GameBoard& level);
private:
	void eatItems(GameBoard& level, char item);
	bool moveUnit(GameBoard& level, int new_x, int new_y, int direction);
};
