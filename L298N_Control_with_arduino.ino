#include <RedBot.h>
RedBotSensor left_sen = RedBotSensor(A0);
RedBotSensor center_sen = RedBotSensor(A1);
RedBotSensor right_sen = RedBotSensor(A2);
int enableA = 9;
int enableB = 10;
int pinA1 = 3;
int pinA2 = 4;
int pinB1 = 5;
int pinB2 = 6;
int lineStandard = 1023;
int led_cross = 2;
int num ;
boolean run0 = true;
void setup() {
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(led_cross, OUTPUT);
 delay(2000);
}
/*
 left_sen = RedBotSensor(A3);
 center_sen = RedBotSensor(A5);
 right_sen = RedBotSensor(A4);
*/
void loop() {
 /*   num=followNode(2);
    Serial.println(num);
    if(num==2){
    motorCoast();     
   }
   */
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
int followNode(int num){
  for(int i=0;i<num;i++){
                    follow();
                    Serial.println(num);
                    motorForward(100);
    }
  return num;
  }

void follow(){
  while(!(left_sen.read() >= lineStandard &&right_sen.read() >= lineStandard)){
        if (left_sen.read() < lineStandard && center_sen.read() >= lineStandard && right_sen.read() < lineStandard) {
          motorForward();
        } else if (left_sen.read() >= lineStandard && center_sen.read() < lineStandard && right_sen.read() < lineStandard) {
          turnright();
        } else if (left_sen.read() < lineStandard && center_sen.read() < lineStandard && right_sen.read() >= lineStandard) {
          turnleft();
        }
  }
  motorCoast();
  return ;
}

void motorForward()
{
  analogWrite(enableA, 80);
  analogWrite(enableB, 80);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}
void motorForward(int time2)
{
  analogWrite(enableA, 80);
  analogWrite(enableB, 80);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
  delay(time2);
}
void motorBackward()
{
  analogWrite(enableA, 80);
  analogWrite(enableB, 80);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, HIGH);
}
void motorCoast()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
}
void turnright() {
  analogWrite(enableA, 80);
  analogWrite(enableB, 80);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, LOW);
}
void turnleft() {
  analogWrite(enableA, 80);
  analogWrite(enableB, 80);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}

