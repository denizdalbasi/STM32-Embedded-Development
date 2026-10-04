#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int potPin = A0;

String topText = "Hello Deniz! Welcome to Arduino LCD ";
String bottomText = "Speed Controlled Marquee Display ";

void setup() {
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i <= topText.length() - 16; i++) {
    
    lcd.setCursor(0, 0);
    lcd.print(topText.substring(i, i + 16));
    
    lcd.setCursor(0, 1);
    lcd.print(bottomText.substring(i, i + 16));
    
    int potValue = analogRead(potPin);
    
    Serial.print("Current Delay (Speed): ");
    Serial.print(potValue);
    Serial.println(" ms");
    
    delay(potValue);
  }
}