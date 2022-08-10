#ifndef EasyUltrasonic_h
#define EasyUltrasonic_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

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
      void attach(uint8_t trigPin, uint8_t echoPin, float minDistance = 2, float maxDistance = 400);

      float getDistanceCM();
      float getDistanceIN();

      float getDistanceAdvCM(float temp, float hum);
      float getDistanceAdvIN(float temp, float hum);    
  };

  float convertToCM(float distanceValueIN);
  float convertToIN(float distaceValueCM);
  
}

using namespace easyultrasonic;

#endif
