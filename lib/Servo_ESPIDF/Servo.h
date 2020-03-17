#pragma once

/**
 * \file Servo.h
 * \brief Partial polyfill for the Servo library on ESP-IDF
 * */

#include "runtime/RuntimeConfig.hpp"
#ifdef SMARTCAR_BUILD_ESPIDF_RUNTIME

struct Servo {
    void attach(int pin, int minpl, int maxpl) noexcept;
    /**
     * \param pulseWidth Pulse width to send to the servomotor, in microseconds.
     *     If outside of the range specified at attach() time, it is clamped to lie in that range.
     * */
    void writeMicroseconds(int pulseWidth) noexcept;
};

#endif