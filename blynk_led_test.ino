#define BLYNK_TEMPLATE_ID "TMPL2tAHyVttJ"
#define BLYNK_TEMPLATE_NAME "led"
#define BLYNK_AUTH_TOKEN "C5DqdtYO1rF1T_OiGU3EeusaQva6wclo"

//include the Blynk library
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the built-in LED pin (GPIO 2 on most ESP32 boards)
#define LED_BUILTIN 2

// Your Blynk Auth Token (from the Blynk app)
char auth[] = "C5DqdtYO1rF1T_OiGU3EeusaQva6wclo";

// Your Wi-Fi credentials
char ssid[] = "Black_Tech";
char pass[] = "Black@2020";

// Blynk virtual pin handler
BLYNK_WRITE(V0) {
  int buttonState = param.asInt(); // Read the button state (0 or 1)
  digitalWrite(LED_BUILTIN, buttonState); // Set the LED state
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the built-in LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Connect to Wi-Fi and Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // Run Blynk
  Blynk.run();
}