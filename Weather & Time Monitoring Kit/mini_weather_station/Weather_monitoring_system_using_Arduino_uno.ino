#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --------------------
// LCD Setup
// --------------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --------------------
// DHT11 Setup
// --------------------
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// --------------------
// Sensor Pins
// --------------------
#define RAIN_SENSOR A0
#define LDR_SENSOR  A1

void setup() {

  Serial.begin(9600);

  // Start DHT Sensor
  dht.begin();

  // Start LCD
  lcd.begin();
  lcd.backlight();

  // Welcome Message
  lcd.setCursor(0, 0);
  lcd.print("Weather Monitor");

  lcd.setCursor(0, 1);
  lcd.print("System Starting");

  delay(2000);

  lcd.clear();
}

void loop() {

  // --------------------
  // Read Temperature & Humidity
  // --------------------

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // --------------------
  // Read Rain Sensor
  // --------------------

  int rainValue = analogRead(RAIN_SENSOR);

  // --------------------
  // Read LDR Sensor
  // --------------------

  int ldrValue = analogRead(LDR_SENSOR);

  // Convert LDR value to percentage
  int lightPercent = map(ldrValue, 0, 1023, 100, 0);

  // --------------------
  // Rain Detection
  // --------------------

  String rainStatus;

  if (rainValue < 500) {

    rainStatus = "YES";

  } else {

    rainStatus = "NO";
  }

  // --------------------
  // Serial Monitor Output
  // --------------------

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C  ");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  ");

  Serial.print("Rain: ");
  Serial.print(rainStatus);
  Serial.print("  ");

  Serial.print("Light: ");
  Serial.print(lightPercent);
  Serial.println("%");

  // --------------------
  // LCD Display
  // --------------------

  // First Line
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print((char)223); // Degree Symbol
  lcd.print("C ");

  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");

  // Second Line
  lcd.setCursor(0, 1);

  lcd.print("R:");
  lcd.print(rainStatus);

  lcd.print(" L:");
  lcd.print(lightPercent);
  lcd.print("% ");

  delay(2000);
}
