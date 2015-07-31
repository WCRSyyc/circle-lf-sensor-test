//

#define SIZE 14
#define CUTOFF 300
#include <Servo.h>
Servo myservoA; 
Servo myservoB;  
Servo myservoC;
Servo myservoD;
int TRUE = HIGH;
int FALSE = LOW;
int black;
int blacks = 0;
int CENTER = 13;
int CLOCKWISE = 14;
int COUTERCLOCKWISE = 13;
int find = 0;
int i = 0;
int inside = 0;
int loops = 0;
int outside = 0;
int STOP = 15;
int quit = FALSE;
long time;
int debug[2] = {0,1};
int ledPins[SIZE] = {0,31,32,33,34,35,36,37,38,39,40,41,42,43};
int lightLevel[SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int list[37] = {0,1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12};

void setup() {
  Serial.begin(9600);
  
  for (int i = 1; i < SIZE; i++) {
    pinMode(lightLevel[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 1; i < 4; i++) {
    digitalWrite(ledPins[1], HIGH);
    delay (200);
    digitalWrite(ledPins[1], LOW);
    delay (200);
  }
  digitalWrite(ledPins[1], HIGH);
  delay (3000);
 
}
//---------------------------------end of Void Setup----------------------------------

void loop () {
  scan();
  sensors();
  delay (1000);
}
//---------------------------------end of void loop----------------------------------

void scan () {
  for (int i = 1; i < SIZE; i++) {
    digitalWrite(ledPins[i], LOW);
    lightLevel[i] = analogRead(i);
  }
}

//---------------------------------end of Scan---------------------------------------

void sensors () {
  blacks = 0;
  for (int i = 1; i < SIZE; i++) {
    if (lightLevel[i] > CUTOFF) {
      blacks = blacks + 1;
    }
  Serial.print(lightLevel[i]);
  Serial.print(", ");
  }
  Serial.println(" ");
  Serial.print("Number of blacks = ");
  Serial.println(blacks);
  for (int i = 1; i < SIZE; i++) {
    if (lightLevel[i] > CUTOFF) {
      Serial.print(i);
      Serial.print(", ");
    }
  }
  Serial.println(" ");
}
//---------------------------------end of sensors------------------------------------
