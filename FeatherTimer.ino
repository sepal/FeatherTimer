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
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

// Facatory reset
#define FACTORYRESET_ENABLE 1
// Number of NeoPixels
#define NUMPIXELS           6
// Reset the OLED
#define OLED_RESET          4

#define VERBOSE_MODE        true

// Pin definitions
const int BTN_UP = 9;
const int BTN_MID = 6;
const int BTN_DOWN = 5;
const int TONE = 11;
const int NEO = 12;
const int BATTERY = A7;

const int BLUEFRUIT_SPI_CS = 8;
const int BLUEFRUIT_SPI_IRQ = 7;
const int BLUEFRUIT_SPI_RST = 4;

// Create objects for all the hardware.
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_BMP280 bme;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEO, NEO_GRB + NEO_KHZ800);
Adafruit_BNO055 bno = Adafruit_BNO055(55, BNO055_ADDRESS_B);
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
RTCZero rtc;

void setup() {
  // Initialize the button pins
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_MID, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);

  // Initialize the NeoPixels and turn them off.
  strip.begin();
  strip.show();
  // Lower the brightness, since the timer runs on a battery.
  strip.setBrightness(50);

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

  // Initialize the ble module.
  if ( !ble.begin(VERBOSE_MODE) )
  {
    Serial.print(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }

  // Perform a factory reset to make sure everything is in a known state
  if (FACTORYRESET_ENABLE)
  {
    Serial.println(F("Performing a factory reset: "));
    if (!ble.factoryReset()) {
      Serial.print(F("Couldn't factory reset"));
    }
  }

  // Disable command echo from Bluefruit
  ble.echo(false);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);

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

}
