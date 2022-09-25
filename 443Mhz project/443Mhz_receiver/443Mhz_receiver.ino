#include <RH_ASK.h>// Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library 
RH_ASK rf_driver; // Create Amplitude Shift Keying Object

void setup()
{
    rf_driver.init();     // Initialize ASK Object
    Serial.begin(9600);   // Setup Serial Monitor
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}
 
void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];// Set buffer to size of expected message  RH_ASK_MAX_MESSAGE_LEN
    uint8_t buflen = sizeof(buf);
    if (rf_driver.recv(buf, &buflen))  // Check if received packet is correct size  
  
    {

      if(buf[0]== 'A')
      {
        digitalWrite(2,HIGH);
        Serial.println("....");
      }
      
      if(buf[0]== 'a')
      {
        digitalWrite(2,LOW);
      }

       if(buf[0]== 'B')
      {
        digitalWrite(3,HIGH);
        Serial.println("....");
      }
      
      if(buf[0]== 'b')
      {
        digitalWrite(3,LOW);
      }

       if(buf[0]== 'C')
      {
        digitalWrite(4,HIGH);
        Serial.println("....");
      }
      
      if(buf[0]== 'c')
      {
        digitalWrite(4,LOW);
      }

       if(buf[0]== 'D')
      {
        digitalWrite(5,HIGH);
        Serial.println("....");
      }
      
      if(buf[0]== 'd')
      {
        digitalWrite(5,LOW);
      }

   Serial.print("Message: ");
   Serial.println((char*)buf );         
    }
}


//      buf[0]=='A' ? digitalWrite(2,HIGH) : digitalWrite(2,LOW) ;
//      buf[0]=='B' ? digitalWrite(3,HIGH) : digitalWrite(3,LOW) ;
//      buf[0]=='C' ? digitalWrite(4,HIGH) : digitalWrite(4,LOW) ;
//      buf[0]=='D' ? digitalWrite(5,HIGH) : digitalWrite(5,LOW) ;
