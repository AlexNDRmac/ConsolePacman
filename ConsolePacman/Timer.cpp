#include "stdafx.h"
#include "Timer.h"

Timer::Timer(double gameSpeed, double doorDelay) {
	this->game_speed = gameSpeed / CLOCKS_PER_SEC;
	this->start_time = 0;
	this->elapsed = 0;
	this->door_timer = doorDelay;
	this->ghost_timer = 0;
}

Timer::~Timer() {}

void Timer::start() {
	start_time = clock();
}

void Timer::update() {
	elapsed = (double)(clock() - start_time) / CLOCKS_PER_SEC;
}

void Timer::reset() { 
	start_time = clock();
	elapsed = 0;
	ghost_timer = 0;
}

void Timer::speedUp() {
	if ( game_speed > 0.05 ) {
		game_speed -= (game_speed / 6);
	}
}

bool Timer::ghostTime() {
	if (elapsed > ghost_timer) {
		ghost_timer += game_speed;
		return true;
	}
	return false;
}

bool Timer::doorTime() {
	return (elapsed > door_timer);
}

double Timer::count() {
	return game_speed;
}
double Timer::ghostTimer() {
	return ghost_timer;
}