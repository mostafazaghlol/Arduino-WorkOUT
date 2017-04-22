#include <RedBot.h>
RedBotSensor lf = RedBotSensor(A0);
RedBotSensor cen = RedBotSensor(A1);
RedBotSensor ri= RedBotSensor(A2);
int enableA = 9;
int enableB = 11;
int pinA1 = 3;
int pinA2 = 4;
int pinB1 = 5;
int pinB2 = 6;
int front_trig = A14;
int front_echo = A15;
long front_time, fris;
int motorSpeed = 60;
int lineStandard = 750;
int tmypins[4][3];
int fmypins[4][3];
int i,j;
boolean scane1=true;
boolean scane2=false;
boolean scane3=false;
boolean scane4=false;
boolean scane5=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(front_trig, OUTPUT);
  pinMode(front_echo, INPUT);
}

void loop() {
 
  if(scane1){
for(j=0;j<=3;j=j+1){
if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){  forward();}
else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard&&fris>15){turnright();}
else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard&&fris>15){turnleft();}
else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){tmypins[1][j]=1;forward();delay(200);continue;}
else if(cen.read()>lineStandard && lf.read() <lineStandard &&ri.read() <lineStandard&&fris>15){tmypins[1][j]=0; forward();delay(200);continue;}
else if(fris<15){tmypins[1][j]=2;
   if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){forward();}
   else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard){turnright();}
   else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard){turnleft();}
   else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ forward(); delay(200);motorCoast();delay(500);  continue;}
}
}
if(j==3){scane1=false;}
}
roright();scane2=true;
if(scane2){
for(j=3;j>=0;j=j-1){
  if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){  forward();}
else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard&&fris>15){turnright();}
else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard&&fris>15){turnleft();}
else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){
  tmypins[2][j]=1;
  if(j=3){roright();}else{
  forward();
  delay(200);}
  continue;
  }
else if(cen.read()>lineStandard && lf.read() <lineStandard &&ri.read() <lineStandard&&fris>15){
  tmypins[2][j]=0;
  if(j=3){roright();}else{
  forward();
  delay(200);}
  continue;
  }
else if(fris<15){tmypins[2][j]=2;
   if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){forward();}
   else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard){turnright();}
   else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard){turnleft();}
   else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ forward(); delay(200);motorCoast();delay(500);  continue;}
}
}
if(j==0){scane2=false;}
}
roleft();scane3=true;
if(scane3){
for(j=0;j<=3;j=j+1){
  if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){  forward();}
else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard&&fris>15){turnright();}
else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard&&fris>15){turnleft();}
else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){
  tmypins[2][j]=1;
  if(j=3){roleft();}else{
  forward();
  delay(200);}
  continue;
  }
else if(cen.read()>lineStandard && lf.read() <lineStandard &&ri.read() <lineStandard&&fris>15){
  tmypins[2][j]=0;
  if(j=3){roleft();}else{
  forward();
  delay(200);}
  continue;
  }
else if(fris<15){tmypins[2][j]=2;
   if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){forward();}
   else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard){turnright();}
   else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard){turnleft();}
   else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ forward(); delay(200);motorCoast();delay(500);  continue;}
}
}
if(j==3){scane3=false;}
}
roright();scane4=true;
if(scane4){
for(j=3;j>=0;j=j-1){
  if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){  forward();}
else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard&&fris>15){turnright();}
else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard&&fris>15){turnleft();}
else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){
  tmypins[2][j]=1;
  if(j=3){roright();}else{
  forward();
  delay(200);}
  continue;
  }
else if(cen.read()>lineStandard && lf.read() <lineStandard &&ri.read() <lineStandard&&fris>15){
  tmypins[2][j]=0;
  if(j=3){roright();}else{
  forward();
  delay(200);}
  continue;
  }
else if(fris<15){tmypins[2][j]=2;
   if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){forward();}
   else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard){turnright();}
   else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard){turnleft();}
   else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ forward(); delay(200);motorCoast();delay(500);  continue;}
}
}
if(j==0){
  scane4=false;}
}
roright();scane5=true;
if(scane5){
  for(int x=0;x<3;x=x+1){
 if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){  forward();}
else if(cen.read()>lineStandard&&lf.read()<lineStandard&&ri.read()>lineStandard&&fris>15){turnright();}
else if(cen.read()>lineStandard &&lf.read()>lineStandard && ri.read()<lineStandard&&fris>15){turnleft();}
else if(cen.read()>lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard&&fris>15){forward();delay(200);continue;}
else if(cen.read()>lineStandard && lf.read() <lineStandard &&ri.read() <lineStandard&&fris>15){forward();delay(200);continue;}  
  if (x==3){scane5=false;}
  }
}

motorCoast();


}

void roright(){while( lf.read() >lineStandard ||ri.read() >lineStandard){
  turnright(); if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ return;}
  }
}
void roleft(){while( lf.read() >lineStandard ||ri.read() >lineStandard){
  turnleft(); if(cen.read()<lineStandard && lf.read() >lineStandard &&ri.read() >lineStandard){ return;}
  }
}
void forward(){
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, HIGH); digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}
void backward(){
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
  digitalWrite(pinB1, LOW); digitalWrite(pinB2, HIGH);
}
void turnleft() {
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(pinA1, LOW); digitalWrite(pinA2, HIGH);
  digitalWrite(pinB1, HIGH); digitalWrite(pinB2, LOW);
}

