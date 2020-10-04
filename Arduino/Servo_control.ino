#include<Servo.h>
Servo myser;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  myser.attach(9);
}
int a;
void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(A0) / 10;
  a = a+(a*(80/100));
  myser.write(a);
}
