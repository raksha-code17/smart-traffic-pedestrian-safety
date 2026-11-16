# Project Report: Smart Traffic Management & Pedestrian Safety System

## 1. Introduction

The Smart Traffic Management & Pedestrian Safety System is an Arduino Uno-based educational prototype simulated in Tinkercad. It demonstrates how a microcontroller can coordinate vehicle signal indicators and pedestrian crossing indicators. A pushbutton allows a pedestrian to request a crossing phase. A buzzer and a 16×2 LCD provide audio and visual status information.

This project is intended for learning and demonstration. It is not a real-world traffic-control device.

## 2. Problem Statement

A basic traffic-light demonstration often shows only vehicle signals. This project extends that learning exercise by including pedestrian indicators and a request button, helping demonstrate how inputs, outputs, and programmed sequences can work together.

## 3. Objectives

- Build and simulate a traffic-light circuit using Arduino.
- Display vehicle and pedestrian status using separate LEDs.
- Read a pedestrian request using a pushbutton.
- Provide an audio alert during the crossing phase.
- Display system messages on a 16×2 LCD.
- Practise circuit wiring, embedded programming, and debugging.

## 4. Hardware and Software Requirements

**Hardware:** Arduino Uno, five LEDs, LED resistors, pushbutton, piezo buzzer, 16×2 LCD, 10 kΩ potentiometer, breadboard, and jumper wires.

**Software:** Tinkercad Circuits and Arduino C/C++.

## 5. Pin Configuration

| Device | Pin |
|---|---|
| Vehicle red LED | D8 |
| Vehicle yellow LED | D9 |
| Vehicle green LED | D10 |
| Pedestrian WALK LED | D11 |
| Pedestrian STOP LED | D12 |
| Pushbutton | D2 (other side to GND; INPUT_PULLUP) |
| Buzzer | D6 |
| LCD RS / Enable | D7 / D5 |
| LCD data D4–D7 | D4, D3, A0, A1 |
| LCD RW | GND |
| LCD contrast (VO) | Potentiometer centre pin |

LCD power: VSS to GND and VDD to 5V. Connect the backlight anode through a suitable resistor to 5V and the cathode to GND. Connect all grounds together.

## 6. Working Principle

The program starts by configuring the LEDs, pushbutton, buzzer, and LCD. It first enters a pedestrian crossing phase: vehicle red is ON, pedestrian WALK is ON, and the LCD displays the status. The buzzer produces a sequence of short alerts.

The system then enters a caution phase, turning on the vehicle yellow LED and pedestrian STOP LED. Next, the vehicle green LED turns on and the LCD indicates that pedestrians should wait. During this phase, the program checks the pushbutton. If a request is detected, the system changes to yellow, then red, and enables the pedestrian WALK indicator and buzzer alert.

## 7. Programming Concepts

- `pinMode()` configures input and output pins.
- `digitalWrite()` controls LED states.
- `digitalRead()` reads the pushbutton.
- `INPUT_PULLUP` uses the Arduino's internal pull-up resistor; a pressed button reads LOW.
- `if` statements handle the pedestrian request.
- `for` loops repeat buzzer alerts and button checks.
- The LiquidCrystal library controls the 16×2 LCD.
- `tone()` and `noTone()` control the buzzer.

## 8. Testing

The simulation can be checked by observing each traffic-light phase, confirming the WALK/STOP indicators change with the sequence, checking that LCD messages update, listening for the buzzer alert, and pressing the button during the vehicle-green phase to request a crossing.

## 9. Limitations and Safety

This is a simplified simulation. Its timing is implemented with blocking `delay()` calls, and button requests are checked only during a defined part of the cycle. It does not include certified traffic-control logic, fault detection, redundant hardware, or real-world sensor validation. **Do not connect this prototype to real traffic signals or use it to direct road users.**

## 10. Future Scope

- Replace blocking delays with a non-blocking state machine using `millis()`.
- Add a countdown timer to the LCD.
- Add simulated vehicle or pedestrian sensors.
- Improve button debouncing and request handling.
- Add a labelled circuit diagram and test screenshots.

## 11. Conclusion

The project demonstrates the integration of Arduino, LEDs, a pushbutton, a buzzer, and an LCD in a single simulated system. It provides practical experience with digital I/O, conditional logic, timing, circuit design, and troubleshooting, while introducing the idea of coordinated vehicle and pedestrian signals.
