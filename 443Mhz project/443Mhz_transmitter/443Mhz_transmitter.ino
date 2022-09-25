#include <RH_ASK.h>// Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library 
 
RH_ASK rf_driver; // Create Amplitude Shift Keying Object
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

int data1;
int data2;
int data3;
int data4;
 
void setup()
{
    rf_driver.init();   // Initialize ASK Object
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
}
 
void loop()
{
    data1 = digitalRead(2 );
    data2 = digitalRead(3 );
    data3 = digitalRead(4 );
    data4 = digitalRead(5 );

    sent1();
    sent2();
    sent3();
    sent4();
    delay(100);
}


void sent1()
{
  if(data1 == 0 && val1 == 0)
    {
      const char *msg = "A";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val1 =1;
    }
   else if (data1== 0 && val1 ==1)
    {
       const char *msg = "a";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val1 =0;
    }
}

void sent2()
{
  if(data2 == 0 && val2 == 0)
    {
      const char *msg = "B";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val2 =1;
    }
   else if (data2== 0 && val2 ==1)
    {
       const char *msg = "b";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val2 =0;
    }
}

void sent3()
{
  if(data3 == 0 && val3 == 0)
    {
      const char *msg = "C";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val3 =1;
    }
   else if (data3== 0 && val3 ==1)
    {
       const char *msg = "c";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val3 =0;
    }
}

void sent4()
{
  if(data4 == 0 && val4 == 0)
    {
      const char *msg = "D";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val4 =1;
    }
   else if (data4== 0 && val4 ==1)
    {
       const char *msg = "d";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    val4 =0;
    }
}
