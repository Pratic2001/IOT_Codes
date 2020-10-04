#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int re1 = 10;
const int re2 = 11;
void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(12,OUTPUT);
  pinMode(re1,OUTPUT);
  pinMode(re2 , OUTPUT);
}
int control1 = 1,control2 = 0;
void loop(){
  if (irrecv.decode(&results)){
        if(results.value == 0x11D9708F)
          digitalWrite(12,HIGH);
        else if(results.value == 0x11D948B7){
          digitalWrite(12,LOW);
          delay(500);
          digitalWrite(re1 , LOW);
          digitalWrite(re2 , HIGH);  
          digitalWrite(12 , HIGH);
        }
        else if(results.value == 0x11D958A7){
          digitalWrite(12,LOW);
          delay(500);
          digitalWrite(re2 , LOW);
          digitalWrite(re1 , HIGH);
          digitalWrite(12 , HIGH);  
        }
        else if(results.value == 0x11D950AF)
          digitalWrite(12,LOW);  
        irrecv.resume();
  }
}
