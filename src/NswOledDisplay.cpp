#include "NswOledDisplay.h"

// Full font array (ASCII 32 to 122)
const uint8_t NswOledDisplay::_font[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, // Space
    0x00, 0x00, 0x5F, 0x00, 0x00, // !
    0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x14, 0x7F, 0x14, 0x7F, 0x14, // #
    0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
    0x23, 0x13, 0x08, 0x64, 0x62, // %
    0x36, 0x49, 0x56, 0x20, 0x50, // &
    0x00, 0x07, 0x03, 0x00, 0x00, // '
    0x00, 0x1C, 0x22, 0x41, 0x00, // (
    0x00, 0x41, 0x22, 0x1C, 0x00, // )
    0x2A, 0x1C, 0x7F, 0x1C, 0x2A, // *
    0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x50, 0x30, 0x00, 0x00, // ,
    0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x32, 0x49, 0x79, 0x41, 0x3E, // @
    0x7E, 0x11, 0x11, 0x11, 0x7E, // A
    0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0x02, 0x04, 0x08, 0x10, 0x20, // \
    0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x04, 0x02, 0x01, 0x02, 0x04, // ^
    0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x03, 0x07, 0x00, 0x00, // `
    0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
    0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x20, 0x40, 0x44, 0x3D, 0x00, // j
    0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x7C, 0x14, 0x14, 0x14, 0x08, // p
    0x08, 0x14, 0x14, 0x18, 0x7C, // q
    0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
    0x44, 0x64, 0x54, 0x4C, 0x44  // z
};

const uint8_t NswOledDisplay::_fontWidth = 5;
const uint8_t NswOledDisplay::_fontHeight = 7;

NswOledDisplay::NswOledDisplay(Port port) {
    NswPort p(port);
    _sclPin = p.sclPin;
    _sdaPin = p.sdaPin;
    memset(_framebuffer, 0, sizeof(_framebuffer));
    _cursorX = 0;
    _cursorY = 0;
    _textSize = 1;
    _rotation = 0;
}

bool NswOledDisplay::begin() {
    Wire.begin();
    delay(100);

    const uint8_t initSeq[] = {
        0xAE,        // Display OFF
        0xD5, 0x80,  // Clock div
        0xA8, 0x3F,  // Multiplex (64-1 for 128x64)
        0xD3, 0x00,  // Offset
        0x40,        // Start line
        0x8D, 0x14,  // Charge pump ON
        0x20, 0x00,  // Horizontal addressing
        0xA1,        // Segment remap
        0xC8,        // COM scan direction
        0xDA, 0x12,  // COM pins config (0x12 for 128x64)
        0x81, 0x7F,  // Contrast mid
        0xD9, 0xF1,  // Pre-charge
        0xDB, 0x40,  // VCOMH
        0xA4,        // Entire display ON
        0xA6,        // Normal (not inverted)
        0xAF         // Display ON
    };
    sendCommands(initSeq, sizeof(initSeq));

    Wire.beginTransmission(OLED_I2C_ADDRESS);
    if (Wire.endTransmission() != 0) {
        return false;
    }

    clear();
    display();
    return true;
}

void NswOledDisplay::clear() {
    memset(_framebuffer, 0, sizeof(_framebuffer));
    _cursorX = 0;
    _cursorY = 0;
}

void NswOledDisplay::display() {
    sendCommand(0x21); sendCommand(0); sendCommand(127);  // Column 0-127
    sendCommand(0x22); sendCommand(0); sendCommand(7);    // Page 0-7
    for (uint16_t i = 0; i < sizeof(_framebuffer); i += 16) {
        uint16_t len = min(16, sizeof(_framebuffer) - i);
        sendData(&_framebuffer[i], len);
    }
}

void NswOledDisplay::setTextSize(uint8_t size) {
    _textSize = (size > 0) ? size : 1;
}

void NswOledDisplay::setCursor(uint8_t x, uint8_t y) {
    _cursorX = x;
    _cursorY = y;
}

void NswOledDisplay::print(const char* text) {
    while (*text) {
        drawChar(_cursorX, _cursorY, *text);
        _cursorX += (_fontWidth + 1) * _textSize;
        if (_cursorX >= OLED_WIDTH) {
            _cursorX = 0;
            _cursorY += _fontHeight * _textSize;
        }
        text++;
    }
}

