void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  pinMode(12 , OUTPUT);
  pinMode(11 , OUTPUT);
  pinMode(10 , OUTPUT);
  digitalWrite(13 , LOW);
  digitalWrite(12 , LOW);
  digitalWrite(11 , LOW);
  digitalWrite(10 , LOW);
}
int led1 = 0 , led2 = 0 , led3 = 0 , led4 = 0;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    String data = Serial.readStringUntil('\n');
    int cas = data.toInt();
    switch(cas)
    {
      case 1:
        if(led1 == 0)
          led1 = 1;
        else
          led1 = 0;
          break;
      case 2:
        if(led2 == 0)
          led2 = 1;
        else
          led2 = 0;
          break;
      case 3:
        if(led3 == 0)
          led3 = 1;
        else
          led3 = 0;
          break;
      case 4:
        if(led4 == 0)
          led4 = 1;
        else
          led4 = 0;
          break;                          
    }
  }
  digitalWrite(13 , led1);
  digitalWrite(12 , led2);
  digitalWrite(11 , led3);
  digitalWrite(10 , led4);
}
