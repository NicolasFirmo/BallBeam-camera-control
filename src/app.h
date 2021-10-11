#pragma once
#include "camera.h"
#include "motor.h"

class App{
public:
	enum KeyCode{
		EXIT = 27
	};

	App(std::string windowName);

	void run();

	void controlMotor();

	void updateDeltaTime();
	int handleKey();

private:
	int deltaTime_ = 0;
	std::chrono::time_point<std::chrono::steady_clock> timePoint_;
	int key_;

	Camera camera_;
	Motor motor_;
};
