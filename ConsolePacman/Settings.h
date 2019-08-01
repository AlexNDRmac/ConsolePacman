#pragma once
#include "stdafx.h"

enum EGA_Colors {
	black,
	darkBlue,
	darkGreen,
	darkCyan,
	darkRed,
	darkMagenta,
	darkYellow,
	lightGray,
	darkGray,
	blue,
	green,
	cyan,
	red,
	magenta,
	yellow,
	white
};

/**
* Keyboard Input
*/
const int KEY_UP    = 0x48;
const int KEY_DOWN  = 0x50;
const int KEY_LEFT  = 0x4b;
const int KEY_RIGHT = 0x4d;

/**
* Level Setting
*
*/
const int SCREEN_OFFSET = 1;
const int DOTS_HISCORE  = 240;
const double DOOR_DELAY = 10.0;
const double GAME_SPEED = 250;

/**
* Mapping Level`s graphics to Named Variable
*
*/
const char RENDER_WALL = (char)177;
const char RENDER_DOTS = (char)249;
const char RENDER_ENRG = (char)4;

const char MAP_WALL = '#';
const char MAP_DOTS = '.';
const char MAP_NONE = ' ';
const char MAP_ENRG = '*';
const char MAP_DOOR = '=';
const char GHOST    = (char)1;
const char PACMAN   = 'C';

const int DOOR_COLOR = white;
const int WALL_COLOR = darkGreen;
const int ITEM_COLOR = lightGray;
const int ENRG_COLOR = cyan;

/**
* Level Items points
*
*/
const int DOTS_POINTS = 10;
const int ENRG_POINTS = 50;

/**
* Unit`s Starting Position
* Object`s coordinates
*/
const int GHOST_POS_X  = 22;
const int GHOST_POS_Y  = 17;
const int PACMAN_POS_X = 22;
const int PACMAN_POS_Y = 26;

const int DOORS_ROW    = 15;
const int DOORS_LFT    = 21;
const int DOORS_RHT    = 24;
const int LIFE_ROW     = 34;
const int LIFE_COL     = 10;
const int SCORE_ROW    = 2;
const int SCORE_COL    = 20;
const int TUNNEL_ROW   = 17;
