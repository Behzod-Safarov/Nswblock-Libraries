
 #include <NswBluetooth.h>


 NswBluetooth bluetooth(PORT_5); // Uses pins 6 (RX) and 7 (TX)
 
 void setup()
 {
     // Initialize serial for debugging
     Serial.begin(9600);
     while (!Serial) {
         ; // Wait for Serial to connect
     }
     
     // Initialize Bluetooth at 9600 baud (common default for HC-05/HC-06)
     bluetooth.begin(9600);
     Serial.println("Bluetooth initialized on PORT_5 (RX=6, TX=7). Send data to test...");
 }
 
 void loop()
 {
     // Check if data is available from Bluetooth
     if (bluetooth.available()) {
         char c = bluetooth.read();
         Serial.print("Received from Bluetooth: ");
         Serial.println(c);
         
         // Echo back to Bluetooth
         bluetooth.print("Echo: ");
         bluetooth.println(c);
     }
     
     // Check if data is available from Serial to send to Bluetooth
     if (Serial.available()) {
         char c = Serial.read();
         bluetooth.write(c);
         Serial.print("Sent to Bluetooth: ");
         Serial.println(c);
     }
     
     delay(10); // Small delay to prevent overwhelming the loop
 }