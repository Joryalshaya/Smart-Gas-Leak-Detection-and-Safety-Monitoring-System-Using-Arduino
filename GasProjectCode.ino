// C++ code
 
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0); //  

void setup()
{
  pinMode(7, OUTPUT);// red > danger
  pinMode(4, OUTPUT);// yellow 
  pinMode(8, OUTPUT);// green > save
  pinMode(2, OUTPUT);// buzzer > danger
  Serial.begin(9600);
  
   lcd.begin(16,2);
  lcd.setBacklight(1); // تشغيل الإضاءة الخلفية
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
  
}

void loop()
{
  int x;
  x = analogRead(A1);// read gas sens
  Serial.print("Gas value is: ");
  Serial.print(x);
  
  lcd.setCursor(0, 0);
  lcd.print("Gas Value: ");
  lcd.print(x); 
 lcd.print("   ");
   lcd.setCursor(0, 1); 
  
  
  if  (x<225)
  {
  digitalWrite(8, HIGH);
  digitalWrite(4, LOW);  
  digitalWrite(7, LOW);  
  digitalWrite(2, LOW);
  Serial.println(" - statue: Save"); 
   lcd.print("Status: Save ");
  }
   else if (x<=280) {
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  Serial.println(" - statue: WARNING! GAS DETECTED");
     lcd.print("WARNING GAS DETECT ");
  } 
  else 
  {
  digitalWrite(7, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);   
  digitalWrite(8, LOW); 
  Serial.println(" - statue: DANGER! HIGH TEMP FIRE RISK!!! "); 
    lcd.print("DANGER! FIRE!!!   ");
  }
  delay(3000);

}