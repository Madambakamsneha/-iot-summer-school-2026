/*
 * ---------------------------------------------------------
 *  Sketch  : v1.1_serial_blink_counter.ino
 *  Version : 1.1
 * ---------------------------------------------------------
 *  Description:
 *    Builds on v1.0 by adding Serial Monitor output.
 *    Every time the LED completes a full ON/OFF cycle,
 *    the running blink count is printed to the Serial
 *    Monitor at 9600 baud.
 * ---------------------------------------------------------
 */

const int LED_PIN = LED_BUILTIN;
const int BLINK_DELAY_MS = 500;

unsigned long blinkCount = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println(F("=== LED Blink Counter Started ==="));
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_DELAY_MS);

  digitalWrite(LED_PIN, LOW);
  delay(BLINK_DELAY_MS);

  blinkCount++;
  Serial.print(F("Blink Count: "));
  Serial.println(blinkCount);
}
