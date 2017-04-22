#include <OneSheeld.h>
int enableA = 9;
int enableB = 10;
int pinA1 = A0;
int pinA2 = A1;
int pinB1 = A2;
int pinB2 = A3;
int enableAM2 = 5;
int enableBM2 = 6;
int pinA1M2 = A4;
int pinA2M2 = A5;
int pinB1M2 = 7;
int pinB2M2 = 8;
int enableGrip = 3;
int in1Grip = 4;
int in2Grip = 11;
int motorSpeed = 170;
void setup() {
  OneSheeld.begin();
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(enableAM2, OUTPUT);
  pinMode(pinA1M2, OUTPUT);
  pinMode(pinA2M2, OUTPUT);
  pinMode(enableBM2, OUTPUT);
  pinMode(pinB1M2, OUTPUT);
  pinMode(pinB2M2, OUTPUT);
  pinMode(enableGrip, OUTPUT);
  pinMode(in1Grip, OUTPUT);
  pinMode(in2Grip, OUTPUT);
}
void loop() {
  if (GamePad.isUpPressed()) {
    motorForward();
  } else if (GamePad.isDownPressed()) {
    motorBackward();
  } else if (GamePad.isLeftPressed()) {
    turnleft();
  } else if (GamePad.isRightPressed()) {
    turnright();
  } else if (GamePad.isOrangePressed()) {
    OpenGrip();
  } else if (GamePad.isRedPressed()) {
    CloseGrip();
  } else if (GamePad.isGreenPressed()) {
    motorSpeed=250;
  } else if (GamePad.isBluePressed()) {
    motorCoast();
    StopGrip();
  } else {
    motorCoast();
  }
}
void motorForward() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
  analogWrite(enableAM2, motorSpeed);
  analogWrite(enableBM2, motorSpeed);
  digitalWrite(pinA1M2, HIGH); digitalWrite(pinA2M2, LOW);
  digitalWrite(pinB1M2, HIGH); digitalWrite(pinB2M2, LOW);
}
void motorBackward() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, HIGH);
  analogWrite(enableAM2, motorSpeed);
  analogWrite(enableBM2, motorSpeed);
  digitalWrite(pinA1M2, LOW); digitalWrite(pinA2M2, HIGH);
  digitalWrite(pinB1M2, LOW); digitalWrite(pinB2M2, HIGH);
}
void motorCoast() {
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
  digitalWrite(pinA1M2, LOW);
  digitalWrite(pinA2M2, LOW);
  digitalWrite(pinB1M2, LOW);
  digitalWrite(pinB2M2, LOW);
}
void turnright() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, HIGH);
  analogWrite(enableAM2, motorSpeed );
  analogWrite(enableBM2, motorSpeed);
  digitalWrite(pinA1M2, LOW); digitalWrite(pinA2M2, HIGH);
  digitalWrite(pinB1M2, HIGH); digitalWrite(pinB2M2, LOW);
}
void turnleft() {
  analogWrite(enableA, motorSpeed );
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
  analogWrite(enableAM2, motorSpeed);
  analogWrite(enableBM2, motorSpeed);
  digitalWrite(pinA1M2, HIGH); digitalWrite(pinA2M2, LOW);
  digitalWrite(pinB1M2, LOW); digitalWrite(pinB2M2, HIGH);
}
void OpenGrip() {
  analogWrite(enableGrip, 150); digitalWrite(in1Grip, HIGH); digitalWrite(in2Grip, LOW);
}
void StopGrip() {
  analogWrite(enableGrip, 0); digitalWrite(in1Grip, LOW); digitalWrite(in2Grip, LOW);
}
void CloseGrip() {
  analogWrite(enableGrip, 150); digitalWrite(in1Grip, LOW); digitalWrite(in2Grip, HIGH);
}

