#include "EasyUltrasonic.h"

namespace easyultrasonic{
  void EasyUltrasonic::attach(uint8_t trigPin, uint8_t echoPin, float minDistance, float maxDistance){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->minDistance = minDistance;
    this->maxDistance = maxDistance;

    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
  }

  float EasyUltrasonic::getDistanceCM(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = (duration / 2) * 0.0343;

    if (distance > maxDistance){
      distance = maxDistance;
    }

    if (distance < minDistance){
      distance = 0;
    }

    return distance;
  }

  float EasyUltrasonic::getDistanceIN(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = ((duration / 2) * 0.0343) / 2.54;

    if ((distance * 2.54) > maxDistance){
      distance = maxDistance / 2.54;
    }

    if ((distance * 2.54) < minDistance){
      distance = 0;
    }

    return distance;
  }

  float EasyUltrasonic::getDistanceAdvCM(float temp, float hum){
    this->temp = temp;
    this->hum = hum;

    soundSpeed = 331.4 + (0.606 * this->temp) + (0.0124 * this->hum);
    soundSpeed = soundSpeed / 10000;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = (duration / 2) * soundSpeed;

    if (distance > maxDistance){
      distance = maxDistance;
    }

    if (distance < minDistance){
      distance = 0;
    }

    return distance;
  }

  float EasyUltrasonic::getDistanceAdvIN(float temp, float hum){
    this->temp = temp;
    this->hum = hum;

    soundSpeed = 331.4 + (0.606 * this->temp) + (0.0124 * this->hum);
    soundSpeed = soundSpeed / 10000;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = ((duration / 2) * soundSpeed) / 2.54;

    if ((distance * 2.54) > maxDistance){
      distance = maxDistance / 2.54;
    }

    if ((distance * 2.54) < minDistance){
      distance = 0;
    }

    return distance;
  }

  float convertToCM(float distanceValueIN){
    return distanceValueIN * 2.54;
  }

  float convertToIN(float distanceValueCM){
    return distanceValueCM / 2.54;
  }

}
