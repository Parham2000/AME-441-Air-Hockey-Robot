#include <Arduino.h>
int counter = 0; // Counts the number of pulses
int t1 = millis(); // used as a marker for when i started collecting data
int t2 = t1;       // used as a marker to check how much time has passed.
double rpm = 0;    // used to record RPM
double PPR = 1/360;
int CCW = 0; // CCW = 0 and CCW = 1 implies clockwise


void func() {
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    CCW = 0;
  }
  else{
    CCW = 1;
  }
  counter++;
  }

   
void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2
  pinMode(3, INPUT_PULLUP); // internal pullup input pin 2
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, func, RISING);
   

  }
   
  void loop() {


  t2 = millis();
  // after 1 second record the RPM.
  if (t2 - t1 >= 1000){
    rpm = counter*0.1666666666666667; // convert frequency to RPM rpm = counter/second * PPR * 60
    Serial.print("RPM: ");
    Serial.print(rpm);
    Serial.print(", COUNTER: ");
    Serial.print(counter);
    Serial.print(", DIR: ");
    if(CCW == 0){
      Serial.println("CLOCK WISE");
    }
    else{
      Serial.println("COUNTER CLOCK WISE");
    }
    counter = 0;
    t1 = t2;
  }


  }
   
