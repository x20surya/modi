#include <LiquidCrystal.h>

#define IR 5

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  pinMode(IR, INPUT);
  lcd.begin(16,2);
}

void loop() {
  int val = digitalRead(IR);

  lcd.clear();
  if(val == LOW)
    lcd.print("Object Found");
  else
    lcd.print("No Object");

  delay(500);
}