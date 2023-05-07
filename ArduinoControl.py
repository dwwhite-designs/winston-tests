#!/usr/bin/env python3
import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()

    x = True

    ser.write("Starting up connection./n".encode('utf-8'))


    while x:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
    
        print("Enter a, s, d, or f.")
        command = input()
        if command == 'f':
            x = False
        output = command + "/n"

        ser.write(output.encode('utf-8'))
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(1)