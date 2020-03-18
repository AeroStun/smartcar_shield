extern "C"  {
    extern void setup(void);
    extern void loop(void);
}

extern "C" void app_main() {
    ::setup();
    ::loop(); // We just want to have `loop` be ODR-used
}