void NswOledDisplay::print(int number) {
    char buf[12];
    itoa(number, buf, 10);
    print(buf);
}

void NswOledDisplay::print(float number, uint8_t decimalPlaces) {
    char buf[16];
    dtostrf(number, 0, decimalPlaces, buf);
    print(buf);
}

void NswOledDisplay::println(const char* text) {
    print(text);
    _cursorX = 0;
    _cursorY += _fontHeight * _textSize;
}

void NswOledDisplay::println(int number) {
    print(number);
    _cursorX = 0;
    _cursorY += _fontHeight * _textSize;
}

void NswOledDisplay::println(unsigned long number) {
    char buf[12];
    ultoa(number, buf, 10);
    print(buf);
    _cursorX = 0;
    _cursorY += _fontHeight * _textSize;
}

void NswOledDisplay::println(float number, uint8_t decimalPlaces) {
    print(number, decimalPlaces);
    _cursorX = 0;
    _cursorY += _fontHeight * _textSize;
}

void NswOledDisplay::drawPixel(uint8_t x, uint8_t y, bool color) {
    if (x >= OLED_WIDTH || y >= OLED_HEIGHT) return;
    transformCoordinates(x, y);
    uint16_t index = x + (y / 8) * OLED_WIDTH;
    uint8_t bit = 1 << (y % 8);
    if (color) _framebuffer[index] |= bit;
    else _framebuffer[index] &= ~bit;
}

void NswOledDisplay::drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, bool color) {
    int16_t dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int16_t dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int16_t err = dx + dy, e2;
    while (true) {
        drawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void NswOledDisplay::drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color) {
    drawLine(x, y, x + w - 1, y, color);
    drawLine(x, y + h - 1, x + w - 1, y + h - 1, color);
    drawLine(x, y, x, y + h - 1, color);
    drawLine(x + w - 1, y, x + w - 1, y + h - 1, color);
}

void NswOledDisplay::fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color) {
    for (uint8_t i = x; i < x + w; i++) {
        for (uint8_t j = y; j < y + h; j++) {
            drawPixel(i, j, color);
        }
    }
}

void NswOledDisplay::drawCircle(uint8_t x0, uint8_t y0, uint8_t r, bool color) {
    int16_t f = 1 - r, ddF_x = 1, ddF_y = -2 * r;
    int16_t x = 0, y = r;
    drawPixel(x0, y0 + r, color);
    drawPixel(x0, y0 - r, color);
    drawPixel(x0 + r, y0, color);
    drawPixel(x0 - r, y0, color);
    while (x < y) {
        if (f >= 0) { y--; ddF_y += 2; f += ddF_y; }
        x++; ddF_x += 2; f += ddF_x;
        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 - y, y0 - x, color);
    }
}

void NswOledDisplay::fillCircle(uint8_t x0, uint8_t y0, uint8_t r, bool color) {
    for (int16_t y = -r; y <= r; y++) {
        for (int16_t x = -r; x <= r; x++) {
            if (x * x + y * y <= r * r) {
                drawPixel(x0 + x, y0 + y, color);
            }
        }
    }
}

void NswOledDisplay::drawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color) {
    drawLine(x0, y0, x1, y1, color);
    drawLine(x1, y1, x2, y2, color);
    drawLine(x2, y2, x0, y0, color);
}

void NswOledDisplay::fillTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color) {
    int16_t a, b, y, last;
    int16_t tx0 = x0, ty0 = y0, tx1 = x1, ty1 = y1, tx2 = x2, ty2 = y2;

    if (ty0 > ty1) { swap(ty0, ty1); swap(tx0, tx1); }
    if (ty1 > ty2) { swap(ty1, ty2); swap(tx1, tx2); }
    if (ty0 > ty1) { swap(ty0, ty1); swap(tx0, tx1); }

    if (ty0 == ty2) {
        a = b = tx0;
        if (tx1 < a) a = tx1;
        else if (tx1 > b) b = tx1;
        if (tx2 < a) a = tx2;
        else if (tx2 > b) b = tx2;
        drawLine(a, ty0, b, ty0, color);
        return;
    }

    int16_t dx01 = tx1 - tx0, dy01 = ty1 - ty0;
    int16_t dx02 = tx2 - tx0, dy02 = ty2 - ty0;
    int16_t dx12 = tx2 - tx1, dy12 = ty2 - ty1;
    int32_t sa = 0, sb = 0;

    if (ty1 == ty2) last = ty1;
    else last = ty1 - 1;

    for (y = ty0; y <= last; y++) {
        a = tx0 + sa / dy01;
        b = tx0 + sb / dy02;
        sa += dx01;
        sb += dx02;
        if (a > b) swap(a, b);
        drawLine(a, y, b, y, color);
    }

    sa = dx12 * (y - ty1);
    sb = dx02 * (y - ty0);
    for (; y <= ty2; y++) {
        a = tx1 + sa / dy12;
        b = tx0 + sb / dy02;
        sa += dx12;
        sb += dx02;
        if (a > b) swap(a, b);
        drawLine(a, y, b, y, color);
    }
}

