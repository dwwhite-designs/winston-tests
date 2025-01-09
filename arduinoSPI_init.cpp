#include <SPI.h>

const int slaveSelectPin = 10; // Chip Select Pin

void setup() {
  pinMode(slaveSelectPin, OUTPUT); 
  digitalWrite(slaveSelectPin, HIGH); // Disable SPI initially
  SPI.begin(); 
  SPI.setClockDivider(SPI_CLOCK_DIV8); // Set SPI clock speed (optional)
  // ... rest of your setup code
}

void loop() {
  // ... your main code
  if (digitalRead(slaveSelectPin) == LOW) { // Check if Pi is requesting data
    //  Put your SPI communication code here
    //  Example: Send data to Raspberry Pi
    SPI.transfer(someVariable);
  }
  // ... rest of your loop code
}
