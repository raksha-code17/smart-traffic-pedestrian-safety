#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 5, 4, 3, A0, A1);

const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int walkLED = 11;
const int stopLED = 12;
const int pedestrianButton = 2;
const int buzzer = 6;

void showMessage(const char *line1, const char *line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void crossingAlert() {
  for (int i = 0; i < 5; i++) {
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    delay(300);
  }
}

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(walkLED, OUTPUT);
  pinMode(stopLED, OUTPUT);
  pinMode(pedestrianButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  showMessage("SMART TRAFFIC", "SYSTEM READY");
  delay(2000);
}

void loop() {
  // Pedestrian crossing phase
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(walkLED, HIGH);
  digitalWrite(stopLED, LOW);
  showMessage("VEHICLES: STOP", "WALK: NOW");
  crossingAlert();
  delay(2500);

  // Transition / caution phase
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  digitalWrite(walkLED, LOW);
  digitalWrite(stopLED, HIGH);
  showMessage("CAUTION!", "PLEASE WAIT");
  delay(2000);

  // Vehicle movement phase
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  showMessage("VEHICLES: GO", "WALK: STOP");

  // Check for a pedestrian request during the vehicle phase
  bool request = false;
  for (int i = 0; i < 50; i++) {
    if (digitalRead(pedestrianButton) == LOW) {
      request = true;
      break;
    }
    delay(100);
  }

  if (request) {
    showMessage("CROSSING REQ.", "PLEASE WAIT");
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(2000);

    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(walkLED, HIGH);
    digitalWrite(stopLED, LOW);
    showMessage("VEHICLES: STOP", "WALK: NOW");
    crossingAlert();
    delay(2500);
  }
}
