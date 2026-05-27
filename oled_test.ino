/*
Test OLED 
Wiring
OLED Pin	Arduino Uno Pin	Notes
VCC	3.3 V or 5 V	⚠️ Some OLEDs only work with 3.3 V, others are 5 V tolerant
GND	GND	Must be shared with Arduino
SCL	A5	(On Mega = 21, on Nano = A5)
SDA	A4	(On Mega = 20, on Nano = A4)
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }

  display.clearDisplay();            
  display.setTextSize(2);            // 🔹 Slightly larger text
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 10);
  display.println("Freq:40KHz");

  display.setCursor(0, 35);
  display.println("Dist:10CM");

  display.display();                 
}

void loop() {
  // Nothing here
}
