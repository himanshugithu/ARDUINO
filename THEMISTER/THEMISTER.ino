#include <LiquidCrystal.h>
LiquidCrystal lcd (3,4,5,6,7,8); // define (rs,e,d4,d5,d6,d7)

int ThermistorPin = 0;  //assign pin no A0 aas thermistor pin
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  lcd.begin(16,0); //initialize  lcd diplay 
  Serial.begin(9600);  //initialize serial communication
  lcd.clear();
}

void loop() {

  Vo = analogRead(ThermistorPin); //read analog value from pin A0
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
//  Serial.print(Tf);
//  Serial.print(" F; ");
 Serial.print(Tc);
  Serial.println(" C");   

lcd.setCursor(0,0);
lcd.print("TEMP. :");
lcd.setCursor(7,0);
lcd.print(Tc);
  
  delay(1000);
}
