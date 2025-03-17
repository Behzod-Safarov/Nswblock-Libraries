#ifndef NSW_BASE_MODULE_H
#define NSW_BASE_MODULE_H

#include <Arduino.h>

class NswBaseModule {
public:
    virtual void begin() = 0;  // Pure virtual function (must be implemented)
};

#endif
