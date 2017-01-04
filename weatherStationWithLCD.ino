/*
 * Weather Station
 *  
 * Codes and idea below are originally from
 *  - Weather Station (http://github.com/openhomeautomation/home-automation-arduino)
 *  - Clock with thermometer using Arduino (http://www.instructables.com/id/Clock-with-termometer-using-Arduino-i2c-16x2-lcd-D/)
 * 
 * Libraries used:
 *  - LiquidCrystal I2C (https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)
 *  - Adafruit Sensor (https://github.com/adafruit/Adafruit_Sensor)
 *  - DHT Sensor (http://github.com/adafruit/dht-sensor-library)
 */

// libraries
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// constants for DHT sensor
#define DHTPIN 7
#define DHTTYPE DHT11

// constants for LCD
#define LCD_ADDR 0x3F
#define LCD_COL 16
#define LCD_ROW 2

// get instance of DHT
DHT dht(DHTPIN, DHTTYPE);

// get instance of LCD
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

// thermometer pic made of dots
byte picThermo[] =
{
  B00100,
  B01010,
  B01010,
  B01010,
  B01110,
  B11111,
  B11111,
  B01110
};

// water drop pic made of dots
byte picAqua[] =
{
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

// sun pic made of dots
byte picSun[] =
{
  B00100,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00100,
  B00000
};

// Korean character of 'Gi'
byte picKrGi[] =
{
  B00000,
  B11101,
  B00101,
  B00101,
  B00101,
  B01001,
  B01001,
  B10001
};

// Korean character of 'Sang'
byte picKrSang[] =
{
  B00000,
  B01010,
  B01010,
  B10111,
  B00010,
  B01100,
  B10010,
  B01100
};

// Korean character of 'Gwan'
byte picKrGwan[] =
{
  B00000,
  B11110,
  B00110,
  B01011,
  B11110,
  B00010,
  B10000,
  B11110
};

// Korean character of 'Cheuk'
byte picKrCheuk[] =
{
  B00100,
  B11111,
  B01010,
  B10001,
  B11111,
  B00000,
  B11111,
  B00001
};

// Korean character of 'So'
byte picKrSo[] =
{
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B00100,
  B11111,
  B00000
};

void setup() {

  // initialize DHT sensor
  dht.begin();

  // initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  
  // create custom characters: thermometer, water drop, sun
  lcd.createChar(1, picThermo);
  lcd.createChar(2, picAqua);
  lcd.createChar(3, picSun);

  // create custom characters: 'weather station' in Korean
  lcd.createChar(4, picKrGi);
  lcd.createChar(5, picKrSang);
  lcd.createChar(6, picKrGwan);
  lcd.createChar(7, picKrCheuk);
  lcd.createChar(8, picKrSo);

}

void loop() {
  
  // get current temperature, humidity and light level
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float light = (float) analogRead(A0) / 1024 * 100;

  // print 'Weather Station' in Korean
  lcd.setCursor(0, 0);
  lcd.print('<');
  lcd.print(char(4));
  lcd.print(char(5));
  lcd.print(char(6));
  lcd.print(char(7));
  lcd.print(char(8));
  lcd.print('>');

  // print light level on display
  lcd.setCursor(8, 0);
  lcd.print(char(3)); // custom sun sign
  lcd.setCursor(10 , 0);
  lcd.print(light);
  lcd.print('%');

  // print temperature on display
  lcd.setCursor(1, 1);
  lcd.print(char(1)); // custom thermometer sign
  lcd.setCursor(3, 1);
  lcd.print(int(temperature));
  lcd.print(char(223)); // degree sign
  lcd.print('C');

  // print humidity on display
  lcd.setCursor(10, 1);
  lcd.print(char(2)); // custom water drop sign
  lcd.setCursor(12, 1);
  //lcd,setCursor(10, 1);
  lcd.print(int(humidity));
  lcd.print('%');

  // wait 5 sec before next sensoring
  delay(5 * 1000);

}
