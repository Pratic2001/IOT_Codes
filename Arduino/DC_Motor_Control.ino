int i;
String str , temp;
void setup() {
  // put your setup code here, to run once:
  pinMode(11 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(7 , OUTPUT);
  Serial.begin(9600);
  digitalWrite(7 , LOW);
  digitalWrite(8 , LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("Enter F for forward and R for reverse: ");
    while(Serial.available() == 0){}
    str = Serial.readString();
    Serial.println("Enter the Speed from 105 to 255: ");
    while(Serial.available() == 0){}
    temp = Serial.readString();
    i = temp.toInt();
    if(str.equals(String("F")))
    { 
      digitalWrite(11 , LOW);
      delay(1000);
      digitalWrite(11,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8 , HIGH);
    }
    else if(str.equals(String("R")))
    {
      digitalWrite(11 , LOW);
      delay(1000);
      digitalWrite(11,HIGH);
      digitalWrite(8 , LOW);
      digitalWrite(7 , HIGH);
    }
  analogWrite(11 , i);
}
