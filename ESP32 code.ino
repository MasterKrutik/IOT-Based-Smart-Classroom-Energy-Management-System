#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";

unsigned long channelID = YOUR_CHANNEL_NUMBER;
const char* writeAPIKey = "YOUR_API_KEY";

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

  ThingSpeak.setField(1, temp); // temperature
  ThingSpeak.setField(2, hum);  // humidity

  ThingSpeak.writeFields(channelID, writeAPIKey);

  delay(15000); // ThingSpeak minimum delay
}
