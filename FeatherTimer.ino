/**
 * FeatherTimer
 */

#include <string.h>
#include <SPI.h>
#include <Wire.h>
#include <RTCZero.h>
#include <MenuSystem.h>
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

#include "Button.h"
#include "AppState.h"

// Menu variables
MenuSystem MenuSystem;
Menu MenuRoot("Root");
MenuItem MenuItemTime("Time");
MenuItem MenuItemTimer("Timer");

Button button;

AppStateManager stateManager;

// Facatory reset
#define FACTORYRESET_ENABLE 1
// Number of NeoPixels
#define NUMPIXELS           6
// Reset the OLED
#define OLED_RESET          4

#define VERBOSE_MODE        true

// Pin definitions
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

  MenuRoot.add_item(&MenuItemTime, &on_menu_time);
  MenuRoot.add_item(&MenuItemTimer, &on_menu_timer);
  MenuSystem.set_root_menu(&MenuRoot);
  displayMenu();
}

int btn_up_lstate = HIGH;
int btn_mid_lstate = HIGH;
int btn_down_lstate = HIGH;

long time_start_mid = 0;

void loop() {
  button.update();
}

void on_pressed(uint8_t button) {
  Serial.println(button);
  switch (button) {
    case Button::UP:
      MenuSystem.next();
      displayMenu();
      break;
    case Button::MID:
      MenuSystem.select();
      break;
    case Button::DOWN:
      MenuSystem.prev();
        displayMenu();
      break;
  }
}

void displayMenu() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.setTextSize(1);

  Menu const* cp_menu = MenuSystem.get_current_menu();

  display.println(cp_menu->get_name());
  display.println(cp_menu->get_selected()->get_name());

  display.display();
}

void on_menu_time(MenuItem* p_menu_item) {
  display.clearDisplay();
  display.setCursor(0, 2);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.print("TimeMenu");
  display.display();
}

void on_menu_timer(MenuItem* p_menu_item) {
  display.clearDisplay();
  display.setCursor(0, 2);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.print("TimerMenu");
  display.display();
}
