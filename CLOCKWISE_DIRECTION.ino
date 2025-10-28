#include <Servo.h>

Servo ESC;                // Create servo object for ESC
#define ESC_PIN 8         // ESC signal pin
#define POT_PIN A0        // Potentiometer pin

void setup() {
  Serial.begin(9600);
  ESC.attach(ESC_PIN);
  
  Serial.println("Initializing ESC for Clockwise rotation...");
  ESC.writeMicroseconds(1500);   // Neutral (Stop)
  delay(2000);                   // Wait 2 seconds for ESC to arm
  Serial.println("ESC armed and ready (Clockwise Mode).");
}

void loop() {
  int potValue = analogRead(POT_PIN);     // Read potentiometer (0–1023)
  
  // Map 0–1023 → 1500–2000 (neutral to full forward)
  int throttle = map(potValue, 0, 1023, 1500, 2000);

  ESC.writeMicroseconds(throttle);

  Serial.print("Direction: CLOCKWISE | Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Throttle: ");
  Serial.println(throttle);

  delay(50);
}

/* 
To switch to ANTICLOCKWISE mode, 
replace this line:
    int throttle = map(potValue, 0, 1023, 1500, 2000);
with:
    int throttle = map(potValue, 0, 1023, 1500, 1000);
*/
