include <Servo.h>
Servo servo1;          // create servo object to control a servo
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
 
void setup() 
{
servo1.attach(7);             // attaches the servo on pin 9 to the servo object
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);// put your setup code here, to run once:
}

void loop() 
{
  Measuredistance();
  if(distance <= 10)
  {
  servo1.write(90);
  delay(50000);
  servo1.write(0);
  }
 delay(30000);            // waits for 30 sec
}
void Measuredistance()
{
  digitalWrite(trigPin, LOW);
  delay(2000);                         // waits for 2 sec
  digitalWrite(trigPin, HIGH);
  delay(1000);                          // waits for 1 sec
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*(0.034/2);
 }
