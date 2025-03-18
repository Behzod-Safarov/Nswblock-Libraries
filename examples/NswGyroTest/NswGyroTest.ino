 #include <NswGyro.h>

 NswGyro gyro; // Default constructor uses address 0x68
 
 void setup()
 {
     Serial.begin(115200);
     gyro.begin();
 }
 
 void loop()
 {
     gyro.update();
     Serial.read(); // Note: This clears serial buffer but doesn't use the input
     Serial.print("X:");
     Serial.print(gyro.getAngleX());
     Serial.print(" Y:");
     Serial.print(gyro.getAngleY());
     Serial.print(" Z:");
     Serial.println(gyro.getAngleZ());
     delay(10);
 }