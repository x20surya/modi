#include <LiquidCrystal.h>

#define SOIL A0

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  int val = analogRead(SOIL);

  lcd.clear();
  lcd.print("Moisture:");
  lcd.setCursor(0,1);
  lcd.print(val);

  delay(1000);
}