// Define pins for the push button, buzzer, and photoresistor
const int buttonPin = 2;
const int buzzerPin = 9;
const int photoresistorPin = A0;

// Define variables to store the state of the push button and the reading from the photoresistor
int buttonState = 0;
int photoresistorValue = 0;

void setup() {
  // Initialize the push button, buzzer, and photoresistor pins
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Set up serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Read the state of the push button and the reading from the photoresistor
  buttonState = digitalRead(buttonPin);
  photoresistorValue = analogRead(photoresistorPin);

  // Map the photoresistor reading to a frequency for the buzzer
  int frequency = map(photoresistorValue, 0, 1023, 100, 1000);

  // Check if the push button is pressed
  if (buttonState == HIGH) {
    // Play a tone on the buzzer at the mapped frequency
    tone(buzzerPin, frequency, 100);
    Serial.println(frequency);
  } else {
    // Turn off the buzzer if the button is not pressed
    noTone(buzzerPin);
  }

  // Wait for a short time before reading the inputs again
  delay(50);
}
