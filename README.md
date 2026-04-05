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


