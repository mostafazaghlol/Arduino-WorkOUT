/*this code created by Mostafa salah zaghloul for سمينا بنفسك Team
 *first trial at 9:55 pm on fri 2/10/2015
 *secound trial at 00:30 am on 5/10/2015
 *third trial at 11pm on 8/10/2015
 *
 *
 */
//motor A
#define en1 9
#define in1 4
#define in2 5
//motor b
#define en2 3
#define in3 6
#define in4 7

int front_trig = A4; 
int front_echo = A5; 

int left_trig = A2;
int left_echo = A3;

int right_trig = A0;
int right_echo = A1;


//distance,time
long front_time, front_dis, right_time, right_dis, left_time, left_dis;

void setup() {
  pinMode(front_trig, OUTPUT); 
  pinMode(front_echo, INPUT);

  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(front_trig, LOW);  
  delayMicroseconds(2);               
  digitalWrite(front_trig, HIGH); 
  delayMicroseconds(5);               
  digitalWrite(front_trig, LOW);  
  front_time = pulseIn(front_echo, HIGH); 
  front_dis = front_time/ 29 / 2;

  digitalWrite(left_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(left_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(left_trig, LOW);
  left_time= pulseIn(left_echo, HIGH);
  left_dis= left_time / 29 / 2;

  digitalWrite(right_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(right_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(right_trig, LOW);
  right_time = pulseIn(right_echo, HIGH);
  right_dis = right_time / 29 / 2;
  Serial.print(right_dis);
  Serial.print(":");
  Serial.print(front_dis);
  Serial.print(":");
  Serial.println(left_dis);
  
  
/*  if (right_dis <= 6&& left_dis <= 6&& front_dis>5){
   forward();
  }
  else if(right_dis > 6&&left_dis <= 6&& front_dis>5){
    right();
    
  }else if (left_dis >6&&right_dis <= 6&& front_dis>5){
    left();
   }*/

   
if(right_dis <= 15)
  { left();
  }
  else if(left_dis <=15)
    
    {right();
    
   }
   else if (front_dis<=15)
   {back();
   }else {
    forward();
    }
   delay(100);
}
void right() {
  analogWrite(en1,255);
  analogWrite(en2,255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Stop () {
  analogWrite(en1, 0);
  analogWrite(en2, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void left() {
  analogWrite(en1, 255);
  analogWrite(en2, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forward() {
  analogWrite(en1, 255);
  analogWrite(en2, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void back(){

   analogWrite(en1, 255);
  analogWrite(en2, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


