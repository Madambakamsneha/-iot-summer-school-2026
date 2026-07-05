/*
 * ---------------------------------------------------------
 *  Project : IoT Summer School 2026 - Week 1
 *  File    : led_blink.ino
 *  Purpose : Assignment starter sketch - basic LED blink
 * ---------------------------------------------------------
 *  Description:
 *    Turns the onboard LED (LED_BUILTIN) ON and OFF
 *    at a fixed 1-second interval. This is the classic
 *    "Hello World" of embedded systems and verifies that
 *    the board, IDE, and upload toolchain are working.
 * ---------------------------------------------------------
 */

void setup() {
  // Configure the onboard LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
  delay(1000);                     // Wait 1 second

  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off
  delay(1000);                     // Wait 1 second
}
