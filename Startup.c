#include <Wire.h>
#include <PWMServo.h>
//#include <SoftwareSerial.h>

// Servo channel on the PCA9685
#define SERVO_CHANNEL 0

// Minimum distance to stop rotation
#define MIN_DISTANCE 5

// SoftwareSerial for Bluetooth communication
#define RX_PIN 10
#define TX_PIN 11
//SoftwareSerial bluetooth(RX_PIN, TX_PIN);



//PWMServo servo;
bool rotate = false;

void setup() {
  wiringPiSetupGpio (void);
  //servo.begin();
  //bluetooth.begin(9600);
}

void loop() {
  //checkBluetooth();
  //checkServo();
}
/*
void checkBluetooth() {
  while (bluetooth.available()) {
    // receive command from Bluetooth device
    char command = bluetooth.read();
    if (command == 's') {
      // start rotation
      startServo();
    } else if (command == 't') {
      // stop rotation
      stopServo();
    }
  }
}

void checkServo() {
  if (rotate) {
    int distance = getDistance();
    if (distance < MIN_DISTANCE) {
      // object is too close, stop the servo
      stopServo();
    } else {
      // object is far enough away, rotate clockwise
      rotateServo();
    }
  }
}

void startServo() {
  rotate = true;
}

void stopServo() {
  rotate = false;
  servo.write(SERVO_CHANNEL, 90);
}

void rotateServo() {
  servo.write(SERVO_CHANNEL, 0);
  delay(20);
}

int getDistance() {
  // code to get the distance reading from the LIDAR sensor
  // ...
  return distance;
}
*/