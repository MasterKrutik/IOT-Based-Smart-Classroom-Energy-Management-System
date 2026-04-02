#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// === Display Settings ===
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET_PIN -1

// === Sensor & Actuator Pins ===
#define DHT_SENSOR_PIN 2
#define DHT_SENSOR_TYPE DHT11
#define ENTRY_PIN 9
#define EXIT_PIN 8
#define FAN_LED_PIN 3
#define ROOM_LED_PIN 4

// === Thresholds ===
#define TEMP_LIMIT 30.0
#define HUM_LIMIT 70.0

Adafruit_SSD1306 screen(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET_PIN);
DHT climate(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// === State Variables ===
int currentOccupancy = 0;
int totalEntered = 0;
int totalExited = 0;
float tempReading = 0;
float humReading = 0;
bool climateActive = false;
bool fanOn = false;
bool roomLightOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(ENTRY_PIN, INPUT);
  pinMode(EXIT_PIN, INPUT);
  pinMode(FAN_LED_PIN, OUTPUT);
  pinMode(ROOM_LED_PIN, OUTPUT);

  climate.begin();
  screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  screen.clearDisplay();
}

void loop() {
  // Entry detection
  if (digitalRead(ENTRY_PIN) == LOW) {
    totalEntered++;
    currentOccupancy++;
    climateActive = true;
    roomLightOn = true;
    digitalWrite(ROOM_LED_PIN, HIGH);
    delay(300); // shorter debounce
  }

  // Exit detection
  if (digitalRead(EXIT_PIN) == LOW) {
    totalExited++;
    currentOccupancy = max(currentOccupancy - 1, 0);
    if (currentOccupancy == 0) {
      climateActive = false;
      roomLightOn = false;
      digitalWrite(ROOM_LED_PIN, LOW);
    }
    delay(300);
  }

  // Climate control
  if (climateActive) {
    tempReading = climate.readTemperature();
    humReading = climate.readHumidity();
    if (currentOccupancy > 0 && (tempReading > TEMP_LIMIT || humReading > HUM_LIMIT)) {
      digitalWrite(FAN_LED_PIN, HIGH);
      fanOn = true;
    } else {
      digitalWrite(FAN_LED_PIN, LOW);
      fanOn = false;
    }
  } else {
    tempReading = humReading = 0;
    digitalWrite(FAN_LED_PIN, LOW);
    fanOn = false;
  }

  // Display info
  screen.clearDisplay();
  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(0, 0);
  screen.printf("Occupancy: %d\n", currentOccupancy);
  screen.printf("Temp: %.1f C\n", tempReading);
  screen.setCursor(0, 20);
  screen.printf("Humidity: %.1f %%\n", humReading);
  screen.setCursor(0, 30);
  screen.printf("Entered: %d\n", totalEntered);
  screen.setCursor(0, 40);
  screen.printf("Exited: %d\n", totalExited);
  screen.setCursor(0, 50);
  screen.printf("Fan: %s\n", fanOn ? "ON" : "OFF");
  screen.setCursor(0, 60);
  screen.printf("Light: %s\n", roomLightOn ? "ON" : "OFF");
  screen.display();

  // Serial output
  Serial.printf("%.1f,%.1f,%d,%d,%d\n",
                tempReading,
                humReading,
                currentOccupancy,
                fanOn ? 1 : 0,
                roomLightOn ? 1 : 0);

  delay(2000);
}
