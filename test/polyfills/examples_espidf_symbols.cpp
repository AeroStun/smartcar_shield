extern void setup();
extern void loop();
extern "C" void app_main() {
    setup();
    loop(); // We just want to have `loop` be ODR-used
}