#!/usr/bin/env python3
import serial
import time
import bluetooth


def write_read(inputs):
    arduino.write(bytes(inputs, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline().decode('utf-8').rstrip()
    return data


paired_devices = bluetooth.bonded_devices()
for address in paired_devices:
    print(f"Paired device with MAC address: {address}")

if __name__ == '__main__':
    arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=0.1)
    arduino.reset_input_buffer()

    x = True

    arduino.write("Starting up connection./n".encode('utf-8'))


    while x:
        if arduino.in_waiting > 0:
            line = arduino.readline().decode('utf-8').rstrip()
            print(line)
    
        print("Enter a, s, d, or f.")
        command = input()
        if command == 'f':
            x = False
        output = command + "/n"

        line = write_read(output)
        print(line)
        time.sleep(1)