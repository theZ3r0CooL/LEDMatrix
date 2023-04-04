#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <Adafruit_NeoPixel.h>

class LEDMatrix {
  public:
    LEDMatrix(uint16_t numPerRow, uint8_t numRow, uint8_t pin);
    void begin();
    void setPixelColor(uint16_t x, uint16_t y, uint32_t color);
    void fill(uint32_t color);
    void clear();
    void show();
    void scrollText(String text, uint32_t color, uint16_t speed);
    void drawPattern(uint32_t* pattern, uint16_t patternLength, uint16_t speed);
  private:
    Adafruit_NeoPixel strip;
    uint16_t numPerRow;
    uint8_t numRow;
    uint16_t numPixels;
    uint32_t* buffer;
    uint16_t bufferLength;
    void shiftBufferLeft();
    void setPixelColorBuffer(uint16_t x, uint16_t y, uint32_t color);
};

#endif  // LEDMATRIX_H