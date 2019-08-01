#pragma once

class Timer {
private:
	clock_t start_time;
	double game_speed;
	double elapsed;
	double door_timer, ghost_timer;
public:
	Timer(double gameSpeed, double doorDelay);
	~Timer();

	void start();
	void update();
	void reset();
	void speedUp();

	bool ghostTime();
	bool doorTime();

	double count();
	double ghostTimer();
};