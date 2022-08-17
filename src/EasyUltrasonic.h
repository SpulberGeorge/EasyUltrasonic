/*

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

#ifndef EasyUltrasonic_h
#define EasyUltrasonic_h

#include "Arduino.h"

namespace easyultrasonic{
  class EasyUltrasonic{
    private:
      float distance;
      float duration;
      float soundSpeed;
      float temp;
      float hum;
      uint8_t trigPin;
      uint8_t echoPin;
      float minDistance;
      float maxDistance;

    public:
      void attach(uint8_t trigPin, uint8_t echoPin, float minDistance = 2, float maxDistance = 400); // Sets the sensor pins as output/input (The default values for the minDistance and maxDistance parameters correspond to the HC-SR04 ultrasonic sensor distance range)

      float getDistanceCM(); // Returns the calculated distance in centimeters
      float getDistanceIN(); // Returns the calculated distance in inches

      float getPreciseDistanceCM(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and returns the calculated distance in centimeters
      float getPreciseDistanceIN(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and returns the calculated distance in inches
  };

  float convertToCM(float distanceValueIN); // Returns the converted value from inches to centimeters
  float convertToIN(float distaceValueCM); // Returns the converted value from centimeters to inches
  
}

using namespace easyultrasonic;

#endif
