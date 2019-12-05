#include <Adafruit_MotorShield.h>
#define Trigpin 8
#define Echopin 7
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// The DC motor connected to M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

// The DC motor connected to M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

float distance;
//car
int flag = 0;

void setup() {
  Serial.begin(19200);
  AFMS.begin();
  pinMode(Trigpin, OUTPUT);
  pinMode(Echopin, INPUT);
  leftMotor->setSpeed(200);
  rightMotor->setSpeed(200);
  Serial.println("Startup");
}

void go()
{
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

void back()
{
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
}

void right()
{
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
}

void csb()
{
  int dat;
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  distance = pulseIn(Echopin, HIGH) / 58.00;
  Serial.print(distance);
  Serial.println("cm");
  dat = distance;
  if (dat > 10) 
  {
    go();
    
  }
  if (dat < 10) 
  {
   
    right();
  }
}

void loop() {
  csb();
}
