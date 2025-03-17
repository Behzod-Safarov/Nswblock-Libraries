#include <NswFourButton.h>

// Create an instance of the 4-button module, connected to PORT_3 (A2, A3)
NswFourButton buttons(PORT_3);

void setup() {
    Serial.begin(115200);  // Start the serial monitor at 115200 baud rate
    Serial.println("4-Button Module Test Started...");
    Serial.println("Press any button to see the output.");
}

void loop() {
    uint8_t button = buttons.getPressedButton();  // Read which button is pressed

    if (button > 0) {
        Serial.print("Button ");
        Serial.print(button);
        Serial.println(" is Pressed!");
    } else {
        Serial.println("No button pressed...");
    }

    delay(300);  // Add a small delay to make the output readable
}
