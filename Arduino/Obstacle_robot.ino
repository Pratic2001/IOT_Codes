#include <Servo.h>
Servo serv;
int serv_pos = 90,leftdist,rightdist;
int time;
int forward(){
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
  return 0;
}
int reverse(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  delay(2000);
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(500);
    
  return 0;
}
int left(){
  return 0;
}
int right(){
  return 0;
}
int distance(){
  int distance;
  digitalWrite (2, HIGH);

    delayMicroseconds (10);

    digitalWrite (2, LOW);

    time = pulseIn (3, HIGH);

    distance = (time * 0.034) / 2;
    return distance;
}
void setup() {
  // put your setup code here, to run once:
  serv.attach(9);
  pinMode(12,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

int dist; 

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  Serial.println(dist);
  serv.write(serv_pos);
  dist = distance();
  if(dist < 17){
    reverse();
    serv.write(0);
    delay(1000);
    rightdist = distance();
    serv.write(180);
    delay(1000);
    leftdist = distance;
    digitalWrite(13,HIGH);
    if((leftdist > rightdist)&& leftdist > 15 )
      left();
    else if((rightdist > leftdist)&& rightdist > 15)
      right();
    else
      reverse();    
  }
}
