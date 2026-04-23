#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal lcd(7,8,9,10,11,12);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.clear();
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print("%");

  delay(2000);
}