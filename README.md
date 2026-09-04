# 🌱 Smart Irrigation System using Arduino

An **Arduino-based Smart Irrigation System** that automatically controls a water pump based on soil moisture levels. The system also monitors **temperature and humidity** using a DHT11 sensor and displays real-time information on a **16×2 I2C LCD**.

The main goal is to reduce water wastage and automate plant irrigation by turning the water pump ON when the soil becomes dry and OFF when sufficient moisture is detected.

---

## 🚀 Features

* 🌱 Automatic soil moisture monitoring
* 💧 Automatic water pump control
* 🔄 Hysteresis-based relay control to prevent rapid ON/OFF switching
* 🌡️ Temperature monitoring using DHT11
* 💦 Humidity monitoring using DHT11
* 📟 Real-time data displayed on a 16×2 I2C LCD
* 🖥️ Sensor readings available through the Serial Monitor
* ⚡ Relay-controlled water pump

---

## 🛠️ Hardware Requirements

| Component                           |    Quantity |
| ----------------------------------- | ----------: |
| Arduino Uno                         |           1 |
| Soil Moisture Sensor                |           1 |
| DHT11 Temperature & Humidity Sensor |           1 |
| 16×2 I2C LCD                        |           1 |
| Relay Module                        |           1 |
| Water Pump                          |           1 |
| Jumper Wires                        | As required |
| Breadboard                          |           1 |
| External Power Supply               |           1 |

---

## 🔌 Pin Configuration

| Component            | Arduino Pin |
| -------------------- | ----------- |
| Soil Moisture Sensor | A0          |
| Relay Module         | D7          |
| DHT11 Sensor         | D2          |
| LCD SDA              | A4          |
| LCD SCL              | A5          |
| LCD I2C Address      | `0x27`      |

> **Note:** The LCD I2C address may be different depending on your LCD module. Use an I2C scanner to find the correct address if `0x27` does not work.

---

## ⚙️ How It Works

The system continuously reads the soil moisture value from the soil moisture sensor.

### 🌵 When the soil is dry

If:

```text
Moisture Value < 480
```

the system turns the water pump **ON**.

### 💧 When the soil becomes sufficiently moist

If:

```text
Moisture Value > 520
```

the system turns the water pump **OFF**.

### 🔄 Hysteresis Control

The system uses two different moisture thresholds:

```cpp
#define MOISTURE_THRESHOLD_LOW 480
#define MOISTURE_THRESHOLD_HIGH 520
```

This prevents the relay from rapidly switching ON and OFF when the moisture value fluctuates around a single threshold.

---

## 📊 LCD Display

The LCD displays the current sensor readings.

Example:

```text
Moist:500
T:28.0C H:65.0%
```

Where:

* `Moist` → Soil moisture sensor value
* `T` → Temperature in Celsius
* `H` → Relative humidity percentage

---

## 🖥️ Serial Monitor

The Arduino also sends sensor data to the Serial Monitor at **9600 baud**.

Example:

```text
Soil Moisture: 495
Temperature: 28.00 °C, Humidity: 65.00 %
```

---

## 💻 Software Requirements

You need:

* [Arduino IDE](https://www.arduino.cc/en/software)
* Arduino board package
* `DHT` library
* `LiquidCrystal_I2C` library

### Required Libraries

```cpp
#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

---

## 📥 Installation

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
```

### 2. Open the Project

Open the `.ino` file in **Arduino IDE**.

### 3. Install Required Libraries

From Arduino IDE:

```text
Sketch
→ Include Library
→ Manage Libraries
```

Install:

* **DHT sensor library**
* **LiquidCrystal I2C**

### 4. Connect the Hardware

Connect the sensors, LCD, relay, and pump according to the pin configuration described above.

### 5. Upload the Code

Select:

```text
Tools → Board → Arduino Uno
Tools → Port → Your Arduino Port
```

Then click **Upload**.

### 6. Open Serial Monitor

Set the baud rate to:

```text
9600
```

---

## 🧠 Control Logic

```text
              ┌──────────────────┐
              │ Read Soil Moisture│
              └────────┬─────────┘
                       ↓
             ┌────────────────────┐
             │ Moisture < 480 ?   │
             └───────┬────────────┘
                     │ YES
                     ↓
              ┌──────────────┐
              │  Motor ON    │
              └──────────────┘

                     │
                     │
                     ↓
             ┌────────────────────┐
             │ Moisture > 520 ?   │
             └───────┬────────────┘
                     │ YES
                     ↓
              ┌──────────────┐
              │  Motor OFF   │
              └──────────────┘
```

The actual sensor values may vary depending on the type of soil, sensor, and environment. The thresholds should therefore be **calibrated for your setup**.

---

## 📁 Project Structure

```text
Smart-Irrigation-System/
│
├── SmartIrrigation.ino
├── README.md
└── LICENSE
```

---

## 🔧 Customization

You can change the moisture thresholds according to your soil and sensor readings:

```cpp
#define MOISTURE_THRESHOLD_LOW 480
#define MOISTURE_THRESHOLD_HIGH 520
```

For example:

```cpp
#define MOISTURE_THRESHOLD_LOW 450
#define MOISTURE_THRESHOLD_HIGH 550
```

You should test the sensor in both **dry and wet soil** before selecting the final values.

---

## ⚠️ Important Note About Relay

This project assumes an **active-LOW relay**, meaning:

```text
LOW  → Pump ON
HIGH → Pump OFF
```

If your relay module is **active-HIGH**, reverse the relay logic in the code.

Also, if you're controlling a mains-powered pump, use an appropriately rated relay and proper electrical isolation. Do not connect mains voltage directly to the Arduino.

---

## 🔮 Future Improvements

Possible improvements include:

* 📱 Mobile app monitoring
* ☁️ IoT/cloud integration
* 📊 Online sensor dashboard
* 🌦️ Weather-based irrigation
* 🌧️ Rain sensor integration
* 🔋 Solar-powered irrigation
* 📈 Historical moisture data
* 🤖 AI-based irrigation prediction
* 📲 Automatic notifications when water is needed

---

## 🎯 Project Objective

The objective of this project is to create a simple and cost-effective **automated irrigation system** that:

1. Detects soil moisture.
2. Automatically controls a water pump.
3. Monitors temperature and humidity.
4. Displays real-time environmental data.
5. Reduces unnecessary water consumption.

---

## 👩‍💻 Author

**Meherin Sohani**

Final-Year CSE Student
United International University (UIU), Bangladesh

---

## ⭐ Contributing

Contributions, suggestions, and improvements are welcome!

If you find this project useful, consider giving the repository a ⭐.

---

## 📄 License

This project is open-source and available under the **MIT License**.
