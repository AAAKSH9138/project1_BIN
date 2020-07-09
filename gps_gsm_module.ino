#include <SoftwareSerial.h>
#define trigger  3
#define echo     4
int time_;
float distance, dist_limit = 20.00;//cms
String pilih;

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

{ int c=ultrasonic_sensor();
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

delay(1000); // Delay of 1000 milli seconds or 1 second

Serial.println("AT+CMGS=\"+9072433114\"\r"); // Replace x with mobile number

delay(1000);

Serial.println("Message Send :)");// The SMS text you want to send

Serial.println(pilih);

delay(100);

Serial.println((char)26);// ASCII code of CTRL+Z

delay(1000);

}


int ultrasonic_sensor(void)
{
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  time_ = pulseIn(echo,HIGH);
  distance = time_*0.01725;
  Serial.println(distance);
  if (distance <= dist_limit)
    return 1;
  else
    return 0;
}
