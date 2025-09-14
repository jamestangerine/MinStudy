#include <stdint.h>
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
uint8_t add(uint8_t a, uint8_t b) {
    return a + b;
}