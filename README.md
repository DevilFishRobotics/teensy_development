# Teensy Development
This repository stores all the code that is uploaded to the ROV's Teensy board. The code is responsible for controlling the ROV's motors, reading data from the MS5837 pressure sensor, and controlling an LED connected to the Teensy board.

## Installation
To install the code on the Teensy board, follow these steps:

1. Install the Arduino IDE on your computer.
2. Install the Teensyduino add-on in the board manager within the Arduino IDE.
3. Install the MS5837 library in the library manager within the Arduino IDE.
4. Open the `Teensy_AUV.ino` file in the Arduino IDE and upload it to the Teensy board.
5. Ensure that the motor pins are connected correctly to the ROV's motors and that the SDA and SCL pins are connected to the MS5837 sensor.
6. Connect an LED to the board's digital pin 13 if desired.
7. Once the code is uploaded, open the serial monitor to view sensor readings and debug messages.
Note: The serial monitor is set to 115200 baud by default, but this can be changed in the code if needed.

## Code Structure
The code is split into three main sections:

##### Motor Control: 
This section controls the ROV's motors using the Servo library. Each motor is attached to a specific pin on the Teensy board and is controlled using the `writeMicroseconds()` function. The values used for each motor can be adjusted to change the ROV's movement.

##### Depth Sensor: 
This section reads data from the MS5837 pressure sensor using the MS5837 library. The sensor's fluid density and model are set during the `setup()` function. The sensor readings for pressure, temperature, depth, and altitude are then printed to the serial monitor.

##### LED Control: 
This section controls an LED connected to the Teensy board. The LED is turned on for 1 second using the `digitalWrite()` function and then turned off for 5 seconds using the `delay()` function.

## Usage
To use the code, upload it to the Teensy board using the Arduino IDE. After uploading the code, ensure that the motor pins are connected correctly to the ROV's motors and that the SDA and SCL pins are connected to the MS5837 sensor. Connect an LED to the board's digital pin 13 if desired.

After connecting the components, open the serial monitor to view sensor readings and debug messages. The code is set to print sensor readings at a baud rate of 115200 by default, but this can be changed in the code if needed.

## Contributors
This code was developed by Devilfish Robotics members.