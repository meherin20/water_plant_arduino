#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
#define SOIL_SENSOR_PIN A0
#define RELAY_PIN 7
#define DHT_PIN 2
#define DHT_TYPE DHT11

// Moisture Thresholds for Hysteresis
#define MOISTURE_THRESHOLD_LOW 480  // Turn ON motor below this
#define MOISTURE_THRESHOLD_HIGH 520 // Turn OFF motor above this

// Initialize DHT and LCD
DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // if scanner shows 0x27
 // Try 0x27 if this doesn't work

bool motorOn = false;

void setup()
{
  Serial.begin(9600);
  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Motor off by default

  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  delay(2000);
}

void loop()
{
  int moistureValue = analogRead(SOIL_SENSOR_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moist:");
  lcd.print(moistureValue);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("%");

  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Hysteresis logic to prevent relay flickering
  if (!motorOn && moistureValue < MOISTURE_THRESHOLD_LOW)
  {
    digitalWrite(RELAY_PIN, LOW); // ON if active LOW
    motorOn = true;
  }
  else if (motorOn && moistureValue > MOISTURE_THRESHOLD_HIGH)
  {
    digitalWrite(RELAY_PIN, HIGH); // OFF if active LOW
    motorOn = false;
  }

  delay(1000); // Delay between readings
}