
 #include "NswLEDMatrix.h"

 NswLEDMatrix ledMx(PORT_4);
 
 void setup()
 {
     ledMx.setBrightness(6);
     ledMx.setColorIndex(1);
 }
 
 char *s = "AB";
 
 void loop()
 {
     ledMx.showClock(12, 03, 1);
     delay(2000);
     ledMx.drawStr(0, 7, s);
     delay(2000);
     ledMx.showNum(1.23);
     delay(2000);
 }