#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(12,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
        if(results.value == 0x11D9708F)
          digitalWrite(12,HIGH);
        else if(results.value == 0x11D950AF)
          digitalWrite(12,LOW);  
        irrecv.resume();
  }
}
