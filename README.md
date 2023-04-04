# LEDMatrix Library

The LEDMatrix library provides functions for controlling a 10x15 LED matrix. the one built for this project consists of ws2812 LEDs arranged in alternating rows, powered in parallel and controlled by an ESP32 microcontroller. The library allows for setting individual LED colors, filling the entire matrix with a single color, and displaying animations such as scrolling text or patterns.

## Installation

1. Go to the [LEDMatrix repository](https://www.github.com/theZ3r0CooL/LEDMatrix) on GitHub.
2. Click the "Clone or download" button and select "Download ZIP".
3. In the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library and select the downloaded ZIP file.

## Usage

Include the LEDMatrix library in your sketch by adding `#include <LEDMatrix.h>` at the top of your file.

Create an `LEDMatrix` object with the number of LEDs per row, the number of rows, and the pin connected to the matrix:

```
LEDMatrix matrix(15, 10, 5);
```

Initialize the matrix by calling `begin()` in the `setup()` function:

```
void setup() {
  matrix.begin();
}
```

Use the library functions to control the matrix in the `loop()` function:

```
void loop() {
  // Fill the matrix with red
  matrix.fill(0xFF0000);
  matrix.show();
  delay(1000);

  // Fill the matrix with green
  matrix.fill(0x00FF00);
  matrix.show();
  delay(1000);

  // Fill the matrix with blue
  matrix.fill(0x0000FF);
  matrix.show();
  delay(1000);

  // Clear the matrix
  matrix.clear();
  matrix.show();
  delay(1000);
}
```

## Functions

- `LEDMatrix(uint16_t numPerRow, uint8_t numRow, uint8_t pin)`: Constructor that initializes the `strip` object from the `Adafruit_NeoPixel` library with the total number of LEDs in the matrix.
- `void begin()`: Initializes the `strip` object.
- `void setPixelColor(uint16_t x, uint16_t y, uint32_t color)`: Sets the color of the LED at position `(x, y)` in the matrix.
- `void fill(uint32_t color)`: Fills the entire matrix with the specified color.
- `void clear()`: Clears the entire matrix.
- `void show()`: Updates the LEDs in the matrix to match the values in the `buffer` array.
- `void scrollText(String text, uint32_t color, uint16_t speed)`: Scrolls the specified text across the matrix at the specified speed and color.
- `void drawPattern(uint32_t* pattern, uint16_t patternLength, uint16_t speed)`: Displays a scrolling pattern of colors on the matrix.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.