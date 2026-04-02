#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";

unsigned long channelID = 2699677;
const char* writeAPIKey = "0JNA7MB8ISFV44NM";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  ThingSpeak.begin(client);
}

void loop() {
  // Dummy values for now
  float temp = 25.0;
  float hum = 60.0;
  int people = 3;
  int fanStatus = 1; // 1 = ON, 0 = OFF

  ThingSpeak.setField(1, temp);       // temperature
  ThingSpeak.setField(2, hum);        // humidity
  ThingSpeak.setField(3, people);     // people count
  ThingSpeak.setField(4, fanStatus);  // fan status

  ThingSpeak.writeFields(channelID, writeAPIKey);

  delay(15000); // ThingSpeak minimum delay
}
