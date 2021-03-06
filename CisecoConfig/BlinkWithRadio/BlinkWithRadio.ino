/*
  BlinkWithRadio
  Turns on an LED on for one second, then off for one second, repeatedly.
  Turns on the SRF radio and reports LED status.
  This example code is based on Blink, which is in the public domain.
 */
void setup() {                
  pinMode(13, OUTPUT);   // initialize pin 13 as digital output (LED)
  pinMode(8, OUTPUT);    // initialize pin 8 to control the radio
  digitalWrite(8, HIGH); // select the radio
  Serial.begin(115200);    // start the serial port at 115200 baud
}
void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  Serial.print("LED ON");
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  Serial.print("LED OFF");
  delay(1000);              // wait for a second
}
