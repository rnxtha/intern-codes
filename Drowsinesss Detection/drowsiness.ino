const int relayPin = 7;
char command;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  
  // Start with motor ON (eyes assumed open)
  digitalWrite(relayPin, LOW);
  Serial.println("Arduino Ready - Motor ON");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    // Use if-else to ensure only one action per command
    if (command == '0') {
      digitalWrite(relayPin, HIGH);  // STOP motor (relay OFF - active low)
      Serial.println("Motor STOPPED");
    }
    else if (command == '1') {
      digitalWrite(relayPin, LOW);   // RUN motor (relay ON)
      Serial.println("Motor RUNNING");
    }
    // Ignore any other characters (noise, newlines, etc.)

    // Clear any remaining bytes in buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}