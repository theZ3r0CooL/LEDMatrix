#ifndef LEDMatrix_H
#define LEDMatrix_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LEDMatrix {
  public:
    LEDMatrix(uint16_t numPerRow, uint8_t numRow, uint8_t pin);
    void begin();
    void setPixelColor(uint16_t x, uint16_t y, uint32_t color);
    uint32_t getPixelColor(uint16_t x, uint16_t y);
    void fill(uint32_t color);
    void clear();
    void show();
    void setBrightness(uint8_t brightness);
    uint8_t getRows();
    uint16_t getColumns();
    uint16_t getNumPixels();
    static uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
    void scrollText(String text, uint32_t color, uint16_t speed);
    void drawPattern(uint32_t* pattern, uint16_t patternLength, uint16_t speed);
  private:
    Adafruit_NeoPixel strip;
    // find_arduino_library(strip Adafruit_NeoPixel ${board_id} 3RD_PARTY);
    // link_arduino_library(my_target strip, ${board_id});
    uint16_t numPerRow;
    uint8_t numRow;
    uint16_t numPixels;
    uint32_t* buffer;
    uint16_t bufferLength;
    void shiftBufferLeft();
    void setPixelColorBuffer(uint16_t x, uint16_t y, uint32_t color);
};

#endif