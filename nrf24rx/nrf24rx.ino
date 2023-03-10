#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

int leds[] = { D0, D1 };
int vals[] = { LOW, LOW };

const byte address[2][6] = { "00001", "00002" };

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address[0]);
  radio.openReadingPipe(1, address[1]);
  //radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  uint8_t pipe;
  if (radio.available(&pipe)) {
    char data[32] = {};
    radio.read(&data, sizeof(data));
    Serial.println(data);
    vals[pipe] = !vals[pipe];
    digitalWrite(leds[pipe], vals[pipe]);
  }
}
