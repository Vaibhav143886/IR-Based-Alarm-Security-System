#include <Servo.h>

Servo myservo;
void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(12,INPUT);
 pinMode(6,OUTPUT);
 pinMode(8,INPUT);
 // for servo
 myservo.attach(9);
 }

void loop() 
{ 
  digitalRead(8);
 digitalRead(12);  
if(digitalRead(8)==0)
{//Condition of both sensor detect object at the same time
  if(digitalRead(12)==0)
   {
        digitalWrite(13,HIGH);
        digitalWrite(6,LOW);
        myservo.write(180);
        delay(15);
   }
   else 
   {
    digitalWrite(6,HIGH);
    digitalWrite(13,LOW);
    myservo.write(0);
    delay(15);
   }
   //only 1st sensor detect object
  digitalWrite(13,HIGH);
  delay(3000);
  //code for object detection over 1st after 3 second
    if(digitalRead(8)==0)
    { 
      digitalWrite(6,LOW);
      myservo.write(180);
      delay(5000);
      }
    else
    {
      digitalWrite(6,HIGH);
      myservo.write(0);
      delay(15);
    }
}
else
{
  digitalWrite(13,LOW);
}
//code for object detection over 2nd sensor
  digitalRead(12);
  if(digitalRead(12)==0)
  { 
    digitalWrite(13,HIGH);
    digitalWrite(6,LOW);
    myservo.write(180);
    delay(15);
  }
  else
  {
    digitalWrite(13,LOW);
    digitalWrite(6,HIGH);
    myservo.write(0);
    delay(15);
  }  
}
