/* Decoder IR remote to LCD 2*16
 * --------------------------
 * Arduino uno
 * --------------------------
 * IR receiver 
 * VCC.  : 3.3v          
 * GND.  : GND         
 * SIGNAL: pin 3 
 * --------------------------       
 * LCD keypad sheild dfrobots        
 * --------------------------
 */
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int IRPIN = 3;

IRrecv irrecv(IRPIN);

decode_results result;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16,2);
  Serial.println("Enabling IRin");
  lcd.setCursor(0,0);
  lcd.print("Enabling IRin...");
  irrecv.enableIRIn();
   delay(500);
  lcd.clear();
  Serial.println("Enabled IRin");
  lcd.print("Enabled IRin");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("IR Decode Value");
  
}

void loop() 
{
  if (irrecv.decode(&result)) 
  {
    Serial.println(result.value, HEX);
     lcd.clear();
     lcd.setCursor(0,0);
  lcd.print("IR Decode Value");
        lcd.setCursor(0,1);
       
    lcd.print(result.value, HEX);
    irrecv.resume(); 
  }
  delay(500);
}
