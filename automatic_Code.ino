/**
 * Sensor Line on A0,A1,A2 
 */
 #include <RedBot.h>
RedBotSensor left_sen = RedBotSensor(A0);
RedBotSensor center_sen = RedBotSensor(A1);
RedBotSensor right_sen = RedBotSensor(A2);
/**
 * Motor Contorl on 9,10,3,4,5,6
 */
int enableA = 9;
int enableB = 10;
int pinA1 = 3;
int pinA2 = 4;
int pinB1 = 5;
int pinB2 = 6;
//motorSpeed of 2 motors
int motorSpeed=110;
//Line Standard for black color.
int lineStandard = 900;
void setup() {
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(53,OUTPUT);
}
void loop() {
PSV();
}

void PSV() {
  Serial.print(left_sen.read());
  Serial.print("\t");
  Serial.print(center_sen.read());
  Serial.print("\t");
  Serial.print(right_sen.read());
  Serial.println();
  delay(10);
}

void motorForward(){
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}
void motorBackward(){
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, HIGH);
}
void motorCoast(){
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}
void turnright() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, LOW);
}
void turnleft() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}

