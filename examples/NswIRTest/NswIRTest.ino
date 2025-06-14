#include <NSWInfraredReceiver.h> // NSWbloc infraqizil (IR) qabul qiluvchi kutubxonasi ulanmoqda

// PORT_4 ga ulangan IR qabul qiluvchi qurilmani ishga tushiramiz
// PORT_4: pin1 = tugma tekshiruvi (S1), pin2 = IR signal qabul qiluvchi RX pin
NSWInfraredReceiver irReceiver(PORT_4);

void setup() {
  // USB orqali kompyuter bilan aloqa uchun Serial portni 9600 tezlikda boshlaymiz
  Serial.begin(9600);

  // IR qabul qiluvchini ishga tushiramiz
  irReceiver.begin();

  // Kompyuterga dastur ishga tushganini bildirish uchun xabar yuboramiz
  Serial.println("NSWbloc IR Receiver Test");
}

void loop() {
  // IR qabul qiluvchini yangilab turish uchun doimiy chaqirilishi kerak
  irReceiver.loop();

  // Agar masofadan boshqaruvchi tugmasi bosilgan bo‘lsa
  if (irReceiver.buttonState()) {

    // Bosilgan tugma uchun mos keluvchi IR kodini olamiz
    uint8_t code = irReceiver.getCode();

    // Agar IR kodi 0 bo‘lmasa (ya’ni haqiqiy kod bo‘lsa)
    if (code != 0) {
      // IR kodni kompyuterga HEX (o‘n oltilik) formatda chiqaramiz
      Serial.print("IR Code: 0x");
      Serial.print(code, HEX);
      Serial.print(" (");

      // Kodga mos keluvchi tugmani aniqlaymiz va ekranga chiqaramiz
      switch (code) {
        case IR_BUTTON_A:        Serial.println("A tugmasi bosildi"); break;
        case IR_BUTTON_B:        Serial.println("B tugmasi bosildi"); break;
        case IR_BUTTON_C:        Serial.println("C tugmasi bosildi"); break;
        case IR_BUTTON_D:        Serial.println("D tugmasi bosildi"); break;
        case IR_BUTTON_E:        Serial.println("E tugmasi bosildi"); break;
        case IR_BUTTON_UP:       Serial.println("Yuqoriga tugma bosildi"); break;
        case IR_BUTTON_DOWN:     Serial.println("Pastga tugma bosildi"); break;
        case IR_BUTTON_LEFT:     Serial.println("Chapga tugma bosildi"); break;
        case IR_BUTTON_RIGHT:    Serial.println("O‘ngga tugma bosildi"); break;
        case IR_BUTTON_SETTING:  Serial.println("Sozlamalar tugmasi bosildi"); break;
        case IR_BUTTON_F:        Serial.println("F tugmasi bosildi"); break;
        case IR_BUTTON_0:        Serial.println("0 tugmasi bosildi"); break;
        case IR_BUTTON_1:        Serial.println("1 tugmasi bosildi"); break;
        case IR_BUTTON_2:        Serial.println("2 tugmasi bosildi"); break;
        case IR_BUTTON_3:        Serial.println("3 tugmasi bosildi"); break;
        case IR_BUTTON_4:        Serial.println("4 tugmasi bosildi"); break;
        case IR_BUTTON_5:        Serial.println("5 tugmasi bosildi"); break;
        case IR_BUTTON_6:        Serial.println("6 tugmasi bosildi"); break;
        case IR_BUTTON_7:        Serial.println("7 tugmasi bosildi"); break;
        case IR_BUTTON_8:        Serial.println("8 tugmasi bosildi"); break;
        case IR_BUTTON_9:        Serial.println("9 tugmasi bosildi"); break;

        // Agar kod tanilmagan bo‘lsa
        default:                 Serial.println("Noma’lum tugma bosildi"); break;
      }

      // Yozuvni tugatamiz
      Serial.println(")");
    }
  }

  // Serial monitorni haddan tashqari ko‘p to‘ldirib yubormaslik uchun kichik pauza
  delay(10);
}
