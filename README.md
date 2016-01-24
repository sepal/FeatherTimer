# FeatherTimer
A timer based on Adafruits [Feather M0 Bluefruit LE](https://www.adafruit.com/products/2995) and [FeatherWing OLED display](https://www.adafruit.com/product/2900).
It also has a BNO-055 9-axis motion sensor from [Pesky Products](https://www.tindie.com/products/onehorse/bno-055-9-axis-motion-sensor-with-hardware-sensor-fusion/)
which fits nicely under the display.
The timer also has a buzzer, as well as 6 [NeoPixels](https://learn.adafruit.com/adafruit-neopixel-uberguide) to indicate the timeout.  

## Libraries
The firmware uses a number of libraries, which is also the reason, why the Feather M0 is needed.
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library/)
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel)
- [Adafruit BNO055](https://github.com/adafruit/Adafruit_BNO055)
- [Adafruit BMP280](https://github.com/adafruit/Adafruit_BMP280_Library)
- [Adafruit BluefruitLE nRF51](https://github.com/adafruit/Adafruit_BluefruitLE_nRF51)
