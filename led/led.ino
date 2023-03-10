#include <ESP8266WiFi.h>

int PIN = D2; // GPIO4

int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, state);
  randomSeed(analogRead(D3));
}

void loop() {

  digitalWrite(PIN, state);
  state = !state;
  delay(random(10,1000));

}
