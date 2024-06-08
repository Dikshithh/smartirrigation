#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//scl to a5
//sda to a4

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool button1;
bool button2;
int data;

void setup() {
Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(3,LOW);


  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("MIT BOYS");
  display.display(); 
  delay(5000); 
  display.clearDisplay();

}

void loop() {
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
   data=analogRead(A0);
   Serial.println(data);
   int val = map(data, 400, 1024, 100, 0);
   display.println(val);
   display.display();
   delay(300);
   display.clearDisplay(); 

  
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



