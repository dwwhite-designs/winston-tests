import spidev

spi = spidev.SpiDev()
spi.open(0, 0)  # Open SPI bus 0, device 0
spi.max_speed_hz = 1000000  # Set SPI clock speed (optional)
# ... your main code

# Example: Send data to Arduino and receive a response
to_send = 0x0A  # Example data
response = spi.xfer2([to_send]) 
# ... rest of your code

spi.close()  # Close the SPI connection when done
