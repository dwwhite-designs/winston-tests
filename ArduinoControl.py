#!/usr/bin/env python3
import serial
import time
import subprocess


def write_read(inputs):
    arduino.write(bytes(inputs, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline().decode('utf-8').rstrip()
    return data




# Call the 'lsof' command to retrieve a list of open sockets
process = subprocess.Popen(['sudo', 'lsof', '-i'], stdout=subprocess.PIPE)

# Filter for Bluetooth sockets that are currently connected
output, error = process.communicate()
connected_devices = []
for line in output.decode().split('\n'):
    if 'bluetooth' in line and 'ESTABLISHED' in line:
        parts = line.split()
        mac_address = parts[-1].split(':')[0]
        if mac_address != '00:00:00:00:00:00':
            connected_devices.append(mac_address)

# Print the MAC addresses of the connected devices
for address in connected_devices:
    print(f"Connected device with MAC address: {address}")

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