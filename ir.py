import RPi.GPIO as GPIO
import time

IR = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(IR, GPIO.IN)

while True:
    if GPIO.input(IR) == 0:
        print("Object Detected")
    else:
        print("No Object")
    time.sleep(1)