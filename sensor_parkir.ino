#define ECHOPIN 10                             
#define TRIGPIN 9
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){ 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Sensor  Parkir ");
  Serial.begin(9600);
  lcd.setCursor(0, 1);
  lcd.print("   by  Kel. 9   ");
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
  delay(1000); 
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Status:         ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(1000); 
} 
 
void loop(){ 
  //lcd.clear();
  lcd.setCursor(0, 1);
  digitalWrite(TRIGPIN, LOW);                    
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH);                   
  delayMicroseconds(10); 
 
  digitalWrite(TRIGPIN, LOW);                    
  int distance = pulseIn(ECHOPIN, HIGH);         
  distance = distance/58;                         
  if (distance > 100) {
    lcd.print("  TERUS MUNDUR  ");
    tone(7, 400);
    delay(200);
    noTone(7);
    delay(1000);
  } else if ((distance <= 50) && (distance >= 20)) {
    lcd.print("  PELAN  PELAN  ");
    tone(7, 600);
    delay(200);
    noTone(7);
    delay(500);
  } else if ((distance < 20) && (distance >= 10)) {
    lcd.print("      AWAS!     ");
    tone(7, 900);
    delay(200);
    noTone(7);
    delay(100);
  } else {
    lcd.print("    STOOPP!!    ");
    tone(7, 900);
    delay(100);
    noTone(7);
    delay(50);
  }
  lcd.print(distance);
  lcd.print("cm");
  Serial.print(distance);  
  Serial.print(" cm\n"); 
  //delay(100);     
}
