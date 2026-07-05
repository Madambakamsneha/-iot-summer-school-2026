# 💡 LED Blink — Week 1

## 📌 Project Overview

This mini-project is the foundational "Hello World" exercise of embedded
systems programming. It verifies that the Arduino board, IDE, drivers,
and upload toolchain are all correctly configured by blinking the
onboard LED at a fixed interval. Four progressively advanced versions
of this sketch are provided in the [`versions/`](./versions) folder,
building up from a basic blink to a fully instrumented, potentiometer-
controlled sketch.

---

## 🧰 Components Required

| Component            | Quantity | Notes                                 |
|-----------------------|:--------:|-----------------------------------------|
| Arduino Uno / Nano     | 1        | Or any compatible board                |
| USB Cable              | 1        | For power + serial upload              |
| LED (optional)         | 1        | Only needed if not using onboard LED   |
| 220Ω Resistor          | 1        | Required only with an external LED     |
| 10kΩ Potentiometer     | 1        | Required for v1.2 / v1.3               |
| Breadboard + Jumper Wires | —     | For potentiometer wiring               |

---

## 🔌 Circuit Connections

**Basic version (onboard LED only):** No external wiring required —
`LED_BUILTIN` is wired to a pin on the board already (typically pin 13
on the Uno).

**Potentiometer version (v1.2 / v1.3):**

| Potentiometer Pin | Connects To      |
|--------------------|------------------|
| Left terminal       | 5V               |
| Right terminal      | GND              |
| Wiper (middle pin)  | Analog pin `A0`  |

---

## 🖼️ Circuit Description

The potentiometer acts as a voltage divider. As its knob is turned, the
wiper voltage varies smoothly between 0V and 5V. The Arduino reads this
voltage through `analogRead(A0)`, returning a value between `0` and
`1023`. This value is then mapped to a blink delay range (50ms–1000ms),
so turning the knob directly and immediately changes how fast the LED
blinks.

---

## ⬆️ Uploading Steps

1. Open the desired `.ino` file in the Arduino IDE.
2. Connect your Arduino board via USB.
3. Select **Tools → Board** and choose your board model.
4. Select **Tools → Port** and choose the correct COM/USB port.
5. Click **Upload** (→ icon) and wait for "Done uploading."
6. (Optional) Open **Tools → Serial Monitor** at **9600 baud** to view
   live output for v1.1, v1.2, and v1.3.

---

## ✅ Expected Output

| Version | Expected Behavior                                                  |
|---------|----------------------------------------------------------------------|
| v1.0    | LED blinks ON/OFF every 500ms, no Serial output                       |
| v1.1    | LED blinks every 500ms; Serial Monitor prints an incrementing count   |
| v1.2    | LED blink speed changes live as the potentiometer knob is turned      |
| v1.3    | Same as v1.2, plus a formatted startup banner and per-blink log line  |

---

## 🛠️ Troubleshooting

| Symptom                                  | Likely Cause                                | Fix                                             |
|--------------------------------------------|-----------------------------------------------|---------------------------------------------------|
| Upload fails with "port not found"         | Wrong COM port or driver not installed        | Reselect port; install CH340/FTDI driver if needed |
| LED doesn't blink at all                   | Wrong board selected, or bad USB cable        | Recheck **Tools → Board**; try a data-capable cable |
| Serial Monitor shows garbage characters    | Baud rate mismatch                            | Set Serial Monitor to **9600 baud**                |
| Potentiometer has no effect on blink speed | Wiper not connected to A0, or bad wiring       | Recheck breadboard connections                     |

---

## 📚 References

- [Arduino Official Blink Tutorial](https://docs.arduino.cc/built-in-examples/basics/Blink/)
- [Arduino `analogRead()` Reference](https://docs.arduino.cc/language-reference/en/functions/analog-io/analogRead/)
- [Arduino `map()` Reference](https://docs.arduino.cc/language-reference/en/functions/math/map/)

---

## 📄 License

This sub-project is part of `iot-summer-school-2026` and is released
under the [MIT License](../../LICENSE).
