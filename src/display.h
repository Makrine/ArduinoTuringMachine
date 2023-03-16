#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

// colours
#define BLACK ST77XX_BLACK
#define GREEN ST77XX_GREEN
#define WHITE ST77XX_WHITE
#define RED ST77XX_RED
#define YELLOW ST77XX_YELLOW

// pin connections
#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define TFT_MOSI 12  // Data out
#define TFT_SCLK 11  // Clock out

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void CheckForEndDisplay()
{
  if(tft.getCursorY() >= 125)
  {
    tft.setCursor(0, 0);
    tft.fillScreen(BLACK);
  }
}
void ResetDisplay()
{
    tft.setCursor(0, 0);
    tft.fillScreen(BLACK);
}
