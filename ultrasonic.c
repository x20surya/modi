#include <LiquidCrystal.h>

#define TRIG 3
#define ECHO 4

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float dist = duration * 0.034 / 2;

  lcd.clear();
  lcd.print("Dist:");
  lcd.print(dist);
  lcd.print("cm");

  delay(1000);
}