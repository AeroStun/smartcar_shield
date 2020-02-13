/**
 * \class DirectionalOdometer
 * A class to represent directional Odometers. These sensors typically expose three
 * signals lines, as opposed to two in the directionless counterparts. Depending
 * on the state of this third signal, the direction of movement can be inferred.
 */
#pragma once

#include "DirectionlessOdometer.hpp"

class DirectionalOdometer : public DirectionlessOdometer
{
public:
#ifdef SMARTCAR_BUILD_FOR_ARDUINO
    /**
     * Constructs an odometer that can measure distance, speed and direction
     * @param pin               The pin that receives the pulses
     * @param forwardWhenLowPin The pin that is set to LOW when moving forward
     * @param callback          The callback to be invoked when a pulse is received (see example)
     * @param pulsesPerMeter    The amount of odometer pulses that constitute a meter
     *
     * **Example:**
     * \code
     * unsigned short ODOMETER_PIN = 32;
     * unsigned short DIRECTION_PIN = 8;
     * unsigned short FORWARD_STATE = LOW;
     * unsigned long PULSES_PER_METER = 40;
     *
     * DirectionalOdometer odometer(ODOMETER_PIN,
     *                              DIRECTION_PIN,
     *                              []() { odometer.update(); },
     *                              FORWARD_STATE,
     *                              PULSES_PER_METER);
     * \endcode
     */
    DirectionalOdometer(uint8_t pin,
                        uint8_t forwardWhenLowPin,
                        InterruptCallback callback,
                        unsigned long pulsesPerMeter,
                        Runtime& runtime = arduinoRuntime);
#else
    DirectionalOdometer(uint8_t pin,
                        uint8_t forwardWhenLowPin,
                        InterruptCallback callback,
                        unsigned long pulsesPerMeter,
                        Runtime& runtime);
#endif

    /* Check `DirectionlessOdometer` for documentation */
    void reset() override;

    /* Check `DirectionlessOdometer` for documentation */
    void update() override;

    /* Check `Odometer` interface for documentation */
    long getDistance() override;

    /* Check `Odometer` interface for documentation */
    float getSpeed() override;

    /* Check `Odometer` interface for documentation */
    bool providesDirection() const override;

    /**
     * Get the direction of movement
     * @return `1` if travelling forward
     *         `-1` if travelling backward
     *
     * **Example:**
     * \code
     * unsigned short direction = odometer.getDirection();
     * \endcode
     */
    int8_t getDirection() const;

private:
    const uint8_t mDirectionPin;
    Runtime& mRuntime;
    const int kPinStateWhenForward;
    volatile unsigned long mNegativePulsesCounter{ 0 };
    volatile int mDirectionPinState;
};

/**
 * \example directionalOdometers.ino
 * An example on how to get the travelled distance from two DirectionalOdometer.
 */
