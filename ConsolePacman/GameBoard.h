#pragma once

using namespace std;

class GameBoard {
private:
	int hiScore;
	int dots_counter;
	int level_w;
	int level_h;
	int offset;
	bool doors;
	vector<string>* level_map = new vector<string>();
public:
	GameBoard();
	~GameBoard();

	int getHiScore();
	int getEatenDots();
	int getLevelHeight();
	int getLevelWidth();
	bool isDoorOpen();
	const char& getPosition(int pos_x, int pos_y);

	void setHiScore(int points);
	void updateDots();
	void setPosition(int pos_x, int pos_y, char unitSign);
	
	void setWindowSize(int x, int y, int offset);
	void loadLevel();
	void displayMessage(int x, int y, const string& message);
	void displayIntro();
	void gameOver();
	void openDoors();
	void closeDoors();
	
	void setColor(int color);
	void render();
	void drawUnit(int pos_x, int pos_y, const char& unitSign, int color);
	void updateLives(int lives);
	void updateHiScore();
};
