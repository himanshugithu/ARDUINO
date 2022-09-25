int pwm = 3;
int m1 = 4;
int m2 = 5;

int pot;

void setup() {
  pinMode(pwm , OUTPUT);
  pinMode(m1 , OUTPUT);
  pinMode(m2 , OUTPUT);

}

void loop() {
 
  pot = analogRead(A0);
 int Mspeed = map(pot, 0,1023,0,255);

 if (Mspeed >= 128)
 {
   int Mspeed1= map(Mspeed,128,255,0,128);
   digitalWrite(m1,HIGH);
   digitalWrite(m2,LOW);
   analogWrite(pwm,Mspeed1);
 }



 if (Mspeed <= 128)
 {
   digitalWrite(m1,LOW);
   digitalWrite(m2,HIGH);
   analogWrite(pwm,Mspeed);
 }
    //+analogWrite(pwm,Mspeed);
    delay(20);
    

}
