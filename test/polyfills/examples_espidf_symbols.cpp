#include EXAMPLE_FILE

extern "C" void app_main() {
    setup();
    loop(); // We just want to have `loop` be ODR-used
}