/*
*	Car.cpp
*/
#include "AndroidCar.h"
const int IDLE_SPEED = 1500;
const int MAX_FRONT_SPEED = 1700; //can go to 1800
const int MAX_BACK_SPEED = 1200; //can go to 1200
const int STRAIGHT_WHEELS = 90;
const int MAX_RIGHT_DEGREES = 115;
const int MAX_LEFT_DEGREES = 65;

Car::Car(unsigned short steeringWheelPin, unsigned short escPin){
	setSteeringWheelPin(steeringWheelPin);
	setESCPin(escPin);
}

void Car::begin(){
	motor.attach(_escPin);
	steeringWheel.attach(_steeringWheelPin);
	setSpeed(0);
	setSteeringWheel(0);
}

void Car::setSteeringWheelPin(int steeringWheelPin){
	_steeringWheelPin = steeringWheelPin;
}

void Car::setESCPin(int escPin){
	_escPin = escPin;
}

void Car::setSpeed(int speed){
	_speed = constrain(IDLE_SPEED + speed, MAX_BACK_SPEED, MAX_FRONT_SPEED);
	motor.write(_speed);
}

void Car::setSteeringWheel(int degrees){
	_angle = constrain(STRAIGHT_WHEELS + degrees, MAX_LEFT_DEGREES, MAX_RIGHT_DEGREES);
	steeringWheel.write(_angle);
}

int Car::getSpeed(){
	return _speed;
}

int Car::getAngle(){
	return _angle;
}
