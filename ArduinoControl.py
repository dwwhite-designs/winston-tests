#!/usr/bin/env python3
import serial
import time
import bluetooth
import psutil


def write_read(inputs):
    arduino.write(bytes(inputs, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline().decode('utf-8').rstrip()
    return data




# Get a list of all processes on the system
processes = psutil.process_iter()

# Filter for processes related to Bluetooth
bluetooth_procs = [p for p in processes if p.name() == 'bluetoothd']

# Get the MAC addresses of the connected devices
connected_devices = []
for proc in bluetooth_procs:
    for conn in proc.connections():
        if conn.status == 'ESTABLISHED' and conn.laddr[1] == 1:
            connected_devices.append(conn.raddr[0])

# Print the MAC addresses of the connected devices
for address in connected_devices:
    print(f"Connected device with MAC address: {address}")


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