/**
 * The SR04 (or SRF05) is an inexpensive ultrasonic sensor controllable over two
 * digital pins.
 *
 * For a more advanced solution (faster readings, not using `pulseIn`, non-blocking measurements)
 * please use the [NewPing library](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home).
 */
#pragma once

#include <stdint.h>

#include "../../../../runtime/Runtime.hpp"
#include "../../DistanceSensor.hpp"

#ifndef PLATFORM_AGNOSTIC_BUILD
#include "../../../../runtime/arduino_runtime/ArduinoRuntime.hpp"
extern ArduinoRuntime arduinoRuntime;
#endif

namespace smartcarlib
{
namespace constants
{
namespace sr04
{
const uint8_t kDefaultIterations       = 5;
const unsigned int kDefaultMaxDistance = 70;
} // namespace sr04
} // namespace constants
} // namespace smartcarlib

class SR04 : public DistanceSensor
{
public:
#ifndef PLATFORM_AGNOSTIC_BUILD
    /**
     * Constructs an SR04 ultrasonic sensor
     * @param triggerPin  The pin to produce the trigger signal
     * @param echoPin     The pin to receive the echo signal
     * @param maxDistance The maximum measurement distance in centimeters
     */
    SR04(uint8_t triggerPin,
         uint8_t echoPin,
         unsigned int maxDistance = smartcarlib::constants::sr04::kDefaultMaxDistance,
         Runtime& runtime         = arduinoRuntime);
#else
    SR04(uint8_t triggerPin, uint8_t echoPin, unsigned int maxDistance, Runtime& runtime);
#endif

    /* Check `DistanceSensor` interface for documentation */
    unsigned int getDistance() override;

    /* Check `DistanceSensor` interface for documentation */
    unsigned int getMedianDistance(uint8_t iterations
                                   = smartcarlib::constants::sr04::kDefaultIterations) override;

private:
    const uint8_t kTriggerPin;
    const uint8_t kEchoPin;
    const unsigned long kTimeout;
    Runtime& mRuntime;
    bool mAttached;

    void attach();
};
