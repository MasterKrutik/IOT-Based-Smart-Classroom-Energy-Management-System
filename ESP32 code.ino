#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "yourSSID";
const char* password = "yourPASSWORD";
unsigned long myChannelNumber = 2699677;
const char* myWriteAPIKey = "0JNA7MB8ISFV44NM";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  
  ThingSpeak.begin(client);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    Serial.println("Received data: " + data); // Print received data

    int commaIndex1 = data.indexOf(',');
    int commaIndex2 = data.indexOf(',', commaIndex1 + 1);
    int commaIndex3 = data.indexOf(',', commaIndex2 + 1);
    int commaIndex4 = data.indexOf(',', commaIndex3 + 1);

    float temperature = data.substring(0, commaIndex1).toFloat();
    float humidity = data.substring(commaIndex1 + 1, commaIndex2).toFloat();
    int peopleCount = data.substring(commaIndex2 + 1, commaIndex3).toInt();
    int fanStatus = data.substring(commaIndex3 + 1, commaIndex4).toInt();
    int greenLedStatus = data.substring(commaIndex4 + 1).toInt();

    Serial.print("People Present: ");
    Serial.println(peopleCount);
    Serial.print("Fan Status: ");
    Serial.println(fanStatus ? "ON" : "OFF");
    Serial.print("Light Status: ");
    Serial.println(greenLedStatus ? "ON" : "OFF");

    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humidity);
    ThingSpeak.setField(3, peopleCount);
    ThingSpeak.setField(4, fanStatus);
    ThingSpeak.setField(5, greenLedStatus);
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  }

  delay(2000); // Update every 2 seconds
}
