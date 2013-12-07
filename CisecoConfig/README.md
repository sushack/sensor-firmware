#Ciseco RFu/SRF Setup

This sensor uses the Ciseco RFu module (an ATMega 328 microcontroller + Ciseco SRF radio) to read the sensor pins and communicate with a sensor gateway running remotely.

It's a steep learning curve to set up, so some of the instructions are listed here after several hours piecing them together from Ciseco's vast rambling website.

## Setup

Program an RFu-328 using the Arduino environment and a Ciseco RFu dev board

###Setting up Ciseco RFu dev board:
 * Solder female headers above the CISECO logo
 * Solder headers onto dev board next to FTDI - Use these pins to communicate to an FTDI-USB interface 
 * Solder the 1uf capacitor just above the IS in CISECO - this is needed for programming the 328
 
###Setting up Ciseco RFu (using the dev board):
 * Solder the male headers onto the surface mount lands.
 * Plug the RFu onto the female headers explained above
 * Connect an FTDI-USB interface to your computer (ensure RX goes to TX and vice versa) - Ensure you only use 3.3v on the RFu and remember to use the DTR pin
 * In the Arduino IDE set your board to be Arduino Uno. The speed is always 115200
 * Upload the blink sketch to test your soldering (PIN 13 is the default LED pin on this sketch)
 * looking at the RFu powered up with the RFu logo facing you, GND is the bottom left pin. Pin 13 is the next-but-one pin.
 * Pin details here: http://openmicros.org/index.php/articles/88-ciseco-product-documentation/294-rfu328-technical-data
 
If the LED blinks you've soldered properly and connected the pins. Hurrah.

### Radio test:
 * At the receiving end (eg. Slice of Radio raspberry Pi SRF interface) make sure it's listening at 115200 and the configuration matches (See http://openmicros.org/index.php/articles/88-ciseco-product-documentation/295-rfu328-troubleshooting for restoring an SRF to working again)
 * Upload BlinkWithRadio sketch from the Starter Guide: http://openmicros.org/index.php/articles/88-ciseco-product-documentation/236-rfu328-starter-guide