void NswOledDisplay::drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t w, uint8_t h, bool color) {
    for (uint8_t j = 0; j < h; j++) {
        for (uint8_t i = 0; i < w; i++) {
            if (pgm_read_byte(bitmap + j * w + i)) {
                drawPixel(x + i, y + j, color);
            }
        }
    }
}

void NswOledDisplay::invertDisplay(bool invert) {
    sendCommand(invert ? 0xA7 : 0xA6);
}

void NswOledDisplay::setContrast(uint8_t contrast) {
    sendCommand(0x81);
    sendCommand(contrast);
}

void NswOledDisplay::setRotation(uint8_t rotation) {
    _rotation = rotation % 4;
    uint8_t cmd1, cmd2;
    switch (_rotation) {
        case 0: cmd1 = 0xA0; cmd2 = 0xC0; break;
        case 1: cmd1 = 0xA1; cmd2 = 0xC0; break;
        case 2: cmd1 = 0xA1; cmd2 = 0xC8; break;
        case 3: cmd1 = 0xA0; cmd2 = 0xC8; break;
    }
    sendCommand(cmd1);
    sendCommand(cmd2);
}

void NswOledDisplay::sleep(bool enable) {
    sendCommand(enable ? 0xAE : 0xAF);
}

void NswOledDisplay::powerSave(bool enable) {
    sendCommand(0x8D);
    sendCommand(enable ? 0x10 : 0x14);
}

void NswOledDisplay::sendCommand(uint8_t cmd) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(0x00);
    Wire.write(cmd);
    Wire.endTransmission();
}

void NswOledDisplay::sendCommands(const uint8_t *cmds, uint8_t len) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(0x00);
    for (uint8_t i = 0; i < len; i++) {
        Wire.write(cmds[i]);
    }
    Wire.endTransmission();
}

void NswOledDisplay::sendData(const uint8_t* data, uint16_t len) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(0x40);
    for (uint16_t i = 0; i < len; i++) {
        Wire.write(data[i]);
    }
    Wire.endTransmission();
}

void NswOledDisplay::drawChar(uint8_t x, uint8_t y, char c, bool color) {
    if (c < 32 || c > 122) c = 32; // Limit to defined range (space to 'z')
    uint16_t charIndex = (c - 32) * _fontWidth; // Index into font array
    for (uint8_t i = 0; i < _fontWidth; i++) {
        uint8_t col = pgm_read_byte(&_font[charIndex + i]);
        for (uint8_t j = 0; j < _fontHeight; j++) {
            if (col & (1 << j)) {
                for (uint8_t sx = 0; sx < _textSize; sx++) {
                    for (uint8_t sy = 0; sy < _textSize; sy++) {
                        drawPixel(x + i * _textSize + sx, y + j * _textSize + sy, color);
                    }
                }
            }
        }
    }
}

void NswOledDisplay::transformCoordinates(uint8_t& x, uint8_t& y) {
    uint8_t temp;
    switch (_rotation) {
        case 0: break;
        case 1: temp = x; x = OLED_HEIGHT - y - 1; y = temp; break;
        case 2: x = OLED_WIDTH - x - 1; y = OLED_HEIGHT - y - 1; break;
        case 3: temp = x; x = y; y = OLED_WIDTH - temp - 1; break;
    }
}

void NswOledDisplay::swap(int16_t& a, int16_t& b) {
    int16_t t = a;
    a = b;
    b = t;
}