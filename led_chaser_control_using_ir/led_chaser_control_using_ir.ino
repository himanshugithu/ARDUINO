#include <IRremote.h>

int RECV_PIN = 3; // ir sensor connected to pin 3
int itrp_pin = 2; // set pin 2 as interrupt pin 

IRrecv irrecv(RECV_PIN);//  DECLEARE  ir object
decode_results results;
int t = 40;
int rnd =5;
int pat1t =75;

void setup() 
{
  for(int i =4;  i<=13; i++)
{
  pinMode(i,OUTPUT);
}
   irrecv.enableIRIn(); 
   attachInterrupt(digitalPinToInterrupt(itrp_pin), Recv_data, CHANGE);
   Serial.begin(9600);//to initialize serial monitor
}

void loop() 
{
  if (  results.value ==350967975   )
  {
    effect1();
    Serial.println(results.value);   
     irrecv.resume(); 
  }
  
  if (  results.value == 350980215)
  {
    effect2();
    Serial.println(results.value);
     irrecv.resume();
  }

   if (  results.value == 350982255  )
  {
    effect3();
    Serial.println("him");   
     irrecv.resume(); 
  }
  
   if (  results.value == 351000615  )
  {
    effect4();
    Serial.println("him");   
     irrecv.resume(); 
  }
  
  if (  results.value == 350963895  )
  {
    effect5();
    Serial.println("him");   
     irrecv.resume(); 
  }

   if (  results.value == 350965935  )
  {
    effect6();
    Serial.println("him");   
     irrecv.resume(); 
  }

   if (  results.value == 350959815  )
  {
    effect7();
    Serial.println("him");   
     irrecv.resume(); 
  }

  

 irrecv.resume();
  delay(200);
}

void Recv_data()
{
  if(irrecv.decode(&results)) 
   {
    Serial.println(results.value);                   
    irrecv.resume();       
   }
}

//void pattern1()
//{
// digitalWrite(4,HIGH);
// delay(100);
// digitalWrite(4,LOW);
// delay(100);
// digitalWrite(13,HIGH);
// delay(100);
// digitalWrite(13,LOW);  
//}


void effect1(){
for(int i=4; i<=13; i++) {
      digitalWrite(i,HIGH);
      delay(pat1t);
      digitalWrite(i,LOW);
 
    }
    
    for(int i=12; i>=4; i--) {
      digitalWrite(i,HIGH);
      delay(pat1t);
      digitalWrite(i,LOW);
    }
  
}

void effect2(){
  for(int i=4; i<=13; i++) {
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      digitalWrite(i+1,HIGH);
      delay(100);
      digitalWrite(i,LOW);
      digitalWrite(i-1,LOW);
      digitalWrite(i+1,LOW);
    }
    
    for(int i=12; i>=4; i--) {
      digitalWrite(i,HIGH);
      digitalWrite(i-1,HIGH);
      digitalWrite(i+1,HIGH);
      delay(100);
      digitalWrite(i,LOW);
      digitalWrite(i-1,LOW);
      digitalWrite(i+1,LOW);
    }
}

void effect3(){

  for(int i=4; i<=13; i=i+2) {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
 
    }
    
    for(int i=13; i>=4; i=i-2) {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
    } 
}

void effect4(){

  for(int i=4; i<=13; i++) {
      digitalWrite(i,HIGH);
      delay(100);
    }
    
    for(int i=13; i>=4; i--) {
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
    }
}

void effect5(){

  for(int i=4; i<=13; i++) {
      digitalWrite(i,HIGH);
      }
    delay(100);
    for(int i=4; i<=13; i++) {
      digitalWrite(i,LOW);
      }
    delay(100);
}

void effect6(){
for(int i=4; i<=8; i++) {
      digitalWrite(i,HIGH);
      }
    for(int i=9; i<=13; i++) {
      digitalWrite(i,LOW);
      }
    delay(200);
    for(int i=4; i<=8; i++) {
      digitalWrite(i,LOW);
      }
    for(int i=9; i<=13; i++) {
      digitalWrite(i,HIGH);
      }
    delay(200);

  
}

void effect7(){

for(int i=3; i<=12; i=i+2) {
      digitalWrite(i,HIGH);
      }
    for(int i=4; i<=12; i=i+2) {
      digitalWrite(i,LOW);
      }
    delay(200);
     for(int i=3; i<=12; i=i+2) {
      digitalWrite(i,LOW);
      }
    for(int i=4; i<=12; i=i+2) {
      digitalWrite(i,HIGH);
      }
    delay(200);
}
