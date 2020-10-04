void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
float num;
int num1;
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(num);
  num = (float)analogRead(A0)/100;
  num1 = (int)num;
  
  if(digitalRead(13)){
    if(num >= 5.1)
      digitalWrite(13,LOW);
  }
  else{
    if(num1 <= 3)
      digitalWrite(13,HIGH);
  }
        
}
