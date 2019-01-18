//Projekt eingebettete Software WS 1819
//heiko Jedamski
//Reaktionstester

//Der Tester soll wie folgt benutzt werden:
//Nach dem Einschalten zeigt der Tester eine
//Einschaltanimation und geht dann in Ruhezustand über
//Durch drücken der Taste wird der Tester aktiviert.
//Der Benutzer drück die Taste erneut, um den Test zu starten.
// Daraufhin wird eine Animation gezeigt und nach einer
// zufälligen Zeit gehen schließlich alle LEDs aus.
// Der Benutzer soll dann schnell wie möglich wieder
// den Knopf drücken. Die Zeit vom Erlöschen der LEDs
// bis zum Drücken wird gemessen und dann mit den LEDs
// angezeigt(100ms 1 LED) Dieser Vorgang kann beliebig
// häufig wiederholt werden, um weitere Tests zu machen.
// Nach einer bestimmten Zeit des Nicht-Benutzt-Werdens
// geht der Reaktionstester in den Ruhezustand.

#include "Reaktionstest.h"

// Objekt erzeugen
RT reaktionstester;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  reaktionstester.animation();
}

void loop() {
  reaktionstester.start_test();
}
