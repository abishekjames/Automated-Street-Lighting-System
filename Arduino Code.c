#include <LiquidCrystal.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
int ledPin=13;
int sensorPin=A0;
void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(13,OUTPUT);
}
void loop(){
  int sensorValue=analogRead(sensorPin);
  lcd.setCursor(0,0);
  lcd.print("LDR>");
  lcd.print(sensorValue);
  delay(150);
  lcd.clear();  
  if(sensorValue >=200){
    lcd.setCursor(10,0);
    lcd.print("LED OFF");
    digitalWrite(13,LOW);
    Serial.println("LED OFF");
  }
  else if(sensorValue <=200){
    lcd.setCursor(10,0);
    lcd.print("LED ON");
    digitalWrite(13,HIGH);
    Serial.println("LED is ON");
    
  }
    
}
