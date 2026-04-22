import Adafruit_DHT

sensor = Adafruit_DHT.DHT11
pin = 4

while True:
    humidity, temperature = Adafruit_DHT.read(sensor, pin)

    if humidity and temperature:
        print("Temp:", temperature, "°C  Humidity:", humidity, "%")