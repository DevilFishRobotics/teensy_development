#include <Wire.h>
#include <WireIMXRT.h>
#include <WireKinetis.h>
#include <MS5837.h>
#include <Servo.h>

byte motorPin0 = 0;
byte motorPin1 = 1;
byte motorPin2 = 2;
byte motorPin3 = 3;
byte motorPin4 = 4;
byte motorPin5 = 5;
byte motorPin6 = 6;
byte motorPin7 = 7;
byte sda = 18; //these are the default pins for Wire so this is for reference
byte scl = 19;
byte ledPin = 13; // declare the LED pin

Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
Servo motor7;
MS5837 depthSensor;

void setup() {
  // put your setup code here, to run once:
  motor0.attach(motorPin0);
  motor1.attach(motorPin1);
  motor2.attach(motorPin2);
  motor3.attach(motorPin3);
  motor4.attach(motorPin4);
  motor5.attach(motorPin5);
  motor6.attach(motorPin6);
  motor7.attach(motorPin7);
  motor0.writeMicroseconds(1500);
  motor1.writeMicroseconds(1500);
  motor2.writeMicroseconds(1500);
  motor3.writeMicroseconds(1500);
  motor4.writeMicroseconds(1500);
  motor5.writeMicroseconds(1500);
  motor6.writeMicroseconds(1500);
  motor7.writeMicroseconds(1500);

  Serial.begin(115200);
  Serial.println("Starting");
  
  Wire.begin();
  Wire.setSDA(sda);
  Wire.setSCL(scl);
    
  while (!depthSensor.init()) {
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");
    delay(5000);
  }
  
  depthSensor.setModel(MS5837::MS5837_30BA);
  depthSensor.setFluidDensity(997);
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output

  
  delay(7000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  motor0.writeMicroseconds(1100);
  motor1.writeMicroseconds(1200);
  motor2.writeMicroseconds(1300);
  motor3.writeMicroseconds(1450);
  motor4.writeMicroseconds(1550);
  motor5.writeMicroseconds(1700);
  motor6.writeMicroseconds(1800);
  motor7.writeMicroseconds(1900);
  
  
  //depth sensor stuff
  depthSensor.read();

  Serial.print("Pressure: ");
  Serial.print(depthSensor.pressure());
  Serial.println(" mbar");

  Serial.print("Temperature: ");
  Serial.print(depthSensor.temperature());
  Serial.println(" deg C");

  Serial.print("Depth: ");
  Serial.print(depthSensor.depth());
  Serial.println(" m");

  Serial.print("Altitude: ");
  Serial.print(depthSensor.altitude());
  Serial.println(" m above mean sea level");
  
  digitalWrite(ledPin, HIGH); // turn the LED on
  delay(1000); // wait for a second
  digitalWrite(ledPin, LOW); // turn the LED off

  delay(5000);
}
