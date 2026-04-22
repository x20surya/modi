import RPi.GPIO as GPIO
import time

# Pin setup
LED1 = 5
LED2 = 6
BUTTON = 13

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED1, GPIO.OUT)
GPIO.setup(LED2, GPIO.OUT)
GPIO.setup(BUTTON, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# User input (interval time)
interval1 = float(input("Enter blink interval for LED1 (seconds): "))
interval2 = float(input("Enter blink interval for LED2 (seconds): "))

current_led = 1  # Start with LED1

try:
    while True:
        # Check button press (toggle LED)
        if GPIO.input(BUTTON) == 0:
            print("Button Pressed - Switching LED")
            current_led = 2 if current_led == 1 else 1

            # Turn off both LEDs
            GPIO.output(LED1, False)
            GPIO.output(LED2, False)

            time.sleep(0.3)  # debounce

        # Blink logic
        if current_led == 1:
            GPIO.output(LED1, True)
            time.sleep(interval1)
            GPIO.output(LED1, False)
            time.sleep(interval1)

        else:
            GPIO.output(LED2, True)
            time.sleep(interval2)
            GPIO.output(LED2, False)
            time.sleep(interval2)

except KeyboardInterrupt:
    GPIO.cleanup()