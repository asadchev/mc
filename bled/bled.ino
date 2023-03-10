#include <ESP8266WiFi.h>

int LED = D2; // GPIO4
int BTN = 16; // GPI16

int state = 1;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  digitalWrite(LED, state);
  //delay(1000);
}

void loop() {

  // if (digitalRead(BTN)) {
  //   while (digitalRead(BTN));
  //   state = !state;
  // }

  state = digitalRead(BTN);
  digitalWrite(LED, state);

  //Serial.print(state);
  //delay(1000);

}
