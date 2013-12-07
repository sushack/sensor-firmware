/**
 * SUSHACK 2013 - http://www.sushack.co.uk/ Sensor hack for OxFloodNetwork
 * Use Ciseco RFu-328 TFT LCD to display received 
 * Sends messages aR1RIVRnnnn- for Distance to river
 *
 * Ultrasonic sensor used here is from http://www.seeedstudio.com/wiki/Grove_-_Ultrasonic_Ranger
 * Library available on page.
 * Wireles modules are from Ciseco, LLAP library from https://github.com/CisecoPlc/LLAPSerial
 * Display is TFT SPI display using Adafruit libraries:
 *     https://github.com/adafruit/Adafruit-ST7735-Library
 *     https://github.com/adafruit/Adafruit-GFX-Library
 *
 * By Andrew D Lindsay
 *
 * @AndrewDlindsay  blog.thiseldo.co.uk
 * 02 November 2013
 *
 */

#include "Adafruit_GFX.h"    // Core graphics library
#include "Adafruit_ST7735.h" // Hardware-specific library
#include "SPI.h"

// Ciseco LLAP library
#include "LLAPSerial.h"

// Ultrasonic sensor library
#include "Ultrasonic.h"

// Set this device ID to R1
#define DEVICE_ID "R1"

// Hardware pins to use
#define ULTRASONIC_PIN 3
#define RADIO_ENABLE 8

// LCD Display
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  6  // you can also connect this to the Arduino reset

// Lets create some objects
// Ultrasonic object
Ultrasonic ultrasonic(ULTRASONIC_PIN);

// Instantiate the Adafruit ST7735 library. Use SPI interface
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


// Perform the setup of the hardware
void setup() {
  // initialise serial for the radio
  Serial.begin(115200);
  // Set radio enable/disable pin
  pinMode(RADIO_ENABLE, OUTPUT);    // initialize pin 8 to control the radio
  digitalWrite(RADIO_ENABLE, LOW); // Disable the radio

  // If your TFT's plastic wrap has a Red Tab, use the following:
  tft.initR(INITR_REDTAB);   // initialize a ST7735R chip, red tab
  // If your TFT's plastic wrap has a Green Tab, use the following:
  //tft.initR(INITR_GREENTAB); // initialize a ST7735R chip, green tab
  tft.fillScreen(ST7735_BLACK);
  
  // Rotate screen so I can use bigger characters
  tft.setRotation(1);

  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 0);

  // Title
  tft.setTextColor(ST7735_CYAN, ST7735_BLACK); // YELLOW
  tft.setTextSize(1);
  tft.println("OxFloodNet Node V0.1");

  // Enable the radio
  digitalWrite(RADIO_ENABLE, HIGH); // select the radio

  // Tell everyone what we ar reading
  tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.setTextSize(2);
  tft.setCursor(1, 22);
  tft.println("Distance (cm)");

  // Set initial display value 0
  displayDistance( 0 );

  // Initialise the LLAPSerial library
  LLAP.init(DEVICE_ID);

}


void displayDistance( int cm ) {
  tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
  tft.setCursor(2, 50);
  tft.setTextSize(9);
  tft.print(cm);
  tft.print("   ");
}


void loop() {  
  
  // Read the untrasonic sensor distance
  ultrasonic.MeasureInCentimeters();
  int cm = ultrasonic.RangeInCentimeters;
  // Display on LCD - Only available on hack hardware
  displayDistance( cm );
  // Send the message
  LLAP.sendInt( "RIVR", cm );
  Serial.print("\n");    // Temporary send CR
  delay(1000);  
}



