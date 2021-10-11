#pragma once

#include "wiringPi.h"
#include "softPwm.h"

class Motor{
public:
	enum class Direction{
		CC,
		CCW,
		STOPED
	};

	Motor();
	~Motor();

	void move(int power);

private:
	void motorDirection(Direction direction);
	void motorPower(int power);

private:
	static const int motorEnabler = 0;
	static const int motorDirection1 = 2;
	static const int motorDirection2 = 3;
	static const int motorPwm = 5;
};
