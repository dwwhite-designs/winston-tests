void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    int data_len = data.length() + 1;
    char dataCh[data_len];
    data.toCharArray(dataCh,data_len);


    Serial.print("You sent me: ");
    Serial.println(data);
    

    switch (dataCh[0]) {
      case 'a':
        Serial.println("Moving forward.");
        break;
      case 's':
        Serial.println("Moving backwards.");
        break;
      case 'd':
        Serial.println("Turning.");
        break;
      case 'f':
        Serial.println("Stopping.");
        break;
    }
  }
}