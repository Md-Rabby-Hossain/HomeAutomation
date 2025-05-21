#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
const int ledPin = 4; // Use GPIO PIN for the Light

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32-BT-Slave"); // Set Bluetooth name
  Serial.println("Bluetooth started. Pair with ESP32_LED.");
}

void loop() {
  if (SerialBT.available()) {
    int command = SerialBT.read(); // Read the ASCII value of the command

    // Handle the received command
    if (command == 49) { // ASCII code for '1'
      digitalWrite(ledPin, LOW); // Turn on LED
      Serial.println("Light is ON");
    } else if (command == 48) { // ASCII code for '0'
      digitalWrite(ledPin, HIGH); // Turn off LED
      Serial.println("Light is OFF");
    } else {
      SerialBT.println("Unknown command");
      Serial.println("Action: Unknown command received");
    }
  }
}
