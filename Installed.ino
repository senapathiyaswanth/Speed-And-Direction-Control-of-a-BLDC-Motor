#include <Servo.h>

Servo ESC;                // Create servo object to control the ESC
#define ESC_PIN 8         // Pin connected to ESC signal wire
#define POT_PIN A0        // Pin connected to potentiometer

void setup() {
  Serial.begin(9600);
  ESC.attach(ESC_PIN);

  Serial.println("Calibrating ESC...");
  ESC.writeMicroseconds(1000);   // Minimum throttle
  delay(2000);                   // Wait 2 seconds for ESC to arm
  Serial.println("ESC armed and ready.");
}

void loop() {
  int potValue = analogRead(POT_PIN);                 // Read potentiometer value (0–1023)
  int throttle = map(potValue, 0, 1023, 1000, 2000);  // Map to ESC signal range

  ESC.writeMicroseconds(throttle);                    // Send signal to ESC

  // Debug info on serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Throttle signal: ");
  Serial.println(throttle);

  delay(50);  // Small delay for stability
}
