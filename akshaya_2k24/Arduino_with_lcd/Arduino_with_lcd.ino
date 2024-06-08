//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

bool button1;
bool button2;
int data;


  
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  

  Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(3,LOW);

  lcd.setCursor(0, 1);
  // lcd.print(" i ");
  // lcd.printByte(3);
  // displayKeyCodes();
  
}




void loop()
{
   data=analogRead(A0);
   Serial.println(data);
   int val = map(data, 400, 1024, 100, 0);
   lcd.setCursor(0, 1);
    lcd.print("Humidity is :");
   lcd.setCursor(14,1);
   lcd.print("   ");
   lcd.setCursor(14,1);
   lcd.print(val);
  delay(300);



button1=digitalRead(4);

button2=digitalRead(5);

if (button1 == LOW) 
  digitalWrite(2,LOW);
else  
   digitalWrite(2,HIGH); 


if (button2 == LOW) 
  digitalWrite(3,LOW);
else  
   digitalWrite(3,HIGH);

}

