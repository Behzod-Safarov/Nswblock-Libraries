

 #include "NswLEDMatrix.h"
 #include <Arduino.h>
 
 // Font data from MeLEDMatrixData.h
 const LED_Matrix_Font_6x8_TypeDef Character_font_6x8[] PROGMEM =
 {
     {' ',  0x00,0x00,0x00,0x00,0x00,0x00},
     {'0',  0x00,0x7C,0x82,0x82,0x7C,0x00},
     {'1',  0x00,0x42,0xFE,0x02,0x00,0x00},
     {'2',  0x00,0x46,0x8A,0x92,0x62,0x00},
     {'3',  0x00,0x44,0x92,0x92,0x6C,0x00},
     {'4',  0x00,0x1C,0x64,0xFE,0x04,0x00},
     {'5',  0x00,0xF2,0x92,0x92,0x8C,0x00},
     {'6',  0x00,0x7C,0x92,0x92,0x4C,0x00},
     {'7',  0x00,0xC0,0x8E,0x90,0xE0,0x00},
     {'8',  0x00,0x6C,0x92,0x92,0x6C,0x00},
     {'9',  0x00,0x64,0x92,0x92,0x7C,0x00},
     {'a',  0x00,0x04,0x2A,0x2A,0x1E,0x00},
     {'b',  0x00,0xFE,0x12,0x12,0x0C,0x00},
     {'c',  0x00,0x0C,0x12,0x12,0x12,0x00},
     {'d',  0x00,0x0C,0x12,0x12,0xFE,0x00},
     {'e',  0x00,0x1C,0x2A,0x2A,0x18,0x00},
     {'f',  0x00,0x10,0x3E,0x50,0x50,0x00},
     {'g',  0x00,0x08,0x15,0x15,0x1E,0x00},
     {'h',  0x00,0xFE,0x10,0x1E,0x00,0x00},
     {'i',  0x00,0x00,0x2E,0x00,0x00,0x00},
     {'j',  0x00,0x02,0x01,0x2E,0x00,0x00},
     {'k',  0x00,0xFE,0x08,0x14,0x12,0x00},
     {'l',  0x00,0x00,0xFE,0x02,0x00,0x00},
     {'m',  0x00,0x1E,0x10,0x0E,0x10,0x0E},
     {'n',  0x00,0x1E,0x10,0x10,0x0E,0x00},
     {'o',  0x00,0x0C,0x12,0x12,0x0C,0x00},
     {'p',  0x00,0x1F,0x12,0x12,0x0C,0x00},
     {'q',  0x00,0x0C,0x12,0x12,0x1F,0x00},
     {'r',  0x00,0x1E,0x08,0x10,0x10,0x00},
     {'s',  0x00,0x12,0x29,0x25,0x12,0x00},
     {'t',  0x00,0x10,0x3E,0x12,0x00,0x00},
     {'u',  0x00,0x1C,0x02,0x02,0x1E,0x00},
     {'v',  0x18,0x04,0x02,0x04,0x18,0x00},
     {'w',  0x18,0x06,0x1C,0x06,0x18,0x00},
     {'x',  0x00,0x12,0x0C,0x0C,0x12,0x00},
     {'y',  0x00,0x18,0x05,0x05,0x1E,0x00},
     {'z',  0x00,0x12,0x16,0x1A,0x12,0x00},
     {'A',  0x00,0x7E,0x88,0x88,0x7E,0x00},
     {'B',  0x00,0xFE,0x92,0x92,0x6C,0x00},
     {'C',  0x00,0x7C,0x82,0x82,0x44,0x00},
     {'D',  0x00,0xFE,0x82,0x82,0x7C,0x00},
     {'E',  0x00,0xFE,0x92,0x92,0x82,0x00},
     {'F',  0x00,0xFE,0x90,0x90,0x80,0x00},
     {'G',  0x00,0x7C,0x82,0x92,0x5C,0x00},
     {'H',  0x00,0xFE,0x10,0x10,0xFE,0x00},
     {'I',  0x00,0x82,0xFE,0x82,0x00,0x00},
     {'J',  0x00,0x0C,0x02,0x02,0xFC,0x00},
     {'K',  0x00,0xFE,0x10,0x28,0xC6,0x00},
     {'L',  0x00,0xFE,0x02,0x02,0x02,0x00},
     {'M',  0x00,0xFE,0x40,0x30,0x40,0xFE},
     {'N',  0x00,0xFE,0x40,0x30,0x08,0xFE},
     {'O',  0x00,0x7C,0x82,0x82,0x82,0x7C},
     {'P',  0x00,0xFE,0x90,0x90,0x60,0x00},
     {'Q',  0x00,0x7C,0x82,0x8A,0x84,0x7A},
     {'R',  0x00,0xFE,0x98,0x94,0x62,0x00},
     {'S',  0x00,0x64,0x92,0x92,0x4C,0x00},
     {'T',  0x00,0x80,0xFE,0x80,0x80,0x00},
     {'U',  0x00,0xFC,0x02,0x02,0xFC,0x00},
     {'V',  0x00,0xF0,0x0C,0x02,0x0C,0xF0},
     {'W',  0x00,0xFE,0x04,0x38,0x04,0xFE},
     {'X',  0x00,0xC6,0x38,0x38,0xC6,0x00},
     {'Y',  0xC0,0x20,0x1E,0x20,0xC0,0x00},
     {'Z',  0x00,0x86,0x9A,0xB2,0xC2,0x00},
     {',',  0x00,0x01,0x0E,0x0C,0x00,0x00},
     {'.',  0x00,0x00,0x06,0x06,0x00,0x00},
     {'%',  0x72,0x54,0x78,0x1E,0x2A,0x4E},
     {'!',  0x00,0x00,0x7A,0x00,0x00,0x00},
     {'?',  0x00,0x20,0x4A,0x30,0x00,0x00},
     {'-',  0x00,0x10,0x10,0x10,0x10,0x00},
     {'+',  0x08,0x08,0x3E,0x08,0x08,0x00},
     {'/',  0x00,0x02,0x0C,0x30,0x40,0x00},
     {'*',  0x22,0x14,0x08,0x14,0x22,0x00},
     {':',  0x00,0x00,0x14,0x00,0x00,0x00},
     {'"',  0x00,0xC0,0x00,0xC0,0x00,0x00},
     {'#',  0x28,0xFE,0x28,0xFE,0x28,0x00},
     {'(',  0x00,0x00,0x7C,0x82,0x00,0x00},
     {')',  0x00,0x00,0x82,0x7C,0x00,0x00},
     {';',  0x00,0x02,0x24,0x00,0x00,0x00},
     {'~',  0x00,0x40,0x80,0x40,0x80,0x00},
     {'=',  0x00,0x28,0x28,0x28,0x28,0x00},
     {'|',  0x00,0x00,0xFE,0x00,0x00,0x00},
     {'>',  0x00,0x82,0x44,0x28,0x10,0x00},
     {'<',  0x00,0x10,0x28,0x44,0x82,0x00},
     {'@',  0x00,0x00,0x00,0x00,0x00,0x00}  // End mark of Character_font_6x8
 };
 
 const LED_Matrix_Clock_Number_Font_3x8_TypeDef Clock_Number_font_3x8[] PROGMEM =
 {
     {0x7C,0x44,0x7C},  // 0
     {0x00,0x7C,0x00},  // 1
     {0x5C,0x54,0x74},  // 2
     {0x54,0x54,0x7C},  // 3
     {0x70,0x10,0x7C},  // 4
     {0x74,0x54,0x5C},  // 5
     {0x7C,0x54,0x5C},  // 6
     {0x40,0x40,0x7C},  // 7
     {0x7C,0x54,0x7C},  // 8
     {0x74,0x54,0x7C},  // 9
     {0x00,0x04,0x00},  // .
     {0x20,0x20,0x20},  // -
     {0x00,0x00,0x00}   // (space)
 };
 
 NswLEDMatrix::NswLEDMatrix() : port(new NswPort(PORT_1))
 {
     u8_SCKPin = port->pin1;
     u8_DINPin = port->pin2;
 
     pinMode(u8_SCKPin, OUTPUT);
     pinMode(u8_DINPin, OUTPUT);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 
     writeByte(Mode_Address_Auto_Add_1);
     setBrightness(Brightness_5);
     clearScreen();
 }
 
 NswLEDMatrix::NswLEDMatrix(Port port) : port(new NswPort(port))
 {
     u8_SCKPin = this->port->pin1;
     u8_DINPin = this->port->pin2;
 
     pinMode(u8_SCKPin, OUTPUT);
     pinMode(u8_DINPin, OUTPUT);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 
     writeByte(Mode_Address_Auto_Add_1);
     setBrightness(Brightness_5);
     clearScreen();
 }
 
 NswLEDMatrix::NswLEDMatrix(uint8_t SCK_Pin, uint8_t DIN_Pin) : port(nullptr)
 {
     u8_SCKPin = SCK_Pin;
     u8_DINPin = DIN_Pin;
 
     pinMode(u8_SCKPin, OUTPUT);
     pinMode(u8_DINPin, OUTPUT);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 
     writeByte(Mode_Address_Auto_Add_1);
     setBrightness(Brightness_5);
     clearScreen();
 }
 
 void NswLEDMatrix::reset(Port port)
 {
     if(this->port) delete this->port;
     this->port = new NswPort(port);
     u8_SCKPin = this->port->pin1;
     u8_DINPin = this->port->pin2;
 
     pinMode(u8_SCKPin, OUTPUT);
     pinMode(u8_DINPin, OUTPUT);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 
     writeByte(Mode_Address_Auto_Add_1);
     setBrightness(Brightness_5);
     clearScreen();
 }
 
 void NswLEDMatrix::writeByte(uint8_t data)
 {
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, LOW);
 
     for(char i = 0; i < 8; i++)
     {
         digitalWrite(u8_SCKPin, LOW);
         digitalWrite(u8_DINPin, (data & 0x01));
         digitalWrite(u8_SCKPin, HIGH);
         data = data >> 1;
     }
 
     digitalWrite(u8_SCKPin, LOW);
     digitalWrite(u8_DINPin, LOW);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 }
 
 void NswLEDMatrix::writeBytesToAddress(uint8_t Address, const uint8_t *P_data, uint8_t count_of_data)
 {
     if(Address > 15 || count_of_data == 0)
         return;
 
     Address = ADDRESS(Address);
 
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, LOW);
 
     for(char i = 0; i < 8; i++)
     {
         digitalWrite(u8_SCKPin, LOW);
         digitalWrite(u8_DINPin, (Address & 0x01));
         digitalWrite(u8_SCKPin, HIGH);
         Address = Address >> 1;
     }
 
     for(uint8_t k = 0; k < count_of_data; k++)
     {
         uint8_t T_data = *(P_data + k);
         for(char i = 0; i < 8; i++)
         {
             digitalWrite(u8_SCKPin, LOW);
             digitalWrite(u8_DINPin, (T_data & 0x80));
             digitalWrite(u8_SCKPin, HIGH);
             T_data = T_data << 1;
         }
     }
 
     digitalWrite(u8_SCKPin, LOW);
     digitalWrite(u8_DINPin, LOW);
     digitalWrite(u8_SCKPin, HIGH);
     digitalWrite(u8_DINPin, HIGH);
 }
 
 void NswLEDMatrix::clearScreen()
 {
     for(uint8_t i = 0; i < LED_BUFFER_SIZE; i++)
     {
         u8_Display_Buffer[i] = 0x00;
     }
 
     b_Color_Index = 1;
     b_Draw_Str_Flag = 0;
 
     writeBytesToAddress(0, u8_Display_Buffer, LED_BUFFER_SIZE);
 }
 
 void NswLEDMatrix::setBrightness(uint8_t Bright)
 {
     if((uint8_t)Bright > 8)
     {
         Bright = Brightness_8;
     }
 
     if((uint8_t)Bright != 0)
     {
         Bright = (LED_Matrix_Brightness_TypeDef)((uint8_t)(Bright-1) | 0x08);
     }
     writeByte(0x80 | (uint8_t)Bright);
 }
 
 void NswLEDMatrix::setColorIndex(bool Color_Number)
 {
     b_Color_Index = Color_Number;
 }
 
 void NswLEDMatrix::drawBitmap(int8_t x, int8_t y, uint8_t Bitmap_Width, uint8_t *Bitmap)
 {
     if(x > 15 || y > 7 || Bitmap_Width == 0)
         return;
 
     if(b_Color_Index == 1)
     {
         for(uint8_t k = 0; k < Bitmap_Width; k++)
         {
             if(x + k >= 0)
             {
                 u8_Display_Buffer[x+k] = (u8_Display_Buffer[x+k] & (0xff << (8-y))) | 
                                        (y > 0 ? (Bitmap[k] >> y) : (Bitmap[k] << (-y)));
             }
         }
     }
     else if(b_Color_Index == 0)
     {
         for(uint8_t k = 0; k < Bitmap_Width; k++)
         {
             if(x + k >= 0)
             {
                 u8_Display_Buffer[x+k] = (u8_Display_Buffer[x+k] & (0xff << (8-y))) | 
                                        (y > 0 ? (~Bitmap[k] >> y) : (~Bitmap[k] << (-y)));
             }
         }
     }
 
     writeBytesToAddress(0, u8_Display_Buffer, LED_BUFFER_SIZE);
 }
 
 void NswLEDMatrix::drawStr(int16_t X_position, int8_t Y_position, const char *str)
 {
     b_Draw_Str_Flag = 1;
 
     for(i16_Number_of_Character_of_Str = 0; str[i16_Number_of_Character_of_Str] != '\0'; i16_Number_of_Character_of_Str++)
     {
         if(i16_Number_of_Character_of_Str < STRING_DISPLAY_BUFFER_SIZE - 1)
         {
             i8_Str_Display_Buffer[i16_Number_of_Character_of_Str] = str[i16_Number_of_Character_of_Str];
         }
         else
         {
             break;
         }
     }
     i8_Str_Display_Buffer[i16_Number_of_Character_of_Str] = '\0';
 
     if(X_position < -(i16_Number_of_Character_of_Str * 6))
     {
         X_position = -(i16_Number_of_Character_of_Str * 6);
     }
     else if(X_position > 16)
     {
         X_position = 16;
     }
     i16_Str_Display_X_Position = X_position;
 
     if(Y_position < -1)
     {
         Y_position = -1;
     }
     else if(Y_position > 15)
     {
         Y_position = 15;
     }
     i8_Str_Display_Y_Position = Y_position;
 
     showStr();
 }
 
 void NswLEDMatrix::showStr()
 {
     uint8_t display_buffer_label = 0;
 
     if(i16_Str_Display_X_Position > 0)
     {
         for(display_buffer_label = 0; display_buffer_label < i16_Str_Display_X_Position && display_buffer_label < LED_BUFFER_SIZE; display_buffer_label++)
         {
             u8_Display_Buffer[display_buffer_label] = 0x00;
         }
 
         if(display_buffer_label < LED_BUFFER_SIZE)
         {
             uint8_t num;
 
             for(uint8_t k = 0; display_buffer_label < LED_BUFFER_SIZE && k < i16_Number_of_Character_of_Str; k++)
             {
                 for(num = 0; pgm_read_byte(&Character_font_6x8[num].Character[0]) != '@'; num++)
                 {
                     if(i8_Str_Display_Buffer[k] == pgm_read_byte(&Character_font_6x8[num].Character[0]))
                     {
                         for(uint8_t j = 0; j < 6; j++)
                         {
                             u8_Display_Buffer[display_buffer_label] = pgm_read_byte(&Character_font_6x8[num].data[j]);
                             display_buffer_label++;
                             if(display_buffer_label >= LED_BUFFER_SIZE)
                             {
                                 break;
                             }
                         }
                         break;
                     }
                 }
 
                 if(pgm_read_byte(&Character_font_6x8[num].Character[0]) == '@')
                 {
                     i8_Str_Display_Buffer[k] = ' ';
                     k--;
                 }
             }
 
             if(display_buffer_label < LED_BUFFER_SIZE)
             {
                 for(display_buffer_label = display_buffer_label; display_buffer_label < LED_BUFFER_SIZE; display_buffer_label++)
                 {
                     u8_Display_Buffer[display_buffer_label] = 0x00;
                 }
             }
         }
     }
     else if(i16_Str_Display_X_Position <= 0)
     {
         if(i16_Str_Display_X_Position == -(i16_Number_of_Character_of_Str * 6))
         {
             for(; display_buffer_label < LED_BUFFER_SIZE; display_buffer_label++)
             {
                 u8_Display_Buffer[display_buffer_label] = 0x00;
             }
         }
         else
         {
             int8_t j = (-i16_Str_Display_X_Position) % 6;
             uint8_t num;
 
             i16_Str_Display_X_Position = -i16_Str_Display_X_Position;
 
             for(int16_t k = i16_Str_Display_X_Position / 6; display_buffer_label < LED_BUFFER_SIZE && k < i16_Number_of_Character_of_Str; k++)
             {
                 for(num = 0; pgm_read_byte(&Character_font_6x8[num].Character[0]) != '@'; num++)
                 {
                     if(i8_Str_Display_Buffer[k] == pgm_read_byte(&Character_font_6x8[num].Character[0]))
                     {
                         for(; j < 6; j++)
                         {
                             u8_Display_Buffer[display_buffer_label] = pgm_read_byte(&Character_font_6x8[num].data[j]);
                             display_buffer_label++;
                             if(display_buffer_label >= LED_BUFFER_SIZE)
                             {
                                 break;
                             }
                         }
                         j = 0;
                         break;
                     }
                 }
 
                 if(pgm_read_byte(&Character_font_6x8[num].Character[0]) == '@')
                 {
                     i8_Str_Display_Buffer[k] = ' ';
                     k--;
                 }
             }
 
             if(display_buffer_label < LED_BUFFER_SIZE)
             {
                 for(; display_buffer_label < LED_BUFFER_SIZE; display_buffer_label++)
                 {
                     u8_Display_Buffer[display_buffer_label] = 0x00;
                 }
             }
 
             i16_Str_Display_X_Position = -i16_Str_Display_X_Position;
         }
     }
 
     if(7 - i8_Str_Display_Y_Position >= 0)
     {
         for(uint8_t k = 0; k < LED_BUFFER_SIZE; k++)
         {
             u8_Display_Buffer[k] = u8_Display_Buffer[k] << (7 - i8_Str_Display_Y_Position);
         }
     }
     else
     {
         for(uint8_t k = 0; k < LED_BUFFER_SIZE; k++)
         {
             u8_Display_Buffer[k] = u8_Display_Buffer[k] >> (i8_Str_Display_Y_Position - 7);
         }
     }
 
     if(b_Color_Index == 0)
     {
         for(uint8_t k = 0; k < LED_BUFFER_SIZE; k++)
         {
             u8_Display_Buffer[k] = ~u8_Display_Buffer[k];
         }
     }
 
     writeBytesToAddress(0, u8_Display_Buffer, LED_BUFFER_SIZE);
 }
 
 void NswLEDMatrix::showClock(uint8_t hour, uint8_t minute, bool point_flag)
 {
     u8_Display_Buffer[0]  = pgm_read_byte(&Clock_Number_font_3x8[hour/10].data[0]);
     u8_Display_Buffer[1]  = pgm_read_byte(&Clock_Number_font_3x8[hour/10].data[1]);
     u8_Display_Buffer[2]  = pgm_read_byte(&Clock_Number_font_3x8[hour/10].data[2]);
  
     u8_Display_Buffer[3]  = 0x00;
  
     u8_Display_Buffer[4]  = pgm_read_byte(&Clock_Number_font_3x8[hour%10].data[0]);
     u8_Display_Buffer[5]  = pgm_read_byte(&Clock_Number_font_3x8[hour%10].data[1]);
     u8_Display_Buffer[6]  = pgm_read_byte(&Clock_Number_font_3x8[hour%10].data[2]);
  
     u8_Display_Buffer[9]  = pgm_read_byte(&Clock_Number_font_3x8[minute/10].data[0]);
     u8_Display_Buffer[10] = pgm_read_byte(&Clock_Number_font_3x8[minute/10].data[1]);
     u8_Display_Buffer[11] = pgm_read_byte(&Clock_Number_font_3x8[minute/10].data[2]);
 
     u8_Display_Buffer[12] = 0x00;
 
     u8_Display_Buffer[13] = pgm_read_byte(&Clock_Number_font_3x8[minute%10].data[0]);
     u8_Display_Buffer[14] = pgm_read_byte(&Clock_Number_font_3x8[minute%10].data[1]);
     u8_Display_Buffer[15] = pgm_read_byte(&Clock_Number_font_3x8[minute%10].data[2]);
 
     if(point_flag == PointOn)
     {
         u8_Display_Buffer[7] = 0x28;
         u8_Display_Buffer[8] = 0x28;
     }
     else
     {
         u8_Display_Buffer[7] = 0x00;
         u8_Display_Buffer[8] = 0x00;
     }
 
     if(b_Color_Index == 0)
     {
         for(uint8_t k = 0; k < LED_BUFFER_SIZE; k++)
         {
             u8_Display_Buffer[k] = ~u8_Display_Buffer[k];
         }
     }
 
     writeBytesToAddress(0, u8_Display_Buffer, LED_BUFFER_SIZE);
 }
 
 void NswLEDMatrix::showNum(float value, uint8_t digits)
 {
 Posotion_1:
     uint8_t buf[4] = {0x0c, 0x0c, 0x0c, 0x0c};
     uint8_t tempBuf[4];
     uint8_t b = 0;
     uint8_t bit_num = 0;
     uint8_t int_num = 0;
     uint8_t isNeg = 0;
     double number = value;
     if(number >= 9999.5)
     {
         buf[0] = 9;
         buf[1] = 9;
         buf[2] = 9;
         buf[3] = 9;
     }
     else if(number <= -999.5)
     {
         buf[0] = 0x0b;
         buf[1] = 9;
         buf[2] = 9;
         buf[3] = 9;  
     }
     else
     {
         if(number < 0.0)
         {
             number = -number;
             isNeg = 1;
         }
         double rounding = 0.5;
         for(uint8_t i = 0; i < digits; ++i)
         {
             rounding /= 10.0;
         }
         number += rounding;
 
         uint16_t int_part = (uint16_t)number;
         double remainder = number - (double)int_part;
         do
         {
             uint16_t m = int_part;
             int_part /= 10;
             int8_t c = m - 10 * int_part;
             tempBuf[int_num] = c;
             int_num++;
         }
         while(int_part);
 
         bit_num = isNeg + int_num + digits;
 
         if(bit_num > 4)
         {
             bit_num = 4;
             digits = 4 - (isNeg + int_num);
             goto Posotion_1;
         }
         b = 4 - bit_num;
         if(isNeg)
         {
             buf[b++] = 0x0b; // '-' display minus sign
         }
         for(uint8_t i = int_num; i > 0; i--)
         {
             buf[b++] = tempBuf[i - 1];
         }
         if(digits > 0)
         {
             if((b == 3) && (int16_t(remainder*10) == 0))
             {
                 buf[3] = 0x0c;
             }
             else if((b == 2) && (int16_t(remainder*100) == 0))
             {
                 buf[2] = 0x0c;
                 buf[3] = 0x0c;
             }
             else if((b == 1) && (int16_t(remainder*1000) == 0))
             {
                 buf[1] = 0x0c;
                 buf[2] = 0x0c;
                 buf[3] = 0x0c;
             }
             else
             {
                 buf[b++] = 0x0a;  // display '.'
                 while(digits-- > 0)
                 {
                     remainder *= 10.0;
                     int16_t toPrint = int16_t(remainder);
                     buf[b++] = toPrint;
                     remainder -= toPrint;
                 }
             }
         }
     }
 
     u8_Display_Buffer[0]  = pgm_read_byte(&Clock_Number_font_3x8[buf[0]].data[0]);
     u8_Display_Buffer[1]  = pgm_read_byte(&Clock_Number_font_3x8[buf[0]].data[1]);
     u8_Display_Buffer[2]  = pgm_read_byte(&Clock_Number_font_3x8[buf[0]].data[2]);
     
     u8_Display_Buffer[3]  = 0x00;
     
     u8_Display_Buffer[4]  = pgm_read_byte(&Clock_Number_font_3x8[buf[1]].data[0]);
     u8_Display_Buffer[5]  = pgm_read_byte(&Clock_Number_font_3x8[buf[1]].data[1]);
     u8_Display_Buffer[6]  = pgm_read_byte(&Clock_Number_font_3x8[buf[1]].data[2]);
     
     u8_Display_Buffer[7]  = 0x00;
     
     u8_Display_Buffer[8]  = pgm_read_byte(&Clock_Number_font_3x8[buf[2]].data[0]);
     u8_Display_Buffer[9]  = pgm_read_byte(&Clock_Number_font_3x8[buf[2]].data[1]);
     u8_Display_Buffer[10] = pgm_read_byte(&Clock_Number_font_3x8[buf[2]].data[2]);
     
     u8_Display_Buffer[11] = 0x00;
     
     u8_Display_Buffer[12] = pgm_read_byte(&Clock_Number_font_3x8[buf[3]].data[0]);
     u8_Display_Buffer[13] = pgm_read_byte(&Clock_Number_font_3x8[buf[3]].data[1]);
     u8_Display_Buffer[14] = pgm_read_byte(&Clock_Number_font_3x8[buf[3]].data[2]);
 
     u8_Display_Buffer[15] = 0x00;
 
     if(b_Color_Index == 0)
     {
         for(uint8_t k = 0; k < LED_BUFFER_SIZE; k++)
         {
             u8_Display_Buffer[k] = ~u8_Display_Buffer[k];
         }
     }
 
     writeBytesToAddress(0, u8_Display_Buffer, LED_BUFFER_SIZE);
 }