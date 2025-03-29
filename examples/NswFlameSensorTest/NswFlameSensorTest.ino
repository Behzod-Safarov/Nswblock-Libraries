#include "NswFlameSensor.h"

// Olov sensori PORT_1 da ishga tushiriladi (pin1 = 2, pin2 = 3)
// Bu yerda sensorning analog signali pin2 (3) va raqamli signali pin1 (2) ga ulanadi
NswFlameSensor olov(PORT_1);

void setup() {
  // Serial aloqani boshlash, tezligi 9600 baud
  // Bu kompyuter bilan ma'lumot almashish uchun ishlatiladi
  Serial.begin(9600);

  // Olov sensorini ishga tushirish
  // Pinlarni kirish sifatida sozlaydi (analog va raqamli)
  olov.begin();
}

void loop() {
  // Analog qiymatni o'qish (0-1023 oralig'ida)
  // Bu olovning intensivligini ko'rsatadi, yaqinroq olov kichikroq qiymat beradi
  int analogQiymat = olov.readAnalog();

  // Raqamli qiymatni o'qish (true yoki false)
  // True - olov bor (pin1 LOW), False - olov yo'q (pin1 HIGH)
  bool raqamliQiymat = olov.readDigital();

  // Olov aniqlanganligini tekshirish, chegarasi 500
  // Agar analog qiymat 500 dan kichik bo'lsa, olov bor deb hisoblanadi
  bool olovAniqlandi = olov.isFlameDetected(500);

  // Natijalarni Serial Monitor ga chiqarish
  Serial.print("Analog: ");          // "Analog:" so'zini chiqaradi
  Serial.print(analogQiymat);        // Analog qiymatni chiqaradi
  Serial.print("  Raqamli: ");       // "Raqamli:" so'zini chiqaradi
  Serial.print(raqamliQiymat ? "Olov" : "Olov yo'q");  // Olov bor yoki yo'qligini ko'rsatadi
  Serial.print("  Aniqlangan: ");    // "Aniqlangan:" so'zini chiqaradi
  Serial.println(olovAniqlandi ? "Ha" : "Yo'q");       // Ha yoki Yo'q chiqaradi

  // 1 soniya kutish (1000 millisekund)
  // Har bir o'qishdan keyin yangi ma'lumot olish uchun pauza
  delay(1000);
}