# Arduino Sensor Modules Project

This repository contains documentation and example code for working with 7 different Arduino sensor modules. Each module includes connection instructions and basic Arduino code examples.

## 📋 Modules Included

1. **7-Color LED Flash Module** - Automatic RGB LED with preprogrammed sequence
2. **LM393 Speed Sensor with Perforated Disc** - Rotary speed measurement
3. **KY-012 Active Piezo Buzzer** - Sound output module
4. **KY-036 Metal-Touch Sensor** - Touch detection with analog/digital output
5. **KY-010 Light Barrier** - Object detection sensor
6. **KY-009 LED SMD Module** - RGB LED module
7. **KY-029 2-Color LED** - Red/Green LED module

## 🔌 Connection Diagrams

### 1. 7-Color LED Flash Module
Module → Arduino

VCC → 5V

GND → GND

SIG/OUT → Pin 13
### 2. LM393 Speed Sensor
Module → Arduino

VCC → 5V

GND → GND

DOUT → Pin 2
### 3. KY-012 Active Piezo Buzzer
Module → Arduino

GND → GND

SIG → Pin 13
### 4. KY-036 Metal-Touch Sensor
Module → Arduino

VCC → 5V

GND → GND

DOUT → Pin 7

AOUT → Pin A0
### 5. KY-010 Light Barrier
Module → Arduino

VCC → 5V

GND → GND

SIG → Pin 11
### 6. KY-009 LED SMD Module
Module → Arduino

Red → Pin 10 (with 180Ω resistor)

Green → Pin 11 (with 100Ω resistor)

Blue → Pin 12 (with 100Ω resistor)

GND → GND
### 7. KY-029 2-Color LED
Module → Arduino

SIG → Pin 10

VCC → Pin 11

GND → GND
*Note: Use 120Ω resistor for 3.3V, 220Ω for 5V*

## 🚀 Quick Start

1. Clone this repository
2. Open Arduino IDE
3. Navigate to `examples/complete_test/complete_test.ino`
4. Connect your sensors as shown in connection diagrams
5. Upload to Arduino Uno
6. Open Serial Monitor (9600 baud)

## 📁 Project Structure

## 🔧 Requirements

- Arduino IDE 1.8.x or later
- Arduino Uno or compatible
- USB cable
- Jumper wires
- Resistors: 100Ω, 120Ω, 180Ω, 220Ω

## 📚 Examples

Check the `examples/` directory for:
- Complete sensor test
- Individual module examples
- Advanced projects

## ⚠️ Safety Notes

1. Always disconnect power before wiring
2. Use current-limiting resistors for LEDs
3. Double-check connections before powering
4. Refer to datasheets for voltage limits

## 🤝 Contributing

Contributions welcome! Please read CONTRIBUTING.md first.

## 📄 License

MIT License - see LICENSE file for details.
