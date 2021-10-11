#include "motor.h"

Motor::Motor(){
    wiringPiSetup();
    pinMode(motorEnabler, OUTPUT);
    pinMode(motorDirection1, OUTPUT);
    pinMode(motorDirection2, OUTPUT);
    softPwmCreate(motorPwm, 50, 100);
    digitalWrite(motorEnabler, 1);
}

Motor::~Motor(){
    digitalWrite(motorEnabler, 0);
}

void Motor::move(int power){
	if(power>0){
		motorDirection(Direction::CC);
		motorPower(power);
	}else if (power<0){
		motorDirection(Direction::CCW);
		motorPower(-power);
	}else {
		motorDirection(Direction::STOPED);
		motorPower(100);
	}
}

void Motor::motorDirection(Direction direction){
    switch(direction){
		case Direction::CC:
        digitalWrite(motorDirection1, 0);
        digitalWrite(motorDirection2, 1);
		break;
		case Direction::CCW:
        digitalWrite(motorDirection1, 1);
        digitalWrite(motorDirection2, 0);
		break;
		case Direction::STOPED:
        digitalWrite(motorDirection1, 1);
        digitalWrite(motorDirection2, 1);
		break;
    }
}

void Motor::motorPower(int power){
	softPwmWrite(motorPwm, power);
}
