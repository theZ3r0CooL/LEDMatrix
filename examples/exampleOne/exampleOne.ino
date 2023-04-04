#include <LEDMatrix.h>

#define NUM_PER_ROW 15
#define NUM_ROW 10
#define PIN 5

LEDMatrix matrix(NUM_PER_ROW, NUM_ROW, PIN);

void setup() {
  matrix.begin();
}

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