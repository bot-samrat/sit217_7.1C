int buzzer = 12;
int LED = 11;

byte alarmOn = false;
char c=' ';
boolean NL = true;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  char transmission = ' ';  
  if (mySerial.available()) {
    transmission = mySerial.read();
    delay(100);
    Serial.print("Received Transmission: ");
    Serial.println(transmission);
  }

  // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
 
        // do not send line end characters to the HM-10
        if (c!=10 & c!=13 ) 
        {  
             mySerial.write(c);
        }
 
        // Echo the user input to the main window. 
        // If there is a new line print the ">" character.
        Serial.write(c);
    }

  if (alarmOn) {
    alarm();
    Serial.println("Alarm active");
  } if (!alarmOn) {
    alarmOff();
  }

  if (transmission == 'I') {
    if (!alarmOn) {
      alarmOn = true;
    } else if (alarmOn) {
      alarmOn = false;
      Serial.println("Alarm Disabled");
      alarmOff();
    }
  }

 

}

void alarm() {
  Serial.println("Alarm Triggered");
  digitalWrite(buzzer, HIGH); 
  digitalWrite(LED, HIGH);
  delay(500);            
}

void alarmOff() {
  digitalWrite(buzzer,LOW); 
  digitalWrite(LED, LOW);
  delay(500);
}
