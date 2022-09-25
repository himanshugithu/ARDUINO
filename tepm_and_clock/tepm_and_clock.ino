#include <LiquidCrystal.h>
#include <dht.h>
#include <DS3231.h>

DS3231  rtc(SDA, SCL);
dht DHT;
#define DHT11_PIN 2
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

int in;
int buttonPin = 9;
int count = 1;
int t ;
int humi;

byte degree[] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, degree);
  Serial.begin(9600);
  rtc.begin();
  pinMode(buttonPin, INPUT_PULLUP);


  //  rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //  rtc.setTime(10, 37, 30 );     // Set the time to 12:00:00 (24hr format)
  //  rtc.setDate(11, 7, 2021);   // Set the date to January 1st, 2014

  lcd.setCursor(3, 0);
  lcd.print("TIME & TEMP");
  lcd.setCursor(5, 1);
  lcd.print("Monitor");
  delay(2000);

}

void loop()
{
  int in = digitalRead(buttonPin);


  if (in == 0)
  {
    count++;
  }
  switch (count)
  {
    case 1:
      lcd.clear();
      D_clock();
      break;

    case 2:
      temp();
      break;

    default :
      count = 0;

  }

}

void D_clock() {


  Serial.println(rtc.getDOWStr());



  // Send date
  Serial.println(rtc.getDateStr());
  lcd.setCursor(0, 1);
  lcd.print("Date:");
  lcd.setCursor(6, 1);
  lcd.println(rtc.getDateStr());

  // Send time
  Serial.println(rtc.getTimeStr());
  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(6, 0);
  lcd.print(rtc.getTimeStr());
  // Wait one second before repeating :)
  delay (1000);



}

void temp() {

  int chk = DHT.read11(DHT11_PIN);
  t = DHT.temperature;
  humi = DHT.humidity;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp :");
  lcd.setCursor(10, 0);
  lcd.print(t);
  lcd.setCursor(12, 0);
  lcd.write((byte)0);
  lcd.setCursor(13, 0);
  lcd.print('C');


  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(10, 1);
  lcd.print(humi);
  lcd.setCursor(12, 1);
  lcd.print('%');
  delay(500);




  //  Serial.print("Temperature = ");
  //  Serial.println(DHT.temperature);
  //  Serial.print("Humidity = ");
  //  Serial.println(DHT.humidity);

  //  Serial.println("------------------------------------------------------");

}
