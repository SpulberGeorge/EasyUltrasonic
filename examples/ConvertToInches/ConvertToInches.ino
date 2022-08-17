/*

Example sketch for the HC-SR04 ultrasonic sensor / Ping))) ultrasonic sensor
Written by Spulber George-Marian

REQUIRES the following Arduino library:
- EasyUltrasonic: https://github.com/SpulberGeorge/EasyUltrasonic

This sketch converts the distance measured by the ultrasonic sensor from centimeters to inches.

###########################################
                CONNECTIONS:
###########################################


###########################################
                4 Pin Mode:
###########################################

###########################################
              HC-SR04 sensor:
###########################################

          VCC -> 5V
          trig pin -> digital pin 5
          echo pin -> digital pin 6
          GND -> GND
          
###########################################


###########################################
                3 Pin Mode:
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

Copyright (c) 2022 Spulber George-Marian

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

// This sketch uses the 4 Pin Mode with the HC-SR04 sensor

// Set both the TRIGPIN and ECHOPIN to 5 or the digital pin that is connected to your ultrasonic sensor if you want to use your HC-SR04/Ping))) ultrasonic sensor in the 3 Pin Mode
// If you want to use the Ping))) sensor in the 3 Pin Mode you will have to modify the attach() function

#include <EasyUltrasonic.h>

#define TRIGPIN 5 // Digital pin connected to the trig pin of the ultrasonic sensor
#define ECHOPIN 6 // Digital pin connected to the echo pin of the ultrasonic sensor

EasyUltrasonic ultrasonic; // Create the ultrasonic object

void setup() {
  Serial.begin(9600); // Open the serial port

  ultrasonic.attach(TRIGPIN, ECHOPIN); // Attaches the ultrasonic sensor on the specified pins on the ultrasonic object
  // ultrasonic.attach(TRIGPIN, ECHOPIN, 3, 300); // Uncomment this line and comment the above line if you are using the Ping))) ultrasonic sensor
}

void loop() {
  float distanceCM = ultrasonic.getDistanceCM(); // Read the distance in centimeters

  float distanceIN = convertToIN(distanceCM); // Convert the distance to inches
  
  // Print the new distance value in Serial Monitor
  Serial.print(distanceIN);
  Serial.println(" in");

  delay(100);
}
