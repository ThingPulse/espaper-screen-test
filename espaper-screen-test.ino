#define xstr(a) str(a)
#define str(a) #a

#include <Arduino.h>
#include <SPI.h>
#include <MiniGrafx.h>

//#define EPD29
#define EPD42

#define MINI_BLACK 0
#define MINI_WHITE 1
#define CS 15  // D8
#define RST 2  // D4
#define DC 5   // D1
#define BUSY 4 // D2
#define BITS_PER_PIXEL 1

#if defined(EPD29)
  #include <EPD_WaveShare_29.h>
  
  #define DEVICE_ROTATION 1
  #define DEVICE_TYPE Espaper29Bw

  EPD_WaveShare29 epd(CS, RST, DC, BUSY);
  
  const float MAX_TEXT_WIDTH_FACTOR = 0.95;
  const uint8_t STD_MESSAGE_Y_POSITION = 12;  
#elif defined(EPD42)
  #include <EPD_WaveShare_42.h>

  #define DEVICE_ROTATION 2
  #define DEVICE_TYPE Espaper42Bw
  
  EPD_WaveShare42 epd(CS, RST, DC, BUSY);
  
  const float MAX_TEXT_WIDTH_FACTOR = 0.85;
  const uint8_t STD_MESSAGE_Y_POSITION = 100;  
#endif

uint16_t palette[] = {MINI_BLACK, MINI_WHITE};
MiniGrafx gfx = MiniGrafx(&epd, BITS_PER_PIXEL, palette);

void showMessage(String message) {
  gfx.init();
  gfx.fillBuffer(1);
  gfx.setColor(MINI_BLACK);
  gfx.setTextAlignment(TEXT_ALIGN_CENTER);
  gfx.setFont(ArialMT_Plain_16);
  gfx.drawStringMaxWidth(gfx.getWidth() / 2, STD_MESSAGE_Y_POSITION, gfx.getWidth() * MAX_TEXT_WIDTH_FACTOR, message);
  gfx.commit();
  gfx.freeBuffer();
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Boot sequence arrived in setup()"));
  Serial.printf_P(PSTR("Device type: \"%s\"\n"), xstr(DEVICE_TYPE));
  Serial.printf_P(PSTR("Display settings. CS: %d, RST: %d, DC: %d, BUSY: %d\n"), CS, RST, DC, BUSY);

  Serial.printf_P(PSTR("Current free heap: %d\n"), ESP.getFreeHeap());

  gfx.setRotation(DEVICE_ROTATION);
  gfx.setFastRefresh(true);
  gfx.setFastRefresh(false);  
}

void loop() {
  showMessage("Hello, World! Internal clock: " + String(millis()));
  delay(8000);
}
