# IOT-Based-Smart-Classroom-Energy-Management-System

# Introduction

Energy efficiency and automation are becoming essential in modern educational environments. Classrooms often waste electricity when lights and fans remain ON even when no one is present or when environmental conditions do not require them. This project introduces a smart classroom monitoring system built using Arduino Uno, PIR sensors, DHT11, OLED display, and LEDs. The system automatically controls lights based on human presence and simulates fan control based on temperature and humidity thresholds. Real‑time data is displayed on an OLED screen, while an ESP32 module enables remote monitoring and potential cloud integration. The project demonstrates how low‑cost hardware can be combined to create intelligent, responsive, and sustainable infrastructure.


# Problem Statement

Traditional classrooms rely on manual switching of lights and fans, which often leads to:
- Energy wastage when devices remain ON in empty rooms.
  
- Lack of environmental awareness, as fans or AC units may run unnecessarily even under comfortable conditions.
  
- No real‑time monitoring, making it difficult to track occupancy or environmental status.
  
This project addresses these issues by automating control systems using sensors and microcontrollers, ensuring that energy is used only when needed.


# Features
- Automatic light control using PIR sensors (entry/exit detection).
- Fan simulation based on temperature and humidity thresholds.
- Real-time monitoring on OLED display.
- Occupancy count tracking.
- Remote monitoring via ESP32 (cloud-ready).
- Low-cost, scalable, and sustainable design.
  

# Cloud Integration (ThingSpeak)
This project uses ThingSpeak, an IoT analytics platform, to enable cloud-based monitoring and data logging.
🔹 How It Works

   - The Arduino Uno sends sensor data (temperature, humidity, occupancy, fan/light status) to the ESP32 via serial communication.
   - The ESP32 uploads this data to ThingSpeak using Wi-Fi.
   - ThingSpeak stores the data in channels and provides real-time visualization through graphs and dashboards.
   - Users can remotely monitor classroom conditions and energy usage trends from anywhere.

🔗 Live Channel
[View My ThingSpeak Channel] (https://thingspeak.com/channels/2699577)

  

 # Software & Libraries
- Arduino IDE
- Libraries:
   - Wire.h
   - Adafruit_GFX.h
   - Adafruit_SSD1306.h
   - DHT.h


# Hardware Components and Their Functions 

## 1. PIR Sensors (Entry & Exit)
   
   - Detect human motion at the classroom entrance and exit.
     
   - Entry sensor → increments people count, turns ON green LED (lights).
     
   - Exit sensor → decrements people count, turns OFF green LED when room is empty.

## 2. DHT11 Sensor
   
   - Measures temperature and humidity.
     
   - If values exceed thresholds (30°C or 70% humidity) → red LED ON (fan ON simulation).
     
   - Otherwise → red LED OFF.

     
## 3. OLED Display
   
   - Shows real-time information:
     
     - People present
     
     - Temperature & humidity
     
     - Number entered/exited
     
     - Fan status (ON/OFF)
     
     - Light status (ON/OFF)
     
## 4. Green LED
   
   - Simulates classroom lights.
     
   - Turns ON when someone enters, OFF when no one is present.
     
## 5. Red LED
    
   - Simulates the fan.
     
   - Turns ON when temperature or humidity crosses threshold values, OFF otherwise.
     
## 6. Arduino Uno
    
   - Central microcontroller that reads sensor inputs, processes logic, and controls outputs (LEDs, OLED).
     
## 7. ESP32 (via Serial)
    
   - Wi-Fi enabled microcontroller used for transmitting data to the cloud or remote monitoring.
     
   -  Receives data from Arduino (temperature, humidity, people count, fan/light status).
      
## 8. Breadboard & Jumper Wires
    
   - Used for prototyping and connecting all components without soldering.


##🔍 SWOT Analysis
### Strengths
- Automation: Lights and fans controlled automatically based on occupancy and environmental conditions.

- Low Cost: Uses affordable components (Arduino, ESP32, PIR, DHT11, LEDs).

- Cloud Integration: ThingSpeak enables remote monitoring and data visualization.

- Scalability: Can be extended to multiple classrooms or integrated into a smart campus.

- Energy Efficiency: Reduces wastage by ensuring devices are ON only when needed.

### Weaknesses
- Prototype Limitations: LEDs simulate appliances instead of controlling real fans/lights.

- Sensor Accuracy: DHT11 has limited precision compared to advanced sensors.

- Wi‑Fi Dependence: ESP32 requires stable connectivity; interruptions cause data loss.

- Basic Analytics: ThingSpeak provides visualization but lacks advanced predictive models.

- Limited Coverage: Designed for small/medium classrooms; scaling requires more hardware.

### Opportunities
- Advanced Sensors: Upgrade to DHT22, CO₂, or light sensors for richer data.

- Machine Learning: Predict occupancy, energy usage, and faults using AI models.

- Mobile App Integration: Push notifications for administrators and teachers.

- Smart Campus Expansion: Centralized dashboard for multiple classrooms.

- Sustainability: Link with solar panels or smart grids for eco‑friendly energy management.

### Threats
- Connectivity Issues: Poor Wi‑Fi can disrupt cloud logging and monitoring.

- Hardware Failures: Sensor malfunctions may lead to incorrect automation.

- Data Security: Cloud integration requires secure authentication to prevent misuse.

- Adoption Barriers: Schools may hesitate to adopt due to cost or technical expertise.

- Competition: Commercial smart classroom solutions may offer more polished features.


## Key Takeaways

 - Automation significantly reduces unnecessary energy consumption.

 - Cloud dashboards (ThingSpeak) enhance transparency and remote accessibility.

 - The system can be scaled to real fans, lights, and AC units for practical deployment.

 - Future improvements could include machine learning for predictive energy usage and mobile app notifications for administrators.
   
