# EasyUltrasonic
- An Arduino library used to work with ultrasonic sensors in an easy way for measuring distance.

## Specifications
- Works with the HC-SR04 ultrasonic sensor and the DHT temperature/humidity sensors for getting precise distance values.

## Usage

- Include the library so you can use it:

```c++
#include "EasyUltrasonic.h"
```

- Create an EasyUltrasonic object:

```c++
EasyUltrasonic ultrasonic;
```

- Functions:

```c++
attach(); // Sets the sensor pins as output/input

getDistanceCM(); // Returns the calculated distance in centimeters

getDistanceIN(); // Returns the calculated distance in inches

getDistanceAdvCM(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and  returns the calculated distance in centimeters

getDistanceAdvIN(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and returns the calculated distance in inches

convertToCM(float distanceValueIN); // Returns the converted value from inches to centimeters

convertToIN(float distaceValueCM); // Returns the converted value from centimeters to inches
```

- For more info check the [examples](https://github.com/SpulberGeorge/EasyUltrasonic/tree/main/examples) folder in the [EasyUltrasonic](https://github.com/SpulberGeorge/EasyUltrasonic) repository.

## Schematics
- For calculating normal distance with the HC-SR04 ultrasonic sensor and an Arduino UNO board:
![GetDistance](https://user-images.githubusercontent.com/79027106/184158290-fca1cd09-e46c-466e-871c-dc4c8db26c3b.png)

- For calculating precise distance with the HC-SR04 ultrasonic sensor, a DHT temperature/humidity sensor and an Arduino UNO board:
![GetPreciseDistance](https://user-images.githubusercontent.com/79027106/184159341-1e60d5d1-b768-4215-96f0-0874e9be5745.jpg)

## Author
- Spulber George-Marian spbgeorge1@gmail.com

## License
[MIT](https://choosealicense.com/licenses/mit/)
