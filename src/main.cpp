#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

// Create a BluetoothSerial object to handle Bluetooth communication
BluetoothSerial SerialBT;

void setup()
{
  // Initialize serial communication at 115200 baud rate for debugging
  Serial.begin(115200);

  // Set the built-in LED pin as output
  pinMode(BUILTIN_LED, OUTPUT);

  // Start Bluetooth communication and set the device name to "ESP32_Slave"
  SerialBT.begin("ESP32_Slave");
  Serial.println("ESP32 Slave Bluetooth Serial Started. Waiting for Master to connect...");

  // Wait until the ESP32 Master device connects to this ESP32 Slave
  while (!SerialBT.connected())
  {
    delay(1000);  // Wait for 1 second before checking again
    Serial.println("Waiting for ESP32_Master to be connected...");
  }

  // Once connected, print a confirmation message
  Serial.println("Connected to ESP32_Master");

  // Turn on the built-in LED to indicate a successful connection
  digitalWrite(BUILTIN_LED, HIGH);
}

void loop()
{
  // Check if data is received from the master device via Bluetooth
  if (SerialBT.available())
  {
    // Read the incoming data as a string
    String incomingData = SerialBT.readString();
    Serial.print("Received JSON: ");
    Serial.println(incomingData);

    // Create a JSON document to hold the parsed data
    JsonDocument jsonDoc; // Adjust the size as needed

    // Attempt to deserialize the JSON data from the incoming string
    DeserializationError error = deserializeJson(jsonDoc, incomingData);

    // Check if deserialization was successful
    if (error)
    {
      Serial.print("JSON Deserialization failed: ");
      Serial.println(error.c_str());  // Print the error message
      return;  // Exit the loop if there's an error
    }

    // Extract the pin number and status from the JSON document
    int pin_number = jsonDoc["pin_number"];
    bool pin_status = jsonDoc["pin_status"];

    // Set the specified pin as output
    pinMode(pin_number, OUTPUT);

    // Write the received status to the specified pin (HIGH or LOW)
    digitalWrite(pin_number, pin_status);

    // Send a confirmation back to the master device
    SerialBT.println("Command executed successfully");
  }

  delay(50);  // Small delay to avoid overwhelming the loop
}
