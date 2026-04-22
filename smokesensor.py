import RPi.GPIO as GPIO
import time

GAS = 27

GPIO.setmode(GPIO.BCM)
GPIO.setup(GAS, GPIO.IN)

while True:
    if GPIO.input(GAS) == 0:
        print("Gas/Smoke Detected!")
    else:
        print("Safe Environment")
    time.sleep(1)