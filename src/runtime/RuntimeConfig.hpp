/**
 * @file RuntimeConfig.hpp
 * @brief Various bits and pieces to handle the default runtime configuration
 * */

#pragma once

#define SMARTCAR_DEFAULT_RUNTIME EspidfRuntime
#define SMARTCAR_DEFAULT_RUNTIME_PATH "runtime/espidf_runtime/EspidfRuntime.hpp"
#define SMARTCAR_BUILD_ESPIDF_RUNTIME

#ifndef SMARTCAR_DEFAULT_RUNTIME
#define SMARTCAR_DEFAULT_RUNTIME ArduinoRuntime
#define SMARTCAR_DEFAULT_RUNTIME_PATH "runtime/arduino_runtime/ArduinoRuntime.hpp"
#define SMARTCAR_BUILD_ARDUINO_RUNTIME
#endif

#include SMARTCAR_DEFAULT_RUNTIME_PATH
using SmartcarDefaultRuntime = SMARTCAR_DEFAULT_RUNTIME;