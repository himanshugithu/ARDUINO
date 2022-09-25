int Spin = A0;
int led = 13;
boolean val;
int count;
void setup() {
  Serial.begin(9600);
  pinMode(Spin, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  val = analogRead(Spin);
  Serial.println(val); 

  if(val == 0)
  {
    count++;
  }
 // Serial.println(count);
  

}
