#include <Servo.h>

Servo servo_10;
Servo servo_11;

int pos1 = 0;  //servo position for 10x10 cm box
int pos2 = 180;  //servo position for 20x20 cm box

int sensorPin = A0; //The input Pin for the photodiode
int sensorValue = 0; //Variable to store the value coming from the sensor


int sensorPin1 = A1; //The input Pin for the photodiode
int sensorValue1 = 0; //Variable to store the value coming from the sensor

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin1, INPUT);
  servo_10.attach(10);   //servo attached to pin number 10
  servo_11.attach(11);   //servo attached to pin number 11

}

void loop()
{
  sensorValue = analogRead(sensorPin);
  sensorValue1 = analogRead(sensorPin1);

  Serial.println(sensorValue, sensorValue1);


  if (sensorValue >= 50 && sensorValue1 >= 50) {
    for (pos2 = 180; pos2 >= 120; pos2 -= 1)
    {
      //Goes from 180 degrees to 120 degrees
      servo_11.write(pos2);
      delay(5);
    }
    delay(2000); //wait until the box drops into the container
    for (pos2 = 120; pos2 <= 180; pos2 += 1)
    {
      //Goes from 120 degrees to 180 degrees
      servo_11.write(pos2);
      delay(5);
    }
    delay(2000); //wait until the box drops into the container

  }
  else if (sensorValue >= 50) {
    for (pos1 = 0; pos1 <= 60; pos1 += 1)
    {
      //Goes from 0 degrees to 60 degrees
      servo_10.write(pos1);
      delay(5);
    }
    delay(2000); //wait until the box drops into the container

    for (pos1 = 60; pos1 >= 0; pos1 -= 1)
    {
      //Goes from 60 degrees to 0 degrees
      servo_10.write(pos1);
      delay(5);
    }
  }
  else {
    // Do nothing
  }

}
