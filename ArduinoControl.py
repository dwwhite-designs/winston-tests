#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()


   """  while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
        ser.write("Hello from Raspberry Pi!\n".encode('utf-8'))
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(1) """
    
    while True:
    if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
    
    print("Enter a, s, d, or f")
    command = input()
    ser.write(command + "/n".encode('utf-8'))
    line = ser.readline().decode('utf-8').rstrip()
    print(line)
    time.sleep(1)