/*
 * ---------------------------------------------------------
 *  Project : IoT Summer School 2026 - Week 1
 *  File    : blink_modified.ino
 * ---------------------------------------------------------
 *  Description:
 *    Modified blink pattern: the onboard LED blinks THREE
 *    times quickly (150ms ON / 150ms OFF), then pauses for
 *    2 full seconds before repeating the pattern.
 *
 *    Pattern per cycle:
 *      Blink - Blink - Blink - (2s pause) - repeat
 * ---------------------------------------------------------
 */

const int LED_PIN = LED_BUILTIN;
const int FAST_BLINK_DELAY_MS = 150;
const int PAUSE_DELAY_MS = 2000;
const int FAST_BLINK_COUNT = 3;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Three fast blinks
  for (int i = 0; i < FAST_BLINK_COUNT; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(FAST_BLINK_DELAY_MS);

    digitalWrite(LED_PIN, LOW);
    delay(FAST_BLINK_DELAY_MS);
  }

  // 2-second pause before the pattern repeats
  delay(PAUSE_DELAY_MS);
}
