#include <SPI.h>
#include <Wire.h>
#include "MQ135.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64   
#define OLED_RESET -1    
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float air_quality; 
String air_Index;
 
void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  delay(10);
  display.setCursor(0,0);  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Starte Messungen...");
  display.println("");
  display.println("MQ 135");
  display.display();
  delay(4000);
}
 
 
  void loop()
  {
    MQ135 gasSensor = MQ135(A0);
    air_quality = gasSensor.getPPM();
    
    checkAirQuality(air_quality);
    
    Serial.print("Air Quality: ");  
    Serial.print(air_quality);
    Serial.println("  PPM");   
 
    display.clearDisplay();
    display.setCursor(0,0);  
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Air Quality Index");
    
    display.setCursor(0,20);  
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print(air_quality);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(" PPM");
    display.setCursor(0,40);  
    display.print("Luft ist: ");
    display.setCursor(0,50);  
    display.println(air_Index);
    display.display();
 
    delay(2000);
}