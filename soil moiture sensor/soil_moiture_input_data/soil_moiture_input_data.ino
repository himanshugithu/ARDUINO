#include <LiquidCrystal.h>
LiquidCrystal lcd (7,6,5,4,3,2);

#define soilWet 990  // Define max value we consider soil 'wet'
#define soilDry 995
#define sensorPin A0
#define relayPin 9
#define led 10


void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("soil moiture");
  lcd.setCursor(0, 1);
  lcd.print("monitor");
  Serial.begin(9600);
  delay(2000);
}

void loop() {

  int moisture = analogRead(sensorPin);
  Serial.print("Analog Output: ");
  Serial.println(moisture);

  if (moisture < soilWet) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status :");
    lcd.setCursor(0, 1);
    digitalWrite(relayPin, LOW);
    digitalWrite(led, LOW);
    lcd.print("Soil is too wet");
    Serial.println("Status: Soil is too wet");
  }

  else if (moisture >= soilWet && moisture < soilDry)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status : moiture ");
    lcd.setCursor(0, 1);
    lcd.print(" is perfect");
    digitalWrite(relayPin, LOW);
    digitalWrite(led, LOW);
    Serial.println("Status: Soil moisture is perfect");
  }

  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status :");
    lcd.setCursor(0, 1);
    lcd.print("Soil is too dry - time to water!");
    digitalWrite(relayPin, HIGH);
    digitalWrite(led, HIGH);

    Serial.println("Status: Soil is too dry - time to water!");
  }

  delay(1000);  // Take a reading every second for testing

}
