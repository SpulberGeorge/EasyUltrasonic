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

#include "Arduino.h"
#include "EasyUltrasonic.h"

namespace easyultrasonic{
  void EasyUltrasonic::attach(uint8_t trigPin, uint8_t echoPin, float minDistance, float maxDistance){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->minDistance = minDistance;
    this->maxDistance = maxDistance;

    pinMode(this->trigPin, OUTPUT); // Set the pinMode of the trig pin as output
    pinMode(this->echoPin, INPUT); // Set the pinMode of the echo pin as input
  }

  float EasyUltrasonic::getDistanceCM(){
    // If the trig pin is connected to the same pin as the echo pin then we will calculate the distance in the "3 Pin Mode":
    if(trigPin == echoPin){
      // Calculate the duration:
      pinMode(trigPin, OUTPUT); 
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
 
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);

      duration = pulseIn(echoPin, HIGH);

      // Calculate the distance in centimeters:
      distance = (duration / 2) * 0.0343;
      
      if (distance > maxDistance){
        distance = maxDistance;
      }

      if (distance < minDistance){
        distance = 0;
      }

    // If the trig pin is not connected to the same pin as the echo pin then we will calculate the distance in the "4 Pin Mode":
    } else{
        // Calculate the duration:
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);

        // Calculate the distance in centimeters:
        distance = (duration / 2) * 0.0343;

        if (distance > maxDistance){
          distance = maxDistance;
        }

        if (distance < minDistance){
          distance = 0;
        }
    }

    return distance;
  }

  float EasyUltrasonic::getDistanceIN(){
    // If the trig pin is connected to the same pin as the echo pin then we will calculate the distance in the "3 Pin Mode":
    if(trigPin == echoPin){
      // Calculate the duration:
      pinMode(trigPin, OUTPUT); 
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
 
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);

      duration = pulseIn(echoPin, HIGH);

      // Calculate the distance in inches:
      distance = ((duration / 2) * 0.0343) / 2.54;
      
      if ((distance * 2.54) > maxDistance){
        distance = maxDistance / 2.54;
      }

      if ((distance * 2.54) < minDistance){
        distance = 0;
      }
      
    // If the trig pin is not connected to the same pin as the echo pin then we will calculate the distance in the "4 Pin Mode":
    } else{
        // Calculate the duration:
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);

        // Calculate the distance in inches:
        distance = ((duration / 2) * 0.0343) / 2.54;

        if ((distance * 2.54) > maxDistance){
          distance = maxDistance / 2.54;
        }

        if ((distance * 2.54) < minDistance){
          distance = 0;
        }
    }

    return distance;
  }

  float EasyUltrasonic::getPreciseDistanceCM(float temp, float hum){
    this->temp = temp;
    this->hum = hum;

    // Calculate the speed of sound with temperature and humidity:
    soundSpeed = 331.4 + (0.606 * this->temp) + (0.0124 * this->hum);
    soundSpeed = soundSpeed / 10000;

    // If the trig pin is connected to the same pin as the echo pin then we will calculate the distance in the "3 Pin Mode":
    if(trigPin == echoPin){
      // Calculate the duration:
      pinMode(trigPin, OUTPUT); 
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
 
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);

      duration = pulseIn(echoPin, HIGH);

      // Calculate the distance in centimeters:
      distance = (duration / 2) * soundSpeed;
      
      if (distance > maxDistance){
        distance = maxDistance;
      }

      if (distance < minDistance){
        distance = 0;
      }
      
    // If the trig pin is not connected to the same pin as the echo pin then we will calculate the distance in the "4 Pin Mode":
    } else{
        // Calculate the duration:
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);

        // Calculate the distance in centimeters:
        distance = (duration / 2) * soundSpeed;

        if (distance > maxDistance){
          distance = maxDistance;
        }

        if (distance < minDistance){
          distance = 0;
        }
    }

    return distance;
  }

  float EasyUltrasonic::getPreciseDistanceIN(float temp, float hum){
    this->temp = temp;
    this->hum = hum;

    // Calculate the speed of sound with temperature and humidity:
    soundSpeed = 331.4 + (0.606 * this->temp) + (0.0124 * this->hum);
    soundSpeed = soundSpeed / 10000;

    // If the trig pin is connected to the same pin as the echo pin then we will calculate the distance in the "3 Pin Mode":
    if(trigPin == echoPin){
      // Calculate the duration:
      pinMode(trigPin, OUTPUT); 
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
 
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);

      duration = pulseIn(echoPin, HIGH);

      // Calculate the distance in inches:
      distance = ((duration / 2) * soundSpeed) / 2.54;
      
      if ((distance * 2.54) > maxDistance){
        distance = maxDistance / 2.54;
      }

      if ((distance * 2.54) < minDistance){
        distance = 0;
      }

    // If the trig pin is not connected to the same pin as the echo pin then we will calculate the distance in the "4 Pin Mode":
    } else{
        // Calculate the duration:
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);

        // Calculate the distance in inches:
        distance = ((duration / 2) * soundSpeed) / 2.54;

        if ((distance * 2.54) > maxDistance){
          distance = maxDistance / 2.54;
        }

        if ((distance * 2.54) < minDistance){
          distance = 0;
        }
    }

    return distance;
  }

  float convertToCM(float distanceValueIN){
    // Convert the distance value from inches to centimeters:
    return distanceValueIN * 2.54;
  }

  float convertToIN(float distanceValueCM){
    // Convert the distance value from centimeters to inches:
    return distanceValueCM / 2.54;
  }

}
