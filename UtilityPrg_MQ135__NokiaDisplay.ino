#include <SPI.h>
#include <Wire.h>
#include "MQ135.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float air_quality; 
String air_Index;
 
void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
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
    display.setCursor(0,0);  //oled display
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Air Quality Index");
    
  
    display.setCursor(0,20);  //oled display
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print(air_quality);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(" PPM");
    display.setCursor(0,40);  //oled display
    display.print("Luft ist: ");
    display.setCursor(0,50);  //oled display
    display.println(air_Index);
    display.display();
 
    delay(2000);      // thingspeak needs minimum 15 sec delay between updates.
}