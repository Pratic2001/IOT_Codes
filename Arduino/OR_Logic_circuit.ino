void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button1 = 0 , button2 = 0;
  button1 = digitalRead(3);
  button2 = digitalRead(4);
  if(button1 == HIGH || button2 == HIGH)
    digitalWrite(10 , HIGH);
  else
    digitalWrite(10 , LOW);  
}
