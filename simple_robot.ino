/* 
Updated from the test sketch for the Adafruit assembled Motor Shield for Arduino

For use with the Adafruit Motor Shield v2 
---->  http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Initialize pointers to each motor object
Adafruit_DCMotor *mtr1 = AFMS.getMotor(1);
Adafruit_DCMotor *mtr2 = AFMS.getMotor(2);
Adafruit_DCMotor *mtr3 = AFMS.getMotor(3);
Adafruit_DCMotor *mtr4 = AFMS.getMotor(4);

void setup()
{
    Serial.begin(9600);           // set up Serial library at 9600 bps
    Serial.println("Adafruit Motorshield v2 - DC Motor test!");
    
    AFMS.begin();  // create with the default frequency 1.6KHz

  // Run motor tests
  Serial.println("***Motor 1***");
  runTest(mtr1);

  Serial.println("***Motor 2***");
  runTest(mtr2);

  Serial.println("***Motor 3***");
  runTest(mtr3);

  Serial.println("***Motor 4***");
  runTest(mtr4);
    
}

void loop()
{
  Serial.println("Forward Slow");
  moveFowardSlow();
  
  delay(100);

  Serial.println("Backward Slow");
  moveBackwardSlow();

  delay(100);
}

void runTest(Adafruit_DCMotor *myMotor)
{
  uint8_t i;

  Serial.println("tick");
  myMotor->run(FORWARD);
  for (i=0; i<150; i++)
  {
    myMotor->setSpeed(i);  
    delay(5);
  }

  for (i=150; i!=0; i--)
  {
    myMotor->setSpeed(i);  
    delay(5);
  }

  
  Serial.println("tock");
  myMotor->run(BACKWARD);
  for (i=0; i<150; i++) 
  {
    myMotor->setSpeed(i);  
    delay(5);
  }

  for (i=150; i!=0; i--) 
  {
    myMotor->setSpeed(i);  
    delay(5);
  }

  Serial.println("tech");
  myMotor->run(RELEASE);
  delay(1000);
}

void moveFowardSlow()
{
  uint8_t i;

  mtr1->run(FORWARD);
  mtr2->run(FORWARD);
  mtr3->run(FORWARD);
  mtr4->run(FORWARD);

  for (i=0; i<150; i++)
  {
    mtr1->setSpeed(i);
    mtr2->setSpeed(i);
    mtr3->setSpeed(i);
    mtr4->setSpeed(i);  
    delay(5);
  }

  for (i=150; i!=0; i--)
  {
    mtr1->setSpeed(i);
    mtr2->setSpeed(i);
    mtr3->setSpeed(i);
    mtr4->setSpeed(i);  
    delay(5);
  }

  mtr1->run(RELEASE);
  mtr2->run(RELEASE);
  mtr3->run(RELEASE);
  mtr4->run(RELEASE);
}

void moveBackwardSlow()
{
  uint8_t i;

  mtr1->run(BACKWARD);
  mtr2->run(BACKWARD);
  mtr3->run(BACKWARD);
  mtr4->run(BACKWARD);

  for (i=0; i<150; i++)
  {
    mtr1->setSpeed(i);
    mtr2->setSpeed(i);
    mtr3->setSpeed(i);
    mtr4->setSpeed(i);  
    delay(5);
  }

  for (i=150; i!=0; i--)
  {
    mtr1->setSpeed(i);
    mtr2->setSpeed(i);
    mtr3->setSpeed(i);
    mtr4->setSpeed(i);  
    delay(5);
  }

  mtr1->run(RELEASE);
  mtr2->run(RELEASE);
  mtr3->run(RELEASE);
  mtr4->run(RELEASE);
}
