/*

Example sketch for the HC-SR04 ultrasonic sensor / Ping))) ultrasonic sensor
Written by Spulber George

REQUIRES the following Arduino library:
- EasyUltrasonic: https://github.com/SpulberGeorge/EasyUltrasonic

This sketch prints the distance measured by the ultrasonic sensor in the 3 Pin Mode to the Serial Monitor.

###########################################
                CONNECTIONS:
###########################################


###########################################
              HC-SR04 sensor:
###########################################

          VCC -> 5V
          trig pin -> digital pin 5
          echo pin -> digital pin 5
          GND -> GND
          
###########################################

###########################################
///////////////////////////////////////////
###########################################

###########################################
              Ping))) sensor:
###########################################

          5V -> 5V
          SIG -> digital pin 5
          GND -> GND
          
###########################################

MIT License

Copyright (c) 2022 SpulberGeorge

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <EasyUltrasonic.h>

// If you want to use your HC-SR04/Ping))) ultrasonic sensor in the 3 Pin Mode, then the TRIGPIN value will need to be the same as the ECHOPIN value:
#define TRIGPIN 5 // Digital pin connected to the trig pin of the ultrasonic sensor
#define ECHOPIN 5 // Digital pin connected to the echo pin of the ultrasonic sensor

EasyUltrasonic ultrasonic; // Create the ultrasonic object

void setup() {
  Serial.begin(9600); // Open the serial port

  ultrasonic.attach(TRIGPIN, ECHOPIN); // Attaches the ultrasonic sensor on the specified pins on the ultrasonic object
}

void loop() {
  float distanceCM = ultrasonic.getDistanceCM(); // Read the distance in centimeters

  // float distanceIN = ultrasonic.getDistanceIN(); // Uncomment if you want to get the distance in inches
  
  // Print the distance value in Serial Monitor
  Serial.print(distanceCM);
  Serial.println(" cm");

  delay(100);
}
