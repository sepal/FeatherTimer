/**
 * FeatherTimer
 */

#include <string.h>
#include <SPI.h>
#include <Wire.h>
#include <RTCZero.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_NeoPixel.h>

#include "TimeType.h"
#include "Button.h"
#include "App.h"
//#include "TimerApp.h"
TimeType t;
// Number of NeoPixels
#define NUMPIXELS           6
// Reset the OLED
#define OLED_RESET          4

// Pin definitions
const int TONE = 11;
const int NEO = 12;
const int BATTERY = A7;

// Create objects for all the hardware.
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_BMP280 bme;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);
Adafruit_BNO055 bno = Adafruit_BNO055(55, BNO055_ADDRESS_B);
RTCZero rtc;

Button button;
AppManager stateManager;

void setup() {
  // Initialize the button pins
  button.begin();
  button.setPressed(&on_pressed);

  // Initialize the NeoPixels and turn them off.
  strip.begin();
  strip.show();
  // Lower the brightness, since the timer runs on a battery.
  strip.setBrightness(50);

  // Init and clear the display.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();

  // Initialize the BMP280
  if (!bme.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  // Initialize the BNO055
  if(!bno.begin())
  {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);
  bno.setExtCrystalUse(true);

  // Initialize RTC
  rtc.begin();
  // Jan 1, 2016 by default.
  rtc.setEpoch(1451606400);

  // Show that initialization is finished.
  for (int i=0; i<6; i++) {
    strip.setPixelColor(i, 0, 255, 0);
    strip.show();
    delay(100);
  }

  for (int i=5; i>=0; i--) {
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
    delay(100);
  }
}

void loop() {
  button.update();
}

void on_pressed(uint8_t button) {
  Serial.println(button);
  switch (button) {
    case Button::UP:
      break;
    case Button::MID:
      break;
    case Button::DOWN:
      break;
  }
}
