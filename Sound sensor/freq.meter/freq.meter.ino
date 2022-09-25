#include <FreqMeasure.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (2,3,4,5,6,7);

double sum = 0;
int count= 0; 

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  FreqMeasure.begin();
  lcd.setCursor (3,0);
  lcd.print("Frequency");
  lcd.setCursor(5,1);
  lcd.print("Meter");
  delay(2000);
  lcd.clear();
      
}

void loop() {
  
 if( FreqMeasure.available())
  {
   sum = sum + FreqMeasure.read();
   count = count+1;
    if (count > 2) 
    {
      float frequency = FreqMeasure.countToFrequency(sum / count);
     
      String freq = "Freq : "+String(frequency)+"";  
  
//      lcd.setCursor(0, 0);
//      lcd.print("Freq :");
      lcd.setCursor (1,0);
      lcd.print(freq);
      Serial.println(frequency);
      delay(700);
    
      sum = 0;
      count = 0;
     // delay(500);  
    }
    
  }
}
