# 🚨 Arduino Foreign Body Detection System

This Arduino project detects nearby objects using an ultrasonic sensor. If an object is detected within 10 cm, it triggers a buzzer and displays a warning message on a 16x2 LCD display. It's a simple and effective setup for proximity alert systems.

## 🧰 Components

- Arduino Mega 2560 (or compatible board)
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display (LiquidCrystal)
- Buzzer
- Breadboard and Jumper Wires

## ⚙️ How It Works

1. The ultrasonic sensor continuously measures distance.
2. If no object is detected within 10 cm:
   - LCD displays: `Area is empty`
3. If an object is detected within 10 cm:
   - LCD displays: `Warning: Foreign Body`
   - Buzzer is activated to alert the user

## 📋 Code Overview

- The HC-SR04 sensor uses `trigPin` and `echoPin` to measure distance via sound waves.
- The LCD is controlled using the `LiquidCrystal` library.
- The buzzer is connected to a digital output pin.
- Logic is handled using a simple `if` statement to check distance and trigger alerts.

## 📷 Optional: Demo

Include a picture or video of your setup in action if available.

## 🚀 Future Improvements

- Add LED indicators (e.g., green for safe, red for detected)
- Log detection data to SD card
- Send alerts via Bluetooth or Wi-Fi (ESP8266/ESP32)
- Add a reset or mute button for the buzzer
