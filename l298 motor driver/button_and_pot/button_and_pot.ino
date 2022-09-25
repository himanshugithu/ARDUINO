#define EN1 5
#define m1 6
#define m2 7

//#define m3 6
//#define m4 7
//#define EN2 9

#define button1 2
#define button2 3
int digital ;
int analog;
int count;
void setup() {
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(m1 , OUTPUT);
  pinMode(m2 , OUTPUT);
  pinMode(A0, INPUT);
  pinMode(button1 , INPUT);

}

void loop() {
  digital = digitalRead(button1);
  // Serial.println(digital);
  delay(10);
  analog = analogRead(A0);
  //Serial.println(analog);
  int pwm = map(analog, 0, 1023, 0, 255);
  analogWrite(EN1,pwm);
  if (digital == 0)
  {
    count++;
    Serial.println(count);
    delay(300);

  }

  if (count == 1)
  {
    Serial.print("forword");
//    analogWrite(EN1,pwm);
    digitalWrite(m1, HIGH);
    digitalWrite(m2,LOW);
  }

  if (count == 2)
  {
//    analogWrite(EN1,pwm);
    digitalWrite(m1, LOW);
    digitalWrite(m2,HIGH);
  }
  if (count >= 2)
  {
    count = 0;
  }




}
