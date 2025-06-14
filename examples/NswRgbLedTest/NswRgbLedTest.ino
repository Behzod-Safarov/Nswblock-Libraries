#include "NswRGBLed.h"

// LED modulini boshqarish uchun NswRGBLed kutubxonasini ulaymiz
// Kutubxona Adafruit_NeoPixel'dan foydalanadi, bu ranglar va vaqtni to'g'ri boshqaradi

NswRGBLed led(PORT_4, ColorOrder::RGB); // PORT_4 (pin 9) va rang tartibi RGB sifatida o'rnatiladi
// Agar ranglar hali ham noto'g'ri bo'lsa, ColorOrder::BRG, RBG va hokazolarni sinab ko'ring

void setup() {
  // LED modulini ishga tushirish
  led.begin(); // LEDlarni boshlash va dastlabki sozlamalarni o'rnatish
  led.setBrightness(50); // Yorqinlikni 50/255 ga o'rnatish (quvvat sarfini kamaytirish)
}

void loop() {
  // Barcha LEDlarni turli ranglar bilan sinash
  led.setColor(255, 0, 0); // Barcha LEDlarni yashil rangga o'rnatish (to'g'ri bo'lsa, qizil ko'rinadi)
  led.show(); // LEDlarni yangilash va ko'rsatish
  delay(2000); // 2 soniya kutish

  led.setColor(0, 255, 0); // Barcha LEDlarni qizil rangga o'rnatish (to'g'ri bo'lsa, yashil ko'rinadi)
  led.show();
  delay(2000);

  led.setColor(0, 0, 255); // Barcha LEDlarni ko'k rangga o'rnatish
  led.show();
  delay(2000);

  led.setColor(255, 255, 0); // Barcha LEDlarni sariq rangga o'rnatish
  led.show();
  delay(2000);

  led.setColor(0, 255, 255); // Barcha LEDlarni pushti rangga o'rnatish
  led.show();
  delay(2000);

  led.setColor(255, 0, 255); // Barcha LEDlarni moviy rangga o'rnatish
  led.show();
  delay(2000);

  led.setColor(255, 255, 255); // Barcha LEDlarni oq rangga o'rnatish
  led.show();
  delay(2000);

  // Har bir LEDni alohida sinash
  led.clear(); // Barcha LEDlarni o'chirish
  led.setColor(0, 255, 0, 0); // 0-LEDni yashil rangga o'rnatish
  led.setColor(1, 0, 255, 0); // 1-LEDni qizil rangga o'rnatish
  led.setColor(2, 0, 0, 255); // 2-LEDni ko'k rangga o'rnatish
  led.setColor(3, 255, 255, 255); // 3-LEDni oq rangga o'rnatish
  led.show(); // LEDlarni yangilash va ko'rsatish
  delay(2000); // 2 soniya kutish
}