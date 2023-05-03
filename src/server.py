import serial
import time

with serial.Serial("COM3") as ser:
    time.sleep(2)
    ser.write(b"Python")
    time.sleep(3)
    ser.write(b"\nline 2")