# Smart Traffic Management & Pedestrian Safety System

An Arduino Uno-based **educational simulation** built in Tinkercad. It demonstrates a basic vehicle traffic-light sequence and a pedestrian crossing request using LEDs, a pushbutton, a buzzer, and a 16×2 LCD.

> **Safety note:** This is a classroom/demo simulation only. It is not designed, tested, or certified to control real road traffic or pedestrian crossings.

## Features

- Three vehicle signal indicators: red, yellow, and green.
- Dedicated pedestrian WALK and STOP indicators.
- Pushbutton input to request a pedestrian crossing.
- Buzzer alert during the crossing phase.
- 16×2 LCD status messages.
- Arduino control logic using digital input/output.

## Components

- Arduino Uno
- Five LEDs and suitable current-limiting resistors
- Pushbutton
- Piezo buzzer
- 16×2 LCD
- 10 kΩ potentiometer
- Breadboard and jumper wires

## Pin connections

| Component | Arduino connection |
|---|---|
| Vehicle red LED | D8 |
| Vehicle yellow LED | D9 |
| Vehicle green LED | D10 |
| Pedestrian WALK LED | D11 |
| Pedestrian STOP LED | D12 |
| Pedestrian pushbutton | D2 and GND (uses INPUT_PULLUP) |
| Buzzer positive | D6 |
| LCD RS | D7 |
| LCD Enable | D5 |
| LCD data D4, D5, D6, D7 | D4, D3, A0, A1 |
| LCD RW | GND |
| LCD VSS / VDD | GND / 5V |
| LCD VO | Potentiometer centre pin |
| LCD backlight A / K | 5V through suitable resistor / GND |

Connect the potentiometer's two outer pins to 5V and GND. Connect all circuit grounds together. Use suitable current-limiting resistors with LEDs.

## How it works

1. The vehicle signal turns red and the pedestrian WALK indicator turns on.
2. The LCD displays the crossing status and the buzzer gives an alert.
3. The system switches to a yellow caution phase.
4. The vehicle signal turns green and the pedestrian STOP indicator remains on.
5. If the pushbutton is pressed during the vehicle phase, the program shows a request message, switches through yellow, and then provides another pedestrian crossing phase.

## Run the simulation

1. Open the circuit in Tinkercad Circuits and select **Start Simulation**.
2. If recreating the circuit, follow the pin-connection table above.
3. Open `Code/Smart_Traffic_System.ino` and paste it into the Arduino code editor in Text mode.
4. Adjust the LCD contrast potentiometer if needed.
5. Test the pushbutton during the vehicle-green phase.

## Repository structure

```
smart-traffic-pedestrian-safety/
├── Code/
│   └── Smart_Traffic_System.ino
├── Documentation/
│   └── PROJECT_REPORT.md
└── README.md
```

## Concepts demonstrated

Arduino programming, digital input/output, conditional logic, timing, LCD interfacing, basic electronics, circuit simulation, and troubleshooting.

## Possible future improvements

- Use a non-blocking state-machine design with `millis()`.
- Add a countdown display for crossing time.
- Add a simulated vehicle/pedestrian sensor.
- Add a labelled circuit diagram and demonstration video.

## Author

Raksha Gajeshwar
