#include "NswLightSensor.h" // NswLightSensor kutubxonasini ulaymiz. Bu kutubxona yorug'lik sensorini boshqarish uchun ishlatiladi.

// PORT_4 portidagi pin2 ga ulangan yorug'lik sensorini yaratamiz
NswLightSensor lightSensor(PORT_4); // Sensor PORT_4 da ishlaydi, ya'ni pin2 ishlatiladi

void setup() {
  // Serial aloqani boshlaymiz, 9600 baud tezlikda
  // Bu orqali sensor ma'lumotlarini kompyuterga yuboramiz
  Serial.begin(9600);
  
  // Yorug'lik sensorini ishga tushiramiz
  // Bu sensor pinini INPUT rejimiga o'rnatadi
  lightSensor.begin();
}

void loop() {
  // Yorug'lik intensivligini o'qiymiz
  // Bu funksiya analogRead orqali sensordan qiymat oladi (0-1023 oralig'ida)
  int lightValue = lightSensor.readValue();
  
  // Olingan yorug'lik qiymatini serial monitoriga chiqaramiz
  Serial.print("Yorug'lik Intensivligi: ");
  Serial.println(lightValue);

  // Muhit yorug'ligini tekshiramiz, chegaraviy qiymat 500
  // Agar yorug'lik 500 dan katta bo'lsa, "Ha" aks holda "Yo'q" qaytariladi
  bool isBright = lightSensor.isBright(500);
  Serial.print("Yorug'mi: ");
  Serial.println(isBright ? "Ha" : "Yo'q");

  // Keyingi o'qishdan oldin 1 soniya (1000 millisekund) kutamiz
  delay(1000);
}