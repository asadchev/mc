#include <ESP8266WiFi.h>
#include <Servo.h>

Servo servo;
int position = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(D0);
}

void loop() {

  if (position == 0) position = 180;
  else if (position == 180) position = 0;

  Serial.println(position);
  servo.write(position);

  delay(1000);

}
