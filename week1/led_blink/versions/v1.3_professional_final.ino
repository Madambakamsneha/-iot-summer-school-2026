/*
 * =========================================================
 *  Project     : IoT Summer School 2026 - Week 1
 *  Sketch      : v1.3_professional_final.ino
 *  Version     : 1.3
 *  Author      : [Your Name]
 *  Date        : 2026-07-05
 * ---------------------------------------------------------
 *  Description:
 *    Final, production-style version of the Week 1 blink
 *    exercise. Combines all prior iterations into a single
 *    clean sketch:
 *      - Configurable blink delay via a potentiometer (A0)
 *      - Live status reporting over Serial (9600 baud)
 *      - Running blink counter
 *      - Named constants and descriptive function names
 *        for readability and maintainability
 *
 *  Hardware:
 *    - Arduino Uno / Nano (or compatible)
 *    - Onboard LED (LED_BUILTIN)
 *    - 10k potentiometer, wiper -> A0
 *
 *  License: MIT (see repository LICENSE file)
 * =========================================================
 */

// ------------------- Pin Definitions -------------------
const int LED_PIN = LED_BUILTIN;
const int POT_PIN = A0;

// ------------------- Tunable Constants -------------------
const int MIN_DELAY_MS = 50;
const int MAX_DELAY_MS = 1000;
const long SERIAL_BAUD_RATE = 9600;

// ------------------- Global State -------------------
unsigned long blinkCount = 0;

/**
 * Reads the potentiometer and maps it to a blink delay.
 * @return delay in milliseconds, clamped to [MIN_DELAY_MS, MAX_DELAY_MS]
 */
int readBlinkDelay() {
  int potValue = analogRead(POT_PIN);
  return map(potValue, 0, 1023, MIN_DELAY_MS, MAX_DELAY_MS);
}

/**
 * Performs a single LED ON/OFF cycle using the given delay,
 * then reports status over Serial.
 */
void blinkOnce(int delayMs) {
  digitalWrite(LED_PIN, HIGH);
  delay(delayMs);

  digitalWrite(LED_PIN, LOW);
  delay(delayMs);

  blinkCount++;

  Serial.print(F("Blink #"));
  Serial.print(blinkCount);
  Serial.print(F(" | Delay: "));
  Serial.print(delayMs);
  Serial.println(F(" ms"));
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);

  Serial.begin(SERIAL_BAUD_RATE);
  Serial.println(F("========================================"));
  Serial.println(F(" IoT Summer School 2026 - Week 1"));
  Serial.println(F(" LED Blink v1.3 (Professional Final)"));
  Serial.println(F("========================================"));
}

void loop() {
  int currentDelay = readBlinkDelay();
  blinkOnce(currentDelay);
}
