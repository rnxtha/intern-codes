#include <Servo.h>

Servo servoBase; // The one on the table
Servo servoArm;  // The "hanged" one

// Use A0 and A1 for joysticks
int joyX = A0; 
int joyY = A1;

int currentPos1 = 90; 
int currentPos2 = 90;

void setup() { 
  servoBase.attach(3);
  servoArm.attach(5);
  
  servoBase.write(currentPos1);
  servoArm.write(currentPos2);
}

void loop() {
  // Read joystick and map to degrees
  int targetX = map(analogRead(joyX), 0, 1023, 0, 180);
  int targetY = map(analogRead(joyY), 0, 1023, 0, 180);

  // MOVE BOTH AT ONCE: Step current position toward target
  if (currentPos1 < targetX) currentPos1++;
  else if (currentPos1 > targetX) currentPos1--;

  if (currentPos2 < targetY) currentPos2++;
  else if (currentPos2 > targetY) currentPos2--;

  // Write updated positions
  servoBase.write(currentPos1);
  servoArm.write(currentPos2);

  delay(15); // Adjust this for speed (lower is faster)
}