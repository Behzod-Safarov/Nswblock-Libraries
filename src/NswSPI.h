#ifndef NSW_SPI_H
#define NSW_SPI_H

#include <SPI.h>

class NswSPI {
public:
    static void begin();
    static void transfer(uint8_t data);
};

#endif
