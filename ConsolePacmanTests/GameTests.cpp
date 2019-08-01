#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsolePacman/GameBoard.cpp"
#include "../ConsolePacman/Unit.cpp"
#include "../ConsolePacman/Moves.cpp"
#include "../ConsolePacman/Ghosts.cpp"
#include "../ConsolePacman/Pacman.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConsolePacmanTests 
{		
	TEST_CLASS(ConsolePacmanTests) {
	public:
		TEST_METHOD(GameBoard_getMapSymbol) {
			GameBoard* level = new GameBoard();

			level->loadLevel();
			level->setWindowSize(level->getLevelHeight(), level->getLevelWidth(), SCREEN_OFFSET);
			int width = level->getLevelWidth() - 1;
			int height = level->getLevelHeight() - 1;
			Assert::AreEqual('|', level->getPosition(0, 0));
			Assert::AreEqual('|', level->getPosition(width, height));
			Assert::AreEqual('H', level->getPosition(18, 0));
		}
		TEST_METHOD(GameBoard_getHiScore) {
		    GameBoard* level = new GameBoard();
			
			level->setHiScore(255);
			Assert::AreEqual(255, level->getHiScore());
		}
		TEST_METHOD(GameBoard_openDoors) {
			GameBoard* level = new GameBoard();
			
			level->loadLevel();
			level->openDoors();
			Assert::AreEqual(true, level->isDoorOpen());
			Assert::AreEqual(MAP_NONE, level->getPosition(DOORS_LFT, DOORS_ROW));
			Assert::AreEqual(MAP_NONE, level->getPosition(DOORS_RHT, DOORS_ROW));

		}
		TEST_METHOD(GameBoard_closeDoors) {
			GameBoard* level = new GameBoard();

			level->loadLevel();
			level->openDoors();
			level->closeDoors();
			Assert::AreEqual(false, level->isDoorOpen());
			Assert::AreEqual(MAP_DOOR, level->getPosition(DOORS_LFT, DOORS_ROW));
			Assert::AreEqual(MAP_DOOR, level->getPosition(DOORS_RHT, DOORS_ROW));

		}
		TEST_METHOD(GameBoard_updateLives) {
			GameBoard* level = new GameBoard();

			level->loadLevel();
			level->updateLives(2);
			Assert::AreEqual('2', level->getPosition(LIFE_COL, LIFE_ROW));
		}
		TEST_METHOD(GameBoard_updateHiScore) {
			GameBoard* level = new GameBoard();

			level->loadLevel();
			level->setHiScore(123456);
			level->updateHiScore();
			Assert::AreEqual('1', level->getPosition(SCORE_COL,   SCORE_ROW));
			Assert::AreEqual('2', level->getPosition(SCORE_COL+1, SCORE_ROW));
			Assert::AreEqual('3', level->getPosition(SCORE_COL+2, SCORE_ROW));
			Assert::AreEqual('4', level->getPosition(SCORE_COL+3, SCORE_ROW));
			Assert::AreEqual('5', level->getPosition(SCORE_COL+4, SCORE_ROW));
			Assert::AreEqual('6', level->getPosition(SCORE_COL+5, SCORE_ROW));
		}
		TEST_METHOD(Ghosts_moveLeft) {
			GameBoard* level = new GameBoard();
			Ghosts* ghost = new Ghosts(GHOST_POS_X - 3, GHOST_POS_Y, GHOST, red);
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			ghost->initUnit(level);
			prev_pos_x = ghost->getPositionX();
			prev_pos_y = ghost->getPositionY();
			ghost->moveLeft();

			Assert::AreEqual(prev_pos_x - 1, ghost->getPositionX());
			Assert::AreEqual(prev_pos_y,     ghost->getPositionY());
		}
		TEST_METHOD(Ghosts_moveRight) {
			GameBoard* level = new GameBoard();
			Ghosts* ghost = new Ghosts(GHOST_POS_X - 3, GHOST_POS_Y, GHOST, red);
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			ghost->initUnit(level);
			prev_pos_x = ghost->getPositionX();
			prev_pos_y = ghost->getPositionY();
			ghost->moveRight();

			Assert::AreEqual(prev_pos_x + 1, ghost->getPositionX());
			Assert::AreEqual(prev_pos_y,     ghost->getPositionY());
		}
		TEST_METHOD(Ghosts_moveUp) {
			GameBoard* level = new GameBoard();
			Ghosts* ghost = new Ghosts(GHOST_POS_X, GHOST_POS_Y, GHOST, red);
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			ghost->initUnit(level);
			prev_pos_x = ghost->getPositionX();
			prev_pos_y = ghost->getPositionY();
			ghost->moveUp();

			Assert::AreEqual(prev_pos_x,     ghost->getPositionX());
			Assert::AreEqual(prev_pos_y - 1, ghost->getPositionY());
		}
		TEST_METHOD(Ghosts_moveDown) {
			GameBoard* level = new GameBoard();
			Ghosts* ghost = new Ghosts(GHOST_POS_X, GHOST_POS_Y, GHOST, red);
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			ghost->initUnit(level);
			prev_pos_x = ghost->getPositionX();
			prev_pos_y = ghost->getPositionY();
			ghost->moveDown();

			Assert::AreEqual(prev_pos_x,	 ghost->getPositionX());
			Assert::AreEqual(prev_pos_y + 1, ghost->getPositionY());
		}
		TEST_METHOD(Ghosts_canPassWall) {
			GameBoard* level = new GameBoard();
			Ghosts* ghost = new Ghosts(GHOST_POS_X - 3, GHOST_POS_Y, GHOST, red);
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			ghost->initUnit(level);
			prev_pos_x = ghost->getPositionX();
			prev_pos_y = ghost->getPositionY();
			ghost->moveUp();
			ghost->moveDown();

			Assert::AreEqual(prev_pos_x, ghost->getPositionX());
			Assert::AreEqual(prev_pos_y, ghost->getPositionY());
		}
		TEST_METHOD(Pacman_moveAllDirections) {
			GameBoard* level = new GameBoard();
			Pacman* pacman = new Pacman();
			int prev_pos_x = 0;
			int prev_pos_y = 0;

			level->loadLevel();
			pacman->initUnit(level);
			prev_pos_x = pacman->getPositionX();
			prev_pos_y = pacman->getPositionY();
			pacman->moveUp();
			pacman->moveDown();

			Assert::AreEqual(prev_pos_x, pacman->getPositionX());
			Assert::AreEqual(prev_pos_y, pacman->getPositionY());

			pacman->moveLeft();
			Assert::AreEqual(prev_pos_x - 1, pacman->getPositionX());
			Assert::AreEqual(prev_pos_y,     pacman->getPositionY());

			pacman->moveRight();
			pacman->moveRight();
			Assert::AreEqual(prev_pos_x + 1, pacman->getPositionX());
			Assert::AreEqual(prev_pos_y,     pacman->getPositionY());
		}
		TEST_METHOD(Pacman_isCatched) {
			GameBoard* level = new GameBoard();
			Pacman* pacman = new Pacman();
			Ghosts* ghost = new Ghosts(PACMAN_POS_X + 1, PACMAN_POS_Y, GHOST, red);

			level->loadLevel();
			pacman->initUnit(level);
			ghost->initUnit(level);
			
			Assert::AreEqual(false, pacman->isCatched(*ghost));
			pacman->moveRight();
			Assert::AreEqual(true, pacman->isCatched(*ghost));
		}
		TEST_METHOD(Pacman_isWasted) {
			GameBoard* level = new GameBoard();
			Pacman* pacman = new Pacman();
			Ghosts* ghost = new Ghosts(PACMAN_POS_X + 1, PACMAN_POS_Y, GHOST, red);

			level->loadLevel();
			pacman->initUnit(level);
			ghost->initUnit(level);

			Assert::AreEqual(false, pacman->isWasted());
			pacman->moveRight();
			pacman->isCatched(*ghost);
			pacman->isCatched(*ghost);
			pacman->isCatched(*ghost);
			Assert::AreEqual(true, pacman->isWasted());
		}
	};
}