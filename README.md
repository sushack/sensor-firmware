#OxFloodNet Sensor Device
Sensor code from Sushack 2013 - http://www.sushack.co.uk/ 

## Requirements
Initial configuration:
 * Ciseco RFu-328 (SRF radio + ATMega328 module) with an ultrasonic sensor
 * temporary: a TFT LCD to display distance 
  
## Output 
 * LLAP to transmit sensor readings
 * Sends messages in format: aR1RIVRnnnn

Expected sensor gateway:
 * Raspberry Pi running a Ciseco SRF radio and LLAP listener
 * Code at: https://github.com/sushack/pi_sensor_mqtt
 

 

 