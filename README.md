# EasyUltrasonic
- An Arduino library used to work with ultrasonic sensors in an easy way for measuring distance.

## Specifications
- Works with the HC-SR04 ultrasonic sensor in the 3 Pin Mode/4 Pin Mode, the Ping))) ultrasonic sensor in the 3 Pin Mode and the DHT temperature/humidity sensors for getting precise distance values.

## Software Requirements
- You will need to use at least Arduino IDE 1.0.0 or newer version.

## Hardware Requirements 
- An Arduino compatible board (e.g. Arduino UNO): [Arduino UNO](https://amzn.to/3pgZAHC) / [Arduino Mega](https://amzn.to/3QFurJC)
- A HC-SR04 ultrasonic sensor / A Ping))) ultrasonic sensor: [HC-SR04](https://amzn.to/3QHENsy)
- (Optional - For aqqurate distance values) A DHT temperature/humidity sensor (e.g. DHT 11): [DHT11](https://amzn.to/3SO78zc) / [DHT22](https://amzn.to/3zOOONu)
- Some male to female wires or a breadboard with male to male wires: [Wires](https://amzn.to/3pkDW5c) / [Breadboard](https://amzn.to/3Ag2BNF)

- Or you can just use an Arduino compatible kit instead of buying the above components (I personally recommend the ones from Elegoo): [Arduino compatible kits](https://amzn.to/3QnoVvm) / [ELEGOO Mega R3 kit](https://amzn.to/3QMi1zt) / [Official Arduino Starter Kit](https://amzn.to/3Am0JUF)

## Usage

- Include the library so you can use it:

```c++
#include <EasyUltrasonic.h>
```

- Create an EasyUltrasonic object:

```c++
EasyUltrasonic ultrasonic;
```

- Functions:

```c++
attach(uint8_t trigPin, uint8_t echoPin, float minDistance = 2, float maxDistance = 400); // Sets the sensor pins as output/input (The default values for the minDistance and maxDistance parameters correspond to the HC-SR04 ultrasonic sensor distance range)

getDistanceCM(); // Returns the calculated distance in centimeters

getDistanceIN(); // Returns the calculated distance in inches

getPreciseDistanceCM(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and  returns the calculated distance in centimeters

getPreciseDistanceIN(float temp, float hum); // Calculates an accurate distance by knowing the temperature and humidity of the environment and returns the calculated distance in inches

convertToCM(float distanceValueIN); // Returns the converted value from inches to centimeters

convertToIN(float distaceValueCM); // Returns the converted value from centimeters to inches
```

#### Check out the [examples](https://github.com/SpulberGeorge/EasyUltrasonic/tree/main/examples) folder in the [EasyUltrasonic](https://github.com/SpulberGeorge/EasyUltrasonic) repository to understand more.

## Circuit diagrams

### 3 Pin Mode - Works for the HC-SR04 ultrasonic sensor and the Ping))) ultrasonic sensor -

```diff
! If you want to use the HC-SR04 ultrasonic sensor in the 3 Pin Mode you will have to short the trig pin and the echo pin together so you have only one signal pin !
```

```diff
! If you want to use one of the ultrasonic sensors in the 3 Pin Mode, when you call the attach() function you will need to set the trigPin and the echoPin parameters as the same value !
```

```c++
// !!! If you are using the Ping))) ultrasonic sensor, when you call the attach() function you should set the minDistance and maxDistance parameters to the corresponding values by knowing that the Ping))) sensor has a range between 3cm and 300cm:
attach(TRIGPIN, ECHOPIN, 3, 300);
```

- Calculating normal distance with the HC-SR04 ultrasonic sensor in the 3 Pin Mode and an Arduino UNO board:
![HCGetDistance3PinMode](https://user-images.githubusercontent.com/79027106/184505005-2b49aabb-0827-4540-8623-5e2bcdd73d4a.png)

- Calculating precise distance with the HC-SR04 ultrasonic sensor in the 3 Pin Mode, a DHT temperature/humidity sensor and an Arduino UNO board:
![HCGetPreciseDistance3PinMode](https://user-images.githubusercontent.com/79027106/184535882-7343c581-5664-447b-aed0-eb847f5eb1ed.png)

- Calculating normal distance with the Ping))) ultrasonic sensor in the 3 Pin Mode and an Arduino UNO board:
![PingGetDistance3PinMode](https://user-images.githubusercontent.com/79027106/184505140-cad9b64a-0014-4349-9d13-b555fb82de96.png)

- Calculating precise distance with the Ping))) ultrasonic sensor in the 3 Pin Mode, a DHT temperature/humidity sensor and an Arduino UNO board:
![PingGetPreciseDistance3PinMode](https://user-images.githubusercontent.com/79027106/184536322-500ab0c5-1662-461e-8a00-838912380ad9.png)

### 4 Pin Mode - Works for the HC-SR04 ultrasonic sensor -

- Calculating normal distance with the HC-SR04 ultrasonic sensor in the 4 Pin Mode and an Arduino UNO board:
![HCGetDistance4PinMode](https://user-images.githubusercontent.com/79027106/184504951-74e345fb-5902-4f9e-8160-0cca3000fcf1.png)

- Calculating precise distance with the HC-SR04 ultrasonic sensor in the 4 Pin Mode, a DHT temperature/humidity sensor and an Arduino UNO board:
![HCGetPreciseDistance4PinMode](https://user-images.githubusercontent.com/79027106/184535707-3ef86904-0eab-4093-af41-e97e39074937.jpg)

#### Check out the [examples](https://github.com/SpulberGeorge/EasyUltrasonic/tree/main/examples) folder in the [EasyUltrasonic](https://github.com/SpulberGeorge/EasyUltrasonic) repository to understand more.

## Author
- Spulber George-Marian spbgeorge1@gmail.com

## License
[MIT](https://choosealicense.com/licenses/mit/)
