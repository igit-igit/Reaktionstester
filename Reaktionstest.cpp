#include "Arduino.h"
#include "Reaktionstest.h"

//Zeitzähler 32 Bit groß
unsigned long start_time;
unsigned long react_time;
unsigned long random_time;
unsigned int num_of_leds;
unsigned int pressed;

RT::RT(){  
  //Pins definieren
  led1 = 3;
  led2 = 4;
  led3 = 5;
  led4 = 6;
  led5 = 7;
  led6 = 8;
  led7 = 9;
  buttonPin = 2;
  //LEDs und Button initialisieren
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(buttonPin, INPUT);
  pressed = 0;
}

//Zustände
void RT::oneLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}

void RT::twoLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}

void RT::threeLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}
void RT::fourLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}
void RT::fiveLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}
void RT::sixLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW);
}
void RT::sevenLed () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
}

//Einschaltanimation
void RT::animation() {
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led5, HIGH);
  delay(300);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led1, HIGH);
  delay(300);
  // zweiter durchgang
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(300);
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led7, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led7, LOW);
  delay(500);
  reset();
  delay(2000);
}

void RT::reset () {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  pressed = 0;
}

void RT::testAnimation () {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  delay(100);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
}

// Funktion, die langes halten ermöglicht
void RT::wait_until_release() {
  while (digitalRead(buttonPin) != LOW) {
    // digitalWrite(led7, HIGH);
    delay(100);
  }
  // digitalWrite(led7, LOW);
}

void RT::start_test(){
  // Test aktivieren
  if (digitalRead(buttonPin) == HIGH) {
    pressed = pressed + 1;
    wait_until_release();
  }
  // Test starten
  if (pressed == 2) {
    test_loop();
    delay(4000);
    reset();
  }
}

void RT::test_loop() {
  //Zeitmessung starten
  start_time = millis();
  //Generieren der Zufallszeit
  random_time = random(10001);
  //Ausgabe der Zufallszeit
  Serial.println(random_time);
  // TestAnimation
  while ((millis() - start_time < random_time)) {
    testAnimation();
  }
  reset();
  // Zeitmessung nach dem alle LEDs ausgschaltet sind
  start_time = millis();
  // Solange nicht gedrückt wurde bleibt er in while, wenn HIGH geht er aus while raus und
  // errechnet die Reaktionszeit
  while (digitalRead(buttonPin) != HIGH) {
  }
react_time = millis() - start_time;
Serial.println(react_time);
num_of_leds = react_time;

switch (num_of_leds) {
  // Ab 140 beginnen damit der benutzer nicht dauerhaft drückt und 1 led angezeigt wird
case 140 ... 174:
  oneLed();
  break;

case 175 ... 200:
  twoLed();
  break;

case 201 ... 300:
  threeLed();
  break;

case 301 ... 400:
  fourLed();
  break;

case 401 ... 500:
  fiveLed();
  break;

case 501 ... 600:
  sixLed();
  break;

  // Auf 7 LEDs begrenzt -> alles über 600 ms mit 7 LEDs anzeigen
default:
  sevenLed();
  break;
}
}
