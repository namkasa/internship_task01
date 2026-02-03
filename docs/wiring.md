# Wiring Guide

## Required Components
- Arduino Uno
- Breadboard
- Jumper wires (M-M)
- Resistors: 100Ω, 120Ω, 180Ω, 220Ω

## Connection Tables
some of the connections require resistors 
### Complete Setup Wiring
| Sensor | Arduino Pin | Resistor | Notes |
|--------|-------------|----------|-------|
| 7-Color LED SIG | 13 | None | Automatic |
| Speed Sensor DOUT | 2 | None | Interrupt pin |
| Buzzer SIG | 13 | None | Shares pin |
| Touch Digital | 7 | None | Digital out |
| Touch Analog | A0 | None | Analog out |
| Light Barrier | 11 | None | Normally HIGH |
| RGB Red | 10 | 180Ω | For red LED |
| RGB Green | 11 | 100Ω | Shares pin |
| RGB Blue | 12 | 100Ω | |
| 2-Color SIG | 10 | 220Ω | Shares pin |
| 2-Color VCC | 11 | 220Ω | Shares pin |

## Power Connections
- All VCC pins → Arduino 5V
- All GND pins → Arduino GND

## Important Notes
1. Pin 11 and 13 are shared by multiple sensors
2. Always use resistors with LEDs
3. Speed sensor uses interrupt on pin 2
4. Touch sensor has both analog and digital outputs
