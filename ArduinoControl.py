#!/usr/bin/env python3
import serial
import time
import subprocess
import traceback

#Serial Commands
def write_serial(inputs):
    arduino.write(bytes(inputs, 'utf-8'))
    time.sleep(0.1)
    return

def read_serial():
    data = arduino.readline().decode('utf-8').rstrip()
    return data



#Bluetooth Connection
try:
    # Call the 'bluetoothctl' command to retrieve a list of connected devices
    process = subprocess.Popen(['bluetoothctl', 'paired-devices'], stdout=subprocess.PIPE)

    # Extract the MAC addresses of the connected devices
    output, error = process.communicate()
    connected_devices = []
    for line in output.decode().split('\n'):
        if 'Device' in line:
            parts = line.split()
            mac_address = parts[1]
            connected_devices.append(mac_address)

    # Print the MAC addresses of the connected devices
    for address in connected_devices:
        print(f"Connected device with MAC address: {address}")
except Exception as e:
    # Print the traceback error message
    print(f"Error occurred: {e}")
    traceback.print_exc()

#Serial Connection
try:
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

        write_serial(output)
        print(read_serial())
        #print(read_serial())
        time.sleep(1)
except Exception as e:
    # Print the traceback error message
    print(f"Error occurred: {e}")
    traceback.print_exc()