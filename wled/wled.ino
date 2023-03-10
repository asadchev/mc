#include <ESP8266WiFi.h>

int PIN = D1; // GPIO5
const char pass[] = "password";
const char name[] = "esp8266" ;

WiFiServer server(80);
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  auto conn = WiFi.softAP(name);
  server.begin();
  digitalWrite(PIN, state);
}

void loop() {

  WiFiClient client = server.available();
  if (!client)  {  return;  }

  auto request = client.readStringUntil('\r');

  if (request.startsWith("POST")) {
    //request = client.readString();
    {//if (request.indexOf("action=toggle") > -1) {
      //Serial.print(request);
      state = !state;
    }
  }
  //client.flush();

  digitalWrite(PIN, state);

  client.print(
    "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
    "<html>"
    "<body>"
    "<div><h2>ESP32 LED</h2></div>"
  );

  client.print(state ? "LED OFF" : "LED ON");

  client.print(
    "<form action=\"\" method=\"post\">"
    "<input type=\"submit\" name=\"action\" value=\"toggle\" />"
    "</form>"
    "</body>"
    "</html>"
  );

  client.stop();

}
