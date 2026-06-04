#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;

void setup() {

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Digital Clock");
  delay(2000);

  lcd.clear();

  // Check RTC
  if (!rtc.begin()) {
    lcd.setCursor(0,0);
    lcd.print("RTC ERROR");
    while (1);
  }

  // SET TIME AND DATE HERE
  rtc.adjust(DateTime(2026, 5, 16, 5, 36, 0));s

}

void loop() {

  DateTime now = rtc.now();

  // TIME
  lcd.setCursor(0,0);

  if(now.hour() < 10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(":");

  if(now.minute() < 10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(":");

  if(now.second() < 10) lcd.print("0");
  lcd.print(now.second());

  lcd.print(" ");

  // DATE
  lcd.setCursor(0,1);

  if(now.day() < 10) lcd.print("0");
  lcd.print(now.day());
  lcd.print("/");

  if(now.month() < 10) lcd.print("0");
  lcd.print(now.month());
  lcd.print("/");

  lcd.print(now.year());

  lcd.print(" ");

  delay(1000);
}