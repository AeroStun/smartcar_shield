extern "C" extern void setup();
extern "C" extern void loop();

extern "C" void app_main() {
    setup();
    loop(); // We just want to have `loop` be ODR-used
}