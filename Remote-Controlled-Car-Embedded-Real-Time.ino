#include <Arduino_FreeRTOS.h>
#include <IRremote.h>
#include <semphr.h>
#define Pin 2
#define POWER 0x00FF629D
#define A 0x00FF22DD
#define B 0x00FF02FD
#define C 0x00FFC23D
#define UP 0x00FF9867
#define DOWN 0x00FF38C7
#define LEFT 0x00FF30CF
#define RIGHT 0x00FF7A85
#define SELECT 0x00FF18E7
IRrecv irrecv(Pin);
decode_results results;

int Rwheel_spin = 10;
int Rwheel_forward = 9;
int Rwheel_backward = 8;
int Lwheel_forward = 7;
int Lwheel_backward = 6;
int Lwheel_spin = 5;

const int trigPin = 0;
const int echoPin = 1;
long duration;
int distance; // distance from the sensor
int limit = 20; // minimum distance to allow the car to move
int Speed = 100; // speed of the car 100 in normal mode(B)
bool block = 0; // flag to stop the car if the distance is under the limit
bool goingUp = 0;


void inits()
{
    pinMode(Lwheel_backward,OUTPUT);
    pinMode(Lwheel_forward,OUTPUT);
    pinMode(Rwheel_backward,OUTPUT);
    pinMode(Lwheel_backward,OUTPUT);
    pinMode(Rwheel_spin,OUTPUT);
    pinMode(Lwheel_spin,OUTPUT);
    
}
 
void setup() 
{
  inits();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void checkLimit()
{
  if(distance < limit)
    block = 1;
  else
    block = 0;
}


void setDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);


}
void readFromIR()
{
    setDistance();
    checkLimit();
    Serial.println(block);
    if(block && goingUp)
    {
     Stop();
    }
    else
    {
      if(irrecv.decode(&results))
      {
       Serial.println(results.value);
          switch (results.value) {
            
             case UP:            //  FORDWARD Button
                Forward();
                Serial.println("up");
                goingUp = 1;
                break;
                  
             case LEFT:            //  LEFT Button
                Left();
                goingUp = 0;
                break;   
     
             case RIGHT:            //  RIGHT Button
                Right();
                goingUp = 0;
                break;
     
             case DOWN:            //  BACK Button
                Back();
                goingUp = 0;
                break;
                
             case A: 
                Speed = 75;
                break;
                
             case B: 
                Speed = 150;
                break;
                
             case C: 
                Speed = 250;
                break;
                                        
             case SELECT:            // STOP Button
                Stop();
                break;
        }
       }
      else{
        Stop();
      }
        irrecv.resume();   
    }
   }
           
void loop() {  
  readFromIR();
}
 
void Back()
{
            
            
            analogWrite(Lwheel_spin, Speed);
            analogWrite(Rwheel_spin, Speed);            
            digitalWrite(Rwheel_backward, HIGH);
            digitalWrite(Rwheel_forward, LOW);
            digitalWrite(Lwheel_backward, HIGH);
            digitalWrite(Lwheel_forward, LOW);

            

}
 
void Forward()
{
  if(block)
  {
    Stop();
  }
  else
  {
            
            analogWrite(Lwheel_spin, Speed);
            analogWrite(Rwheel_spin, Speed);

            digitalWrite(Lwheel_forward, HIGH);
            digitalWrite(Rwheel_forward, HIGH);
            digitalWrite(Lwheel_backward, LOW);
            digitalWrite(Rwheel_backward, LOW);

  }
            
}    
void Left()
{
            digitalWrite(Rwheel_spin, HIGH);
            digitalWrite(Lwheel_forward, LOW);
            digitalWrite(Rwheel_forward, HIGH);
            for(int i=100;i<=300;i=i+100)
            {
             delay(i);
            }
}
 
void Right()
{
            digitalWrite(Lwheel_spin, HIGH);
            digitalWrite(Rwheel_forward, LOW);
            digitalWrite(Lwheel_forward, HIGH);
            for(int j=100;j<=300;j=j+100)
            {
              delay(j);
            }
} 
void Stop()
{
            digitalWrite(Lwheel_spin, LOW);
            digitalWrite(Rwheel_spin, LOW);
            digitalWrite(Lwheel_backward, LOW);
            digitalWrite(Lwheel_forward, LOW);
            digitalWrite(Rwheel_backward, LOW);
            digitalWrite(Rwheel_forward, LOW);
}
