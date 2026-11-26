// ARDUINO SHUTTER SPEED TESTER USING DIGITAL INPUT PIN D2
// BPW34 PHOTO DIODE AND 100K RESISTOR
// THIS CODE IS FREE TO USE, MODIFY AND DISTRUBUTE

#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define RECEIVER_PIN 2      // Digital Pin 2 (Supports interrupts and fast reads)
#define TIMEOUT 8000000UL   // 8 second timeout
#define MIN_DURATION 100    // Minimum pulse threshold in microseconds

void setup() {
  pinMode(RECEIVER_PIN, INPUT);
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }

  display.clearDisplay();
  displayInitialScreen();
}

void loop() {
  // pulseIn() blocks until D2 goes HIGH, then measures microsecond duration until it goes LOW
  unsigned long duration = pulseIn(RECEIVER_PIN, HIGH, TIMEOUT);

  if (duration > MIN_DURATION) {
    displayResult(duration);
    delay(3000); // Pause to read display before next measurement
    display.clearDisplay();
    displayInitialScreen();
  }
}

void displayInitialScreen() {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Shutter Speed Tester"));
  display.setCursor(0, 18);
  display.println(F("Ready..."));
  display.display();
}

void displayResult(unsigned long duration) {
  display.clearDisplay();
  
  // Line 1: Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Shutter Speed Tester"));
  
  // Line 2: Duration in milliseconds
  double msecs = duration / 1000.0;
  display.setCursor(0, 16);
  display.print(F("Time: "));
  display.print(msecs, 2);
  display.println(F(" ms"));
  
  // Line 3: Calculated fraction
  display.setCursor(0, 32);
  display.setTextSize(2); // Larger text for main result
  if (duration >= 1000000UL) {
    double secs = duration / 1000000.0;
    display.print(secs, 1);
    display.print(F("s"));
  } else {
    double fraction = 1000000.0 / duration;
    display.print(F("1/"));
    display.print(round(fraction));
  }
  
  display.display();
}
