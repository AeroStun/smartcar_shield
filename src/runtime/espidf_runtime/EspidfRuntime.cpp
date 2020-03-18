#include "../RuntimeConfig.hpp"
#include "EspidfRuntime.hpp"
#ifdef SMARTCAR_BUILD_ESPIDF_RUNTIME

void EspidfRuntime::setPinDirection(uint8_t pin, uint8_t direction)
{
    (void)(pin, direction);
}

void EspidfRuntime::setPinState(uint8_t pin, uint8_t state)
{
    (void)(pin, state);
}

int EspidfRuntime::getPinState(uint8_t pin)
{
    (void)pin;
}

int EspidfRuntime::getAnalogPinState(uint8_t pin)
{
    (void)pin;
}

void EspidfRuntime::setPWM(uint8_t pin, int dutyCycle)
{
    (void)(pin, dutyCycle);
}

void EspidfRuntime::i2cInit()
{
}

void EspidfRuntime::i2cBeginTransmission(uint8_t address)
{
    (void)address;
}

size_t EspidfRuntime::i2cWrite(uint8_t value)
{
    (void)value;
    return 0;
}

uint8_t EspidfRuntime::i2cEndTransmission()
{
    return 0;
}

uint8_t EspidfRuntime::i2cRequestFrom(uint8_t address, uint8_t numberOfBytes)
{
    return Wire.requestFrom(address, numberOfBytes);
}

int EspidfRuntime::i2cAvailable()
{
    return 0;
}

int EspidfRuntime::i2cRead()
{
    return 0;
}

int8_t EspidfRuntime::pinToInterrupt(uint8_t pin)
{
    return digitalPinToInterrupt(pin);
}

unsigned long EspidfRuntime::currentTimeMillis()
{
    return 0;
}

unsigned long EspidfRuntime::currentTimeMicros()
{
    return 0;
}

void EspidfRuntime::delayMillis(unsigned long milliseconds)
{
    (void)milliseconds;
}

void EspidfRuntime::delayMicros(unsigned int microseconds)
{
    (void)microseconds;
}

unsigned long EspidfRuntime::getPulseDuration(uint8_t pin, uint8_t state, unsigned long timeout)
{
    (void)(pin, state, timeout);
    return 0;
}

void EspidfRuntime::setInterrupt(uint8_t pin, InterruptCallback callback, int mode)
{
    (void)(pin, callback, mode);
}

uint8_t EspidfRuntime::getLowState() const
{
    constexpr uint8_t low = 0x0;
    return low;
}

uint8_t EspidfRuntime::getHighState() const
{
    constexpr uint8_t high = 0x1;
    return high;
}

uint8_t EspidfRuntime::getOutputState() const
{
    constexpr uint8_t output = 0x01;
    return output;
}

uint8_t EspidfRuntime::getInputState() const
{
    constexpr uint8_t input = 0x02;
    return input;
}

int EspidfRuntime::getRisingEdgeMode() const
{
    constexpr int rising = 0x01;
    return rising;
}

#endif