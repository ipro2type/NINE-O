#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   8
#define TFT_DC   9
#define TFT_RST  3
#define TFT_MOSI 10
#define TFT_SCK  11
#define TFT_BL   14

#define ENC1_CLK 6
#define ENC1_DT  7
#define ENC1_SW  15

#define ENC2_CLK 12
#define ENC2_DT  4
#define ENC2_SW  5

#define BUZZER_PIN  21
#define BUZZER_FREQ 2048
#define DEBOUNCE_MS 25

SPIClass tftSPI(FSPI);
Adafruit_ILI9341 tft(&tftSPI, TFT_DC, TFT_CS, TFT_RST);

volatile long enc1Count = 0;
volatile long enc2Count = 0;
volatile uint32_t enc1LastPulse = 0;
volatile uint32_t enc2LastPulse = 0;

struct DebouncedInput {
  uint8_t pin;
  bool stableState;
  bool lastReading;
  uint32_t lastChangeMs;
};

DebouncedInput sw1 = {ENC1_SW, HIGH, HIGH, 0};
DebouncedInput sw2 = {ENC2_SW, HIGH, HIGH, 0};

bool buzzerActive = false;
uint32_t buzzerOffAt = 0;

long enc1Shown = 0;
long enc2Shown = 0;
bool sw1Shown = false;
bool sw2Shown = false;

void IRAM_ATTR enc1ISR() {
  uint32_t now = micros();
  if (now - enc1LastPulse < 800) return;
  enc1LastPulse = now;
  enc1Count += digitalRead(ENC1_DT) ? -1 : 1;
}

void IRAM_ATTR enc2ISR() {
  uint32_t now = micros();
  if (now - enc2LastPulse < 800) return;
  enc2LastPulse = now;
  enc2Count += digitalRead(ENC2_DT) ? -1 : 1;
}

void beep(uint16_t ms) {
  tone(BUZZER_PIN, BUZZER_FREQ);
  buzzerActive = true;
  buzzerOffAt = millis() + ms;
}

bool updateDebounced(DebouncedInput &in) {
  bool reading = digitalRead(in.pin);
  if (reading != in.lastReading) {
    in.lastChangeMs = millis();
    in.lastReading = reading;
  }
  bool changed = false;
  if ((millis() - in.lastChangeMs) > DEBOUNCE_MS && reading != in.stableState) {
    in.stableState = reading;
    changed = true;
  }
  return changed;
}

void drawLabel(int16_t x, int16_t y, const char* text) {
  tft.setCursor(x, y);
  tft.print(text);
}

void drawValue(int16_t x, int16_t y, long value) {
  tft.fillRect(x, y, 90, 10, ILI9341_BLACK);
  tft.setCursor(x, y);
  tft.print(value);
}

void drawState(int16_t x, int16_t y, bool active) {
  tft.fillRect(x, y, 50, 10, ILI9341_BLACK);
  tft.setCursor(x, y);
  tft.setTextColor(active ? ILI9341_GREEN : ILI9341_RED);
  tft.print(active ? "PRESS" : "----");
  tft.setTextColor(ILI9341_WHITE);
}

void drawStaticUI() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 10);
  tft.print("HARDWARE TEST");
  tft.drawFastHLine(0, 34, tft.width(), ILI9341_DARKGREY);

  tft.setTextSize(1);
  drawLabel(10, 50, "ENC1:");
  drawLabel(10, 70, "ENC2:");
  drawLabel(10, 95, "SW1:");
  drawLabel(90, 95, "SW2:");
}

void setup() {
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  pinMode(ENC1_CLK, INPUT_PULLUP);
  pinMode(ENC1_DT, INPUT_PULLUP);
  pinMode(ENC1_SW, INPUT_PULLUP);
  pinMode(ENC2_CLK, INPUT_PULLUP);
  pinMode(ENC2_DT, INPUT_PULLUP);
  pinMode(ENC2_SW, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  tftSPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);
  tft.begin();
  tft.setRotation(1);
  drawStaticUI();

  attachInterrupt(digitalPinToInterrupt(ENC1_CLK), enc1ISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(ENC2_CLK), enc2ISR, FALLING);

  beep(80);
}

void loop() {
  if (updateDebounced(sw1) && sw1.stableState == LOW) beep(40);
  if (updateDebounced(sw2) && sw2.stableState == LOW) beep(40);

  if (buzzerActive && millis() > buzzerOffAt) {
    noTone(BUZZER_PIN);
    buzzerActive = false;
  }

  noInterrupts();
  long e1 = enc1Count;
  long e2 = enc2Count;
  interrupts();

  if (e1 != enc1Shown) { drawValue(45, 50, e1); enc1Shown = e1; }
  if (e2 != enc2Shown) { drawValue(45, 70, e2); enc2Shown = e2; }

  bool s1 = (sw1.stableState == LOW);
  bool s2 = (sw2.stableState == LOW);
  if (s1 != sw1Shown) { drawState(40, 95, s1); sw1Shown = s1; }
  if (s2 != sw2Shown) { drawState(120, 95, s2); sw2Shown = s2; }
}
