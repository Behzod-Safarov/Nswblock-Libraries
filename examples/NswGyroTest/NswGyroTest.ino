#include <NswGyro.h>

// 📌 Giroskop sensorini boshlaymiz (standart I2C adres: 0x68)
NswGyro gyro;

void setup() {
    Serial.begin(115200);  // 📌 Serial monitor orqali ma'lumotlarni chiqarish uchun
    gyro.begin();          // 📌 Sensorni ishga tushiramiz
}

void loop() {
    gyro.update(); // 📌 Giroskop o‘lchovlarini yangilaymiz

    Serial.read(); // 📌 Serial buffer'ni tozalash, lekin foydalanilmaydi

    // 📌 Giroskopdan olingan burchak ma'lumotlarini chiqaramiz
    Serial.print("X: ");
    Serial.print(gyro.getAngleX());
    Serial.print("°  Y: ");
    Serial.print(gyro.getAngleY());
    Serial.print("°  Z: ");
    Serial.println(gyro.getAngleZ());
    
    delay(10); // 📌 Har 10 millisekundda yangilash
}
