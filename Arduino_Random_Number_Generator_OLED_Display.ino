//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Random Number Picker OLED Display | Lottery Winner
//https://www.youtube.com/watch?v=NEQpoNEQhos&list=PLUWZpHJMEu-Dv5Va5AmPeZH-E8-v9038u&index=37
//https://www.viralsciencecreativity.com/post/arduino-random-number-generator-oled-display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
long radnum;
int button = 9; //D6 for Tactile Switch
int val = LOW;
void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
  pinMode(button, INPUT);
  randomSeed(analogRead(A0));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25, 5);
  display.println("Viral Science");
  display.setTextSize(2);
  display.setCursor(15, 20);
  display.println("Giveaway");
  display.setCursor(30, 50);
  display.setTextSize(1);
  display.println("5000 Entries");   //Enter total number of Entries
  display.display();
}

void loop() {
  val = digitalRead(button);  // read input value
  if (val == HIGH)

  {
    delay(1000);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(25, 10);
    display.println("Winner!");

    radnum = random(5000);            //Enter total number of Entries
    Serial.println(radnum);

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(45, 40);
    display.println(radnum);
    display.display();

    val = LOW;
  }

}
