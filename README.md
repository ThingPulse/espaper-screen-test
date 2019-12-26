# ESPaper screen test

This repository contains a simple sketch with a test sequence for ThingPulse ESPaper devices. It initializes the display driver and updates the screen every eight or so seconds.

## How to
* Clone this repo to your PC or Mac.
* Open Arduino IDE.
* Install the ThingPulse [MiniGrafx](https://github.com/ThingPulse/minigrafx) graphics library in Arduino IDE, search for "mini grafx" in the library manager.
* Choose your device on lines 8ff in the sketch by commenting the one(s) you don't need.
* In the Arduino IDE set as follows:
	* Tools > Board: * > Generic ESP8266
	* Tools > Port > /dev/cu.xxx on Mac or COM# on Windows.
	* Tools > Flash Mode > "QIO"
	* Tools > Flash Size > "2M (1M SPIFFS)"
* Put ESPaper into programming mode:
	* Press button S0 (middle)
	* Hold it down while pressing RESET (right)
	* Release RESET
	* Release S0
* Compile and upload sketch by hitting CTRL + U (⌘ + U on macOS) or Sketch > Upload or the right-arrow icon in the toolbar.
* Once done, press RESET.

## Why so complicated
Given sufficient interest we might provide pre-built binaries that you can quickly flash with our [App Fairy](https://github.com/thingPUlse/app-fairy).
