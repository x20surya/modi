import adafruit_dht
import board
import time

# Initialize sensor (GPIO4 → board.D4)
dht = adafruit_dht.DHT11(board.D4)

while True:
    try:
        temperature = dht.temperature
        humidity = dht.humidity

        if humidity is not None and temperature is not None:
            print("Temp:", temperature, "°C  Humidity:", humidity, "%")

    except RuntimeError:
        # Happens often with DHT sensors — safe to ignore
        pass
    except Exception as e:
        dht.exit()
        raise e

    time.sleep(2)