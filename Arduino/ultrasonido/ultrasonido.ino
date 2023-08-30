// Import the ultrasonic sensor library
#include <Ultrasonic.h>

// Define the trigger and echo pins of the sensor
const int trigPin = 13;
const int echoPin = 12;

// Create an ultrasonic sensor object
Ultrasonic ultrasonic(trigPin, echoPin);

// Set the baud rate of the serial monitor
Serial.begin(9600);

// Start the scanning loop
while (true) {
  // Get the distance measurement from the sensor
  int distance = ultrasonic.read();

  // Print the distance measurement to the serial monitor
  Serial.println(distance);

  // Wait for 1 second before the next measurement
  delay(1000);
}
