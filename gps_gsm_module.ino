#include <SoftwareSerial.h>
#define trigger  3
#define echo     4
int time_;
float distance, dist_limit = 20.00;//cms
int buzz = 13;
void setup()
{

Serial.begin(9600); // Setting the baud rate of GSM Module

Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)

//RecieveMessage();

delay(100);
pinMode(buzz, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
digitalWrite(buzz, LOW);     //set the buzzer in off mode (initial condition)
}
void loop()
{ 
 int c=ultrasonic_sensor();
 if (c==1)
  {
    digitalWrite(buzz,HIGH);
 if (Serial.available()>0)
    SendMessage();
  }
else
{
digitalWrite(buzz,LOW);
}
}
void SendMessage()
{
Serial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); 
Serial.println("AT+CMGS=\"+9264969353\"\r"); 
delay(1000);
Serial.println("Your dustbin is about to be full.Dump it now.");

delay(100);
Serial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
int ultrasonic_sensor()
{
  digitalWrite(trigger, HIGH);
  delay(1000);
  digitalWrite(trigger, LOW);
  time_ = pulseIn(echo,HIGH);//calculate rebound time of ultrasonic waves
  distance = time_*0.01725;
  if (distance <= dist_limit)
    return 1;
  else
    return 0;
}
