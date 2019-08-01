#include "stdafx.h"
#include "GameBoard.h"

GameBoard::GameBoard() {
	this->hiScore = 0;
	this->dots_counter = 0;
	this->level_h = 0;
	this->level_w = 0;
	this->offset  = 0;
	this->doors   = false;
}

GameBoard::~GameBoard() {
	delete level_map;
}

int GameBoard::getHiScore() {
	return this->hiScore;
}

int GameBoard::getEatenDots() {
	return dots_counter;
}

int GameBoard::getLevelHeight() {
	return this->level_h;
}

int GameBoard::getLevelWidth() {
	return this->level_w;
}

bool GameBoard::isDoorOpen() {
	return this->doors;
}

const char& GameBoard::getPosition(int pos_x, int pos_y) {
	return (*level_map)[pos_y][pos_x];
}

void GameBoard::setHiScore(int points) {
	this->hiScore += points;
}

void GameBoard::updateDots() {
	this->dots_counter += 1;
}

void GameBoard::setPosition(int pos_x, int pos_y, char unitSign) {
	(*level_map)[pos_y][pos_x] = unitSign;
}

void GameBoard::setWindowSize(int x, int y, int offset) {
	HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	LPCTSTR title = L"The Pacman Game | C++ Code by AlexNDR";

	CONSOLE_SCREEN_BUFFER_INFO sb_info;
	CONSOLE_CURSOR_INFO cursor_info;

	short y_pos = y + offset;
	short x_pos = x + offset;
	SMALL_RECT windowSize = { 0, 0, y_pos, x_pos };
	cursor_info.bVisible = 0;
	cursor_info.dwSize = 1;

	SetConsoleWindowInfo(outHandle, 1, &windowSize);
	SetConsoleCursorInfo(outHandle, &cursor_info);

	GetConsoleScreenBufferInfo(outHandle, &sb_info);
	COORD bufferSize = {
		sb_info.srWindow.Right - sb_info.srWindow.Left + 1,
		sb_info.srWindow.Bottom - sb_info.srWindow.Top + 1 };

	SetConsoleScreenBufferSize(outHandle, bufferSize);

	SetConsoleTitle(title);
	this->offset = offset;
}

void GameBoard::loadLevel() {
	level_map->push_back("|                 High Score                 |");
	level_map->push_back("|--------------------------------------------|");
	level_map->push_back("|------------------ 000000 ------------------|");
	level_map->push_back("##############################################");
	level_map->push_back("##. . . . . . . . . .####. . . . . . . . . .##");
	level_map->push_back("##.#######.#########.####.#########.#######.##");
	level_map->push_back("##*#######.#########.####.#########.#######*##");
	level_map->push_back("##.#######.#########.####.#########.#######.##");
	level_map->push_back("##. . . . . . . . . ...... . . . . . . . . .##");
	level_map->push_back("##.#######.####.##############.####.#######.##");
	level_map->push_back("##.#######.####.##############.####.#######.##");
	level_map->push_back("##. . . . .####. . . #### . . .####. . . . .##");
	level_map->push_back("##########.######### #### #########.##########");
	level_map->push_back("        ##.######### #### #########.##        ");
	level_map->push_back("        ##.####                ####.##        ");
	level_map->push_back("        ##.#### #####====##### ####.##        ");
	level_map->push_back("##########.#### ##          ## ####.##########");
	level_map->push_back("          . . . ##          ## . . .          ");
	level_map->push_back("##########.#### ##          ## ####.##########");
	level_map->push_back("        ##.#### ############## ####.##        ");
	level_map->push_back("        ##.####                ####.##        ");
	level_map->push_back("        ##.#### ############## ####.##        ");
	level_map->push_back("##########.#### ############## ####.##########");
	level_map->push_back("##. . . . . . . . . .####. . . . . . . . . .##");
	level_map->push_back("##.#######.#########.####.#########.#######.##");
	level_map->push_back("##.#######.#########.####.#########.#######.##");
	level_map->push_back("##*...####. . . . . ..  .. . . . . .####...*##");
	level_map->push_back("#####.####.####.##############.####.####.#####");
	level_map->push_back("#####.####.####.##############.####.####.#####");
	level_map->push_back("##. . . . .####. . . #### . . .####. . . . .##");
	level_map->push_back("##.#################.####.#################.##");
	level_map->push_back("##.#################.####.#################.##");
	level_map->push_back("##. . .................................. . .##");
	level_map->push_back("##############################################");
	level_map->push_back("|  Life = 3                                  |");
	level_map->push_back("|--------------------------------------------|");
	
	this->level_h = level_map->size();
	this->level_w = (*level_map)[0].size();
}

