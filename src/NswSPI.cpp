#include "NswSPI.h"

void NswSPI::begin() {
    SPI.begin();
}

void NswSPI::transfer(uint8_t data) {
    SPI.transfer(data);
}
