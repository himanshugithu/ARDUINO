#include <IRremote.h>
int IR_RECEIVE_PIN = 11; // Receive on pin 11

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume(); // Continue receiving

    if (IrReceiver.decodedIRData.decodedRawData == 0x6D92FD01)
    {
      digitalWrite(2,HIGH);
    }else{
      digitalWrite(2,LOW);
    }
  }
}
