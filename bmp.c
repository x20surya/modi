#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_BMP085.h>

LiquidCrystal lcd(7,8,9,10,11,12);
Adafruit_BMP085 bmp;

void setup() {
  lcd.begin(16,2);
  bmp.begin();
}

void loop() {
  float t = bmp.readTemperature();
  float p = bmp.readPressure()/100;

  lcd.clear();
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(0,1);
  lcd.print("P:");
  lcd.print(p);

  delay(2000);
}