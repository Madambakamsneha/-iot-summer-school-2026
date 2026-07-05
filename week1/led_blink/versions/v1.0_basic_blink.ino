/*
 * ---------------------------------------------------------
 *  Sketch  : v1.0_basic_blink.ino
 *  Version : 1.0
 * ---------------------------------------------------------
 *  Description:
 *    Baseline blink sketch. Blinks the onboard LED with a
 *    500ms ON / 500ms OFF interval (twice as fast as the
 *    default Arduino Blink example).
 * ---------------------------------------------------------
 */

const int LED_PIN = LED_BUILTIN;
const int BLINK_DELAY_MS = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_DELAY_MS);

  digitalWrite(LED_PIN, LOW);
  delay(BLINK_DELAY_MS);
}
