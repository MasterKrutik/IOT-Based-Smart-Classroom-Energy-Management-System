#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define OLED_W 128
#define OLED_H 64
#define OLED_RST -1

#define PIN_DHT 2
#define DHT_TYPE DHT11

Adafruit_SSD1306 oled(OLED_W, OLED_H, &Wire, OLED_RST);
DHT dht(PIN_DHT, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.print("Temp: ");
  oled.println(temp);
  oled.print("Hum: ");
  oled.println(hum);
  oled.display();

  Serial.print("T=");
  Serial.print(temp);
  Serial.print(" H=");
  Serial.println(hum);

  delay(2000);
}
