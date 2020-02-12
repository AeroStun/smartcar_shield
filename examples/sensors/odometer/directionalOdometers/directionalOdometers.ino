#include <Smartcar.h>

const unsigned short LEFT_ODOMETER_PIN     = 35;
const unsigned short LEFT_DIRECTION_PIN    = 34;
const unsigned short RIGHT_ODOMETER_PIN    = 36;
const unsigned short RIGHT_DIRECTION_PIN   = 39;
const unsigned short FORWARD_STATE         = LOW;
const unsigned long LEFT_PULSES_PER_METER  = 600;
const unsigned long RIGHT_PULSES_PER_METER = 740;

DirectionalOdometer leftOdometer(
    LEFT_ODOMETER_PIN,
    []() { leftOdometer.update(); },
    LEFT_DIRECTION_PIN,
    FORWARD_STATE,
    LEFT_PULSES_PER_METER);
DirectionalOdometer rightOdometer(
    RIGHT_ODOMETER_PIN,
    []() { rightOdometer.update(); },
    RIGHT_DIRECTION_PIN,
    FORWARD_STATE,
    RIGHT_PULSES_PER_METER);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(leftOdometer.getDistance());
    Serial.print("\t\t");
    Serial.println(rightOdometer.getDistance());
}
