#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
void shuffle (uint16_t* ptr, uint16_t length) {
    *ptr = 0;
    for (uint16_t i = 1; i < length; i++) {
        ptr++;
        *ptr = i;
    }
    uint16_t j = length-1;
    srand(time(NULL));
    uint16_t r = (uint16_t)(rand() % (j+1));
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