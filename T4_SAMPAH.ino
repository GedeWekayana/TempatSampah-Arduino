#include <Servo.h>
Servo servo;
int angle = 10;
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;
void setup() {
  servo.attach(8);
  servo.write(angle);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(10);

if(distance<100)
{
  servo.write(180);
  delay(4000);
  }
  else
  {
    servo.write(0);
    }
}
