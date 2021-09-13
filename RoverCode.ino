//Initialize Motor Code
// Motor One
int ENA = 6;
int IN1 = 7;
int IN2 = 8;
// Motor Two
int ENB = 11;
int IN3 = 9;
int IN4 = 10;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  mySerial.begin(9600);
  Serial.begin(9600);

  digitalWrite(ENA, 255);
  digitalWrite(ENB, 255);
}

void loop() {
  char transmission;
  char c;
  boolean NL = true;
  if (mySerial.available()) {
    transmission = mySerial.read();
    delay(100);
    Serial.write(transmission);
  }

  if (Serial.available()) {
    c = Serial.read();
        // do not send line end characters to the HC-06
        if (c!=10 & c!=13 ) 
        {  
             mySerial.write(c);
        }
        Serial.write(c);
  }
  switch (transmission) {

    case 'F':
      goStraight();
      break;

    case 'B':
      reverse();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
      break;

    default:
      stopMoving();
      break;
  }
}

void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);


}

void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void stopMoving() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void goStraight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void reverse() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}
