#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)

#define DHTPIN 2         // DHT sensor pin
#define DHTTYPE DHT11    // DHT 11

#define IR_SENSOR_ENTRY_PIN 9
#define IR_SENSOR_EXIT_PIN 8
#define RED_LED_PIN 3
#define GREEN_LED_PIN 4

#define TEMP_THRESHOLD 30.0   // Temperature threshold in °C
#define HUM_THRESHOLD 70.0    // Humidity threshold in %

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

int peopleCount = 0;
int peopleEntered = 0;
int peopleExited = 0;
float temperature;
float humidity;
bool dhtActive = false;
bool fanStatus = false;
bool greenLedStatus = false;

void setup() {
  Serial.begin(9600);
  pinMode(IR_SENSOR_ENTRY_PIN, INPUT);
  pinMode(IR_SENSOR_EXIT_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  dht.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
}

void loop() {
  if (digitalRead(IR_SENSOR_ENTRY_PIN) == LOW) {
    peopleEntered++;
    peopleCount++;
    dhtActive = true;
    greenLedStatus = true;
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on green LED when someone enters
    delay(500); // Debounce
  }

  if (digitalRead(IR_SENSOR_EXIT_PIN) == LOW) {
    peopleExited++;
    peopleCount = max(peopleCount - 1, 0); // Prevent negative count
    if (peopleCount == 0) {
      dhtActive = false;
      greenLedStatus = false;
      digitalWrite(GREEN_LED_PIN, LOW); // Turn off green LED when no one is present
    }
    delay(500); // Debounce
  }
  
  if (dhtActive) {
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    if (peopleCount > 0 && (temperature > TEMP_THRESHOLD || humidity > HUM_THRESHOLD)) {
      digitalWrite(RED_LED_PIN, HIGH); // Turn on red LED based on temp and humidity
      fanStatus = true;
    } else {
      digitalWrite(RED_LED_PIN, LOW); // Turn off red LED
      fanStatus = false;
    }
  } else {
    temperature = humidity = 0;
    digitalWrite(RED_LED_PIN, LOW); // Turn off red LED
    fanStatus = false;
  }

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.print("People Present: ");
  oled.println(peopleCount);
  oled.print("Temp: ");
  oled.print(temperature);
  oled.println(" C");
  oled.setCursor(0, 20);
  oled.print("Humidity: ");
  oled.print(humidity);
  oled.println(" %");
  oled.setCursor(0, 30);
  oled.print("Entered: ");
  oled.println(peopleEntered);
  oled.setCursor(0, 40);
  oled.print("Exited: ");
  oled.println(peopleExited);
  oled.setCursor(0, 50);
  oled.print("Fan Status: ");
  oled.println(fanStatus ? "ON" : "OFF");
  oled.setCursor(0, 60);
  oled.print("Light Status: ");
  oled.println(greenLedStatus ? "ON" : "OFF");
  oled.display();

  // Send data to ESP32
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(peopleCount);
  Serial.print(",");
  Serial.print(fanStatus ? 1 : 0); // Send fan status as 1 (ON) or 0 (OFF)
  Serial.print(",");
  Serial.println(greenLedStatus ? 1 : 0); // Send green LED status as 1 (ON) or 0 (OFF)

  delay(2000); // Update every 2 seconds
}
