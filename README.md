# Arduino Temperature & Humidity Monitor

A simple Arduino project that reads temperature and humidity from a DHT11 sensor, displays the values on a 16x2 LCD, and indicates temperature ranges using coloured LEDs.

---

## Features

- Reads temperature (°C) and humidity (%) from a DHT11 sensor every 2 seconds
- Displays live readings on a 16x2 LCD screen
- Colour-coded LED status:
  - 🔴 **Red** — Hot (30°C and above)
  - 🟡 **Yellow** — Warm (20°C – 29°C)
  - 🔵 **Blue** — Cold (below 20°C)
- Displays a sensor error message and lights the red LED if the DHT11 fails to respond
- Outputs readings to the Serial Monitor at 9600 baud

---

## Hardware Required

| Component | Quantity |
|---|---|
| Arduino (Uno or compatible) | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| 16x2 LCD Display | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Blue LED | 1 |
| 220Ω resistors (for LEDs) | 3 |
| Breadboard & jumper wires | — |

---

## Pin Connections

### DHT11 Sensor
| DHT11 Pin | Arduino Pin |
|---|---|
| DATA | Digital 8 |
| VCC | 5V |
| GND | GND |

### 16x2 LCD (4-bit mode)
| LCD Pin | Arduino Pin |
|---|---|
| RS | Digital 12 |
| EN | Digital 11 |
| D4 | Digital 5 |
| D5 | Digital 4 |
| D6 | Digital 3 |
| D7 | Digital 2 |
| VCC | 5V |
| GND | GND |
| V0 (contrast) | 10kΩ potentiometer |

### LEDs
| LED | Arduino Pin |
|---|---|
| Red | Digital 9 |
| Yellow | Digital 10 |
| Blue | Digital 13 |

> Connect each LED in series with a 220Ω resistor to GND.

---

## Libraries Required

Install these via the Arduino IDE Library Manager (**Sketch → Include Library → Manage Libraries**):

- **DHT sensor library** by Adafruit
- **LiquidCrystal** (built into the Arduino IDE)

---

## Setup & Upload

1. Wire up the components as described above.
2. Open the `.ino` file in the Arduino IDE.
3. Install the required libraries.
4. Select your board: **Tools → Board → Arduino Uno** (or your board).
5. Select the correct port: **Tools → Port**.
6. Click **Upload**.
7. Open **Serial Monitor** (9600 baud) to view live sensor output.

---

## How It Works

Every 2 seconds the loop:
1. Reads temperature and humidity from the DHT11.
2. Prints the values to the Serial Monitor.
3. If the sensor returns an error (`NaN`), the LCD shows `Sensor Error!` and the red LED turns on.
4. Otherwise, the LCD shows the current temperature and humidity, and the LED colour updates based on the temperature threshold.

---

## Temperature Thresholds

| Condition | Range | LED |
|---|---|---|
| Hot | ≥ 30°C | 🔴 Red |
| Warm | 20°C – 29°C | 🟡 Yellow |
| Cold | < 20°C | 🔵 Blue |

---

## Troubleshooting

| Issue | Possible Cause | Fix |
|---|---|---|
| LCD shows nothing | Contrast too low | Adjust the potentiometer on V0 |
| `Sensor Error!` on LCD | Bad wiring or faulty DHT11 | Check DATA pin connection and power |
| Incorrect readings | DHT11 needs warm-up time | The 2-second startup delay handles this; wait a few seconds after power-on |
| No Serial output | Wrong baud rate | Make sure Serial Monitor is set to **9600** |
