#include "LEDMatrix.h"

LEDMatrix::LEDMatrix(uint16_t numPerRow, uint8_t numRow, uint8_t pin)
  : strip(numPerRow * numRow, pin, NEO_GRB + NEO_KHZ800)
{
  this->numPerRow = numPerRow;
  this->numRow = numRow;
  numPixels = numPerRow * numRow;
  bufferLength = numPerRow * (numRow + 1);  // Add an extra row for scrolling text
  buffer = new uint32_t[bufferLength];
}

void LEDMatrix::begin() {
  strip.begin();
  strip.show();
}

void LEDMatrix::setPixelColor(uint16_t x, uint16_t y, uint32_t color) {
  setPixelColorBuffer(x, y, color);
  strip.setPixelColor(y * numPerRow + x, color);
}

uint32_t LEDMatrix::getPixelColor(uint16_t x, uint16_t y) {
  if (x >= numPerRow || y >= numRow) {
    return 0;
  }
  return buffer[y * numPerRow + x];
}

void LEDMatrix::fill(uint32_t color) {
  for (uint16_t i = 0; i < bufferLength; i++) {
    buffer[i] = color;
  }
  strip.fill(color, 0, numPixels);
}

void LEDMatrix::clear() {
  fill(0);
}

void LEDMatrix::show() {
  for (uint16_t i = 0; i < bufferLength; i++) {
    strip.setPixelColor(i, buffer[i]);
  }
  strip.show();
}

void LEDMatrix::setBrightness(uint8_t brightness) {
  strip.setBrightness(brightness);
}

uint8_t LEDMatrix::getRows() {
  return numRow;
}

uint16_t LEDMatrix::getColumns() {
  return numPerRow;
}

uint16_t LEDMatrix::getNumPixels() {
  return numPixels;
}

uint32_t LEDMatrix::Color(uint8_t r, uint8_t g, uint8_t b) {
  return Adafruit_NeoPixel::Color(r, g, b);
}

void LEDMatrix::scrollText(String text, uint32_t color, uint16_t speed) {
  uint16_t textLength = text.length() * (numPerRow + 1);  // Add one extra pixel space between characters
  uint16_t textStart = numPixels;
  uint16_t textEnd = textStart + textLength;
  for (uint16_t i = textStart; i < textEnd; i++) {
    buffer[i] = 0;
  }
  for (uint16_t i = 0; i < text.length(); i++) {
    uint16_t charStart = textStart + i * (numPerRow + 1);
    uint16_t charEnd = charStart + numPerRow;
    for (uint16_t j = charStart; j < charEnd; j++) {
      buffer[j] = color;
    }
  }
  for (uint16_t i = 0; i < textLength + numPerRow; i++) {
    show();
    shiftBufferLeft();
    delay(speed);
  }
}

void LEDMatrix::drawPattern(uint32_t* pattern, uint16_t patternLength, uint16_t speed) {
  uint16_t bufferStart = numPerRow;
  uint16_t bufferEnd = bufferLength;
  for (uint16_t i = bufferStart; i < bufferEnd; i++) {
    buffer[i] = 0;
  }
  uint16_t patternStart = bufferStart - patternLength;
  for (uint16_t i = 0; i < patternLength; i++) {
    buffer[patternStart + i] = pattern[i];
  }
  for (uint16_t i = 0; i < patternLength + numPerRow; i++) {
    show();
    shiftBufferLeft();
    delay(speed);
  }
}

void LEDMatrix::shiftBufferLeft() {
  for (uint16_t i = 0; i < bufferLength - 1; i++) {
    buffer[i] = buffer[i + 1];
  }
}

void LEDMatrix::setPixelColorBuffer(uint16_t x, uint16_t y, uint32_t color) {
  buffer[y * numPerRow + x] = color;
}