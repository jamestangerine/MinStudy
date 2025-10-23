#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
void b_shuffle (uint8_t* ptr, uint8_t length) {
    *ptr = 0;
    for (uint8_t i = 1; i < length; i++) {
        ptr++;
        *ptr = i;
    }
    uint8_t j = length-1;
    srand(time(NULL));
    uint8_t r = (uint8_t)(rand() % length);
    *(ptr-r) = j;
    *ptr = j-r;
    while (j > 2) {
        j--;
        ptr--;
        uint8_t* sec = ptr-(rand() % (j+1));
        uint8_t temp = *sec;
        *sec = *ptr;
        *ptr = temp;
    }
    if ((rand() & 1) == 0) {
        ptr--;
        uint8_t temp = *ptr;
        *ptr = *(ptr-1);
        *(ptr-1) = temp;
    }
}

EMSCRIPTEN_KEEPALIVE
void w_shuffle (uint16_t* ptr, uint16_t length) {
    *ptr = 0;
    for (uint16_t i = 1; i < length; i++) {
        ptr++;
        *ptr = i;
    }
    uint16_t j = length-1;
    srand(time(NULL));
    uint16_t r = (uint16_t)(rand() % length);
    *(ptr-r) = j;
    *ptr = j-r;
    while (j > 2) {
        j--;
        ptr--;
        uint16_t* sec = ptr-(rand() % (j+1));
        uint16_t temp = *sec;
        *sec = *ptr;
        *ptr = temp;
    }
    if ((rand() & 1) == 0) {
        ptr--;
        uint16_t temp = *ptr;
        *ptr = *(ptr-1);
        *(ptr-1) = temp;
    }
}