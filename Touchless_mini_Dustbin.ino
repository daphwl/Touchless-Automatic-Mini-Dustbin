#include <AmebaServo.h>

AmebaServo myservo;
const int trigger_pin = 12;
const int echo_pin = 13;
const int inter_time = 100;
int time = 0;

void setup() 
{
  Serial.begin(115200);
  myservo.attach(8,500,2400);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin,INPUT);
  delay(3000);
}

void loop() 
{
  float duration,distance;
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);
  duration = pulseIn(echo_pin,HIGH);
  distance = (duration/58);
  Serial.print(distance);
  Serial.println(" cm");
  time = time + inter_time;
  delay(inter_time);
  if(distance < 10)
  {
    for(int i = 1500; i>= 1100; i-=25)
    {
      myservo.writeMicroseconds(i);
      Serial.println("2");
      delay(1000);
    }
    delay(1000);
    for(int i=1100; i<=1500; i+=25)
    {
      myservo.writeMicroseconds(i);
      Serial.println("1");
      delay(1000);
    }
    }
  }
