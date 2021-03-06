#include <Smartcar.h>

BrushedMotor leftMotor(smartcarlib::pins::v2::leftMotorPins);
BrushedMotor rightMotor(smartcarlib::pins::v2::rightMotorPins);
DifferentialControl control(leftMotor, rightMotor);

SimpleCar car(control);

void setup()
{
    // Move forward for 3 seconds
    car.setSpeed(50);
    delay(3000);
    // Start turning sharp left
    car.setSpeed(-90);
    delay(3000);
    // Straighten the car and move backward
    car.setAngle(0);
    car.setSpeed(-50);
    delay(3000);
    car.setSpeed(0);
}

void loop() {}