void GameBoard::displayMessage(int x, int y, const string& message) {
	short x_pos = x + offset;
	short y_pos = y + offset;
	COORD point = { y_pos, x_pos };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
	cout << message;
}

void GameBoard::displayIntro() {
	int row = this->level_h / 3;
	int col = this->level_w / 4;
	
	setColor(cyan);
	
	displayMessage(row++, col, "Loading Game...");
	displayMessage(row++, col, "");
	displayMessage(row++, col, "Game Controls (Arrows):");
	displayMessage(row++, col, "  - move up");
	displayMessage(row++, col, "  - move down");
	displayMessage(row++, col, "  - move left");
	displayMessage(row++, col, "  - move right");
	displayMessage(row++, col, "");
	displayMessage(row++, col, "");

	system("pause");
}

void GameBoard::gameOver() {
	int row = this->level_h / 3;
	int col = this->level_w / 4;
	
	string gameResult, gameScore;
	std::ostringstream strs;

	if (dots_counter != DOTS_HISCORE) {
		gameResult = "Sorry, You died :(";
	} else {
		gameResult = "Congratulations!!! You Win!!";
	}

	strs << "You have collected " << dots_counter << " points!";
	gameScore = strs.str();

	system("cls");

	setColor(cyan);
	displayMessage(row++, col, gameResult);
	displayMessage(row++, col, gameScore);
	displayMessage(row++, col, "");
	displayMessage(row++, col, "");

	Sleep(3000);
	system("pause");
}

void GameBoard::openDoors() {
	for (int i = DOORS_LFT; i <= DOORS_RHT; i++) {
		setPosition(i, DOORS_ROW, MAP_NONE);
		drawUnit(i, DOORS_ROW, MAP_NONE, ITEM_COLOR);
	}

	doors = !doors;
}

void GameBoard::closeDoors() {
	for (int i = DOORS_LFT; i <= DOORS_RHT; i++) {
		setPosition(i, DOORS_ROW, MAP_DOOR);
		drawUnit(i, DOORS_ROW, MAP_DOOR, DOOR_COLOR);
	}

	doors = !doors;
}

void GameBoard::setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameBoard::render() {
	system("cls");
	
	for (int row = 0; row < this->level_h; row++) {
		for (int col = 0; col < this->level_w; col++) {
			switch ((*level_map)[row][col]) {
			case MAP_WALL:
				drawUnit(col, row, RENDER_WALL, WALL_COLOR);
				break;
			case MAP_DOTS:
				drawUnit(col, row, RENDER_DOTS, ITEM_COLOR);
				break;
			case MAP_ENRG:
				drawUnit(col, row, RENDER_ENRG, ENRG_COLOR);
				break;
			default:
				drawUnit(col, row, (*level_map)[row][col], ITEM_COLOR);
				break;
			}
		}
	}
}

void GameBoard::drawUnit(int pos_x, int pos_y, const char& unitSign, int color) {
	short x_pos = pos_x + offset;
	short y_pos = pos_y + offset;
	COORD point = { x_pos, y_pos };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);

	char renderUnitSign = unitSign;
	switch (unitSign) {
	case MAP_DOTS:
		renderUnitSign = RENDER_DOTS;
		setColor(ITEM_COLOR);
		break;
	case MAP_ENRG:
		renderUnitSign = RENDER_ENRG;
		setColor(ENRG_COLOR);
		break;
	default:
		setColor(color);
		break;
	}

	cout << renderUnitSign;
}

void GameBoard::updateLives(int lives) {
	string buffer = (*level_map)[LIFE_ROW];
	char update[2] = { "\0" };

	sprintf_s(update, "%d", lives);
	buffer.replace(LIFE_COL, 1, update);
	(*level_map)[LIFE_ROW] = buffer;

	setColor(ITEM_COLOR);
	displayMessage(LIFE_ROW, LIFE_COL, update);
}

void GameBoard::updateHiScore() {
	char score[7] = { "\0" };
	sprintf_s(score, "%06d", hiScore);
	
	string buffer = (*level_map)[SCORE_ROW];
	buffer.replace(SCORE_COL, 6 , score);
	(*level_map)[SCORE_ROW] = buffer;

	setColor(ITEM_COLOR);
	displayMessage(SCORE_ROW, SCORE_COL, score);
}
