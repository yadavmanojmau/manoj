//Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
//Arduino Digital Weight Scale HX711 Load Cell Module
#include <HX711_ADC.h> // https://github.com/olkal/HX711_ADC
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
HX711_ADC LoadCell(4, 5); // dt pin, sck pin
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD HEX address 0x27
int taree = 6;
int a = 0;
float b = 0;

void setup() {
  pinMode (taree, INPUT_PULLUP);
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(1000); // load cells gets 1000ms of time to stabilize

  /////////////////////////////////////
  LoadCell.setCalFactor(255); // Calibarate your LOAD CELL with 100g weight, and change the value according to readings
  /////////////////////////////////////
  
  lcd.init(); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight
  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("Digital Scale "); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to first row
  lcd.print(" 5KG MAX LOAD "); // print out to LCD
delay(3000);
lcd.clear();
}
void loop() { 
  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("Digital Scale "); // print out to LCD 
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
 
  
  lcd.setCursor(1, 1); // set cursor to secon row
  lcd.print(i, 1); // print out the retrieved value to the second row
  lcd.print("g ");
  
  if (i>=5000)
  {
    i=0;
  lcd.setCursor(0, 0); // set cursor to secon row
  lcd.print("  Over Loaded   "); 
  delay(200);
  }
  if (digitalRead (taree) == LOW)
  {
    lcd.setCursor(0, 1); // set cursor to secon row
    lcd.print("   Taring...    ");
    LoadCell.start(1000);
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
}
