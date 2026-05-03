# LameBoy

The goal of this project is to create a custom handheld device where I can play my custom games on. The device will use an LCD screen along with 4 buttons for simple inputs to my C-based games. The first game I will develop alongside this device is my custom version of Tetris based on the original soviet version.

## Software

The software will be broken down into the firmware for the actual device, and the games programmed in C.

### Firmware

__

### Games Library

All source code of games will be stored in the `games_library/` folder.

#### Tetris Mini

Please refer to the [README.md](./games_library/tetris_game/README.md) in the `tetris_game/` folder

## Hardware

- [Raspberry Pi Pico 2](https://www.raspberrypi.com/products/raspberry-pi-pico-2/)
- 4 x 4-wire Buttons (stole them from my [ESP32 Freenove kit](https://www.amazon.ca/Freenove-ESP32-S3-WROOM-Included-Compatible-Wireless/dp/B0BMQ471LV?crid=1Y8GR0YRRP5B6&dib=eyJ2IjoiMSJ9._Zbm4gpd39xSJ7Q_7Mn3dFnsU_0G9HkrqZM3aOnH79eaGjAMEam06bXSf3gKmEqe-XWELD9-YrCV7roqbLwZCXZKfCQ1juJ87ey3tJTP_x2gW-nleDZdJTNha8Bz--bF-p3L6fq9DarxS2KgwO_zE2aiWhJLYYJvVl55jGWhLEv10q-l66h3vp0hanYx5GmVrJSRqgS18fz_HfXNeOGZp7Z8o9UBLd3UYZ1lmyFTuhLlaz-D1poBZb6dn-l8U_9NT5NywN8GOlntCeP0c20QfTF8HWPiYZiw2Hx1nfRant4.D_ugMWNyvRaaaiPyIe3AIzsAwIjoaiYQF_HSOQIablI&dib_tag=se&keywords=freenove+esp32+starte+kit&qid=1777814126&s=electronics&sprefix=freenove+esp32+starte+rkit%2Celectronics%2C133&sr=1-7))
- [LCD display module](https://www.pishop.ca/product/240x320-general-2inch-ips-lcd-display-module/)

### Setup

- Download the [Pi Pico C/C++ SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html)
TBD