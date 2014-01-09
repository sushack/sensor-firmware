#include <Ultrasonic.h>

#include <Ultrasonic.h>

/**
 * SUSHACK 2013 - http://www.sushack.co.uk/ Sensor hack for OxFloodNetwork
 * Use Ciseco RFu-328 and Ultrasound sensor
 * Sends messages aR1RIVRnnnn- for Distance to river
 *
 * Ultrasonic sensor used here is from http://www.seeedstudio.com/wiki/Grove_-_Ultrasonic_Ranger
 * Library available on page.
 * Wireles modules are from Ciseco, LLAP library from https://github.com/CisecoPlc/LLAPSerial
 *
 * By Andrew D Lindsay
 *
 * @AndrewDlindsay  blog.thiseldo.co.uk
 * 02 November 2013
 *
 * modified by B Ward for @oxfloodnet
 */

// Ciseco LLAP library
// https://github.com/CisecoPlc/LLAPSerial
#include "LLAPSerial.h"

// Ultrasonic sensor library
// https://github.com/Seeed-Studio/Grove_Ultrasonic_Ranger
#include "Ultrasonic.h"

// Set this device ID to R1
#define DEVICE_ID "R1"

// Hardware pins to use
#define ULTRASONIC_PIN 3
#define RADIO_ENABLE 8

// Lets create some objects
// Ultrasonic object
Ultrasonic ultrasonic(ULTRASONIC_PIN);


// Perform the setup of the hardware
void setup() {
  
  // initialise serial for the radio - RFu is always 115200
  Serial.begin(115200);
  
  // Set radio enable/disable pin
  pinMode(RADIO_ENABLE, OUTPUT);    // initialize pin 8 to control the radio
  digitalWrite(RADIO_ENABLE, LOW); // Disable the radio

  // Enable the radio
  digitalWrite(RADIO_ENABLE, HIGH); // select the radio

  // Initialise the LLAPSerial library
  LLAP.init(DEVICE_ID);

}



void loop() {  
  
  // Read the untrasonic sensor distance
  long cm = ultrasonic.MeasureInCentimeters();
//  ultrasonic.MeasureInCentimeters();
//                                                                                                                                                                                                             int cm = ultrasonic.RangeInCentimeters;

  // Send the message
  LLAP.sendInt( "RIVR", cm );
  Serial.print("\n");    // Temporary send CR

  // Wait for 1 second
  delay(1000);  
}
