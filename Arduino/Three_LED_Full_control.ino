#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
        if(results.value == 0x11D9D827){
          digitalWrite(10,LOW);
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
        }  
        else if(results.value == 0x11D9F00F){
          
          digitalWrite(10,LOW);
          digitalWrite(12,LOW);
          digitalWrite(11,HIGH);
        }  
        else if(results.value == 0x11D9C03F){
          digitalWrite(11,LOW);
          digitalWrite(12,LOW);
          digitalWrite(10,HIGH);
        }
        else if(results.value == 0x11D950AF){
          digitalWrite(12,LOW);
          digitalWrite(11,LOW);
          digitalWrite(10,LOW);
        }
        else if(results.value == 0x11D9708F){
          digitalWrite(10,HIGH);
          digitalWrite(11,HIGH);
          digitalWrite(12,HIGH);
        }    
        irrecv.resume();
  }
}
