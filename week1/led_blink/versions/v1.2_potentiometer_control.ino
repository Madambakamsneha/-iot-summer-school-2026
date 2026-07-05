/*
 * ---------------------------------------------------------
 *  Sketch  : v1.2_potentiometer_control.ino
 *  Version : 1.2
 * ---------------------------------------------------------
 *  Description:
 *    Adds analog input control. A potentiometer connected
 *    to analog pin A0 dynamically controls the blink delay.
 *    The raw ADC reading (0-1023) is mapped to a delay
 *    range of 50ms - 1000ms, so turning the potentiometer
 *    speeds up or slows down the blink rate in real time.
 * ---------------------------------------------------------
 */

const int LED_PIN = LED_BUILTIN;
const int POT_PIN = A0;

const int MIN_DELAY_MS = 50;
const int MAX_DELAY_MS = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
  Serial.begin(9600);
  Serial.println(F("=== Potentiometer-Controlled Blink Started ==="));
}

void loop() {
  int potValue = analogRead(POT_PIN);                          // 0 - 1023
  int blinkDelay = map(potValue, 0, 1023, MIN_DELAY_MS, MAX_DELAY_MS);

  digitalWrite(LED_PIN, HIGH);
  delay(blinkDelay);

  digitalWrite(LED_PIN, LOW);
  delay(blinkDelay);

  Serial.print(F("Pot Value: "));
  Serial.print(potValue);
  Serial.print(F(" | Delay (ms): "));
  Serial.println(blinkDelay);
}
