//Need the encoder library created by Paul Stoffregen
//Use 5V power supply. I had problems with anything above that

#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include <TimeLib.h>
// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
double time1 = 0;
double time2 = 0;
long prevPosition = 0;
long prevVelocity = 0;
long curPosition = 0;
long curVelocity = 0;
long curAcceleration = 0;
long counter = 0;
long projectedDeltaTime = 100;

//You have to use these pins on the arduino. These are the interrupt pins
Encoder knobLeft(19, 20);
void setup() {
  Serial.begin(9600);
  Serial.println("Encoder Test");
  time1 = millis();
  time2 = time1;
}
long positionLeft  = 0;
void loop() {
  
  counter = counter + 1;
  time1 = millis();
  //Serial.println(counter);
  if (time1-time2>projectedDeltaTime){
    //The actual degree calculation needs some work. 4 is about correct, but I dont know why it is
    curPosition = knobLeft.read()/4;
    curVelocity = (curPosition-prevPosition)/((time1-time2)/1000);
    curAcceleration = (curVelocity-prevVelocity)/((time1-time2)/1000);
    //Serial.print("Position: ");
    Serial.print(time1);
    Serial.print(", ");
    Serial.print(curPosition);
    Serial.print(", ");
    //Serial.print("Velocity: ");
    Serial.print(curVelocity);
    Serial.print(", ");
    //Serial.print("Acceleration: ");
    Serial.println(curAcceleration);

    /*
    Serial.print("Sample rate is: ");
    Serial.print(counter/((time1-time2)/1000));
    Serial.println(" hz.");
    */
    time2=time1;
    prevPosition = curPosition;
    prevVelocity = curVelocity;
    
    counter = 0;
  }
  
}
