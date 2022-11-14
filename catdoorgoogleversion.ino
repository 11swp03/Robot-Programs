#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8
//#define button 10
#include <stdio.h>
#include <stdlib.h>

const int button = 10;            // GPIO 8 for the button
const int led =7;                // GPIO 7 for the LED
int ledflag=0;

//Ultrasonic Sensor Presets
const int Echo = 12;
const int Trig = 13;

void setup(){
   Serial.begin(9600);

   pinMode(PIN_Motor_PWMA, OUTPUT);
   pinMode(PIN_Motor_AIN_1, OUTPUT);
   pinMode(PIN_Motor_PWMB, OUTPUT);
   pinMode(PIN_Motor_BIN_1, OUTPUT);
   pinMode(PIN_Motor_STBY, OUTPUT);

   digitalWrite(PIN_Motor_STBY,HIGH); //turns motor on

    pinMode(button,INPUT);         // define button as an input
  pinMode(led,OUTPUT);           // define LED as an output
  digitalWrite(led,LOW);
}

//Sub-routine to test distance from object
int Distance_test(){
   digitalWrite(Trig, LOW);
   delayMicroseconds(2);
   digitalWrite(Trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trig, LOW);
   long Fdistance = pulseIn(Echo, HIGH);
   Fdistance = Fdistance/148;//converts time delay to distance
   return (int)Fdistance;
   }


void loop(){
   long inches; //make floating point variable to hold distance
   pinMode(Trig, OUTPUT);//Tell Trig pin to output sound
   pinMode(Echo, INPUT);
   int middleDistance = Distance_test();//runs distance test sub-routine

   //closes door if distance from object is greater than 8"
   if (middleDistance >= 10){
      digitalWrite(PIN_Motor_AIN_1,HIGH);
      digitalWrite(PIN_Motor_BIN_1,LOW);
      analogWrite(PIN_Motor_PWMA,127);
      analogWrite(PIN_Motor_PWMB,127);
   }
   //opens door otherwise
   else{
      digitalWrite(PIN_Motor_AIN_1,HIGH);
      digitalWrite(PIN_Motor_BIN_1,LOW);
      analogWrite(PIN_Motor_PWMA,127);
      analogWrite(PIN_Motor_PWMB,127);
   }

   if (digitalRead(button)==HIGH){ // if button is pressed
    if (ledflag==0) {             // and the status flag is LOW
      ledflag=1;                  // make status flag HIGH
      digitalWrite(led,HIGH);     // and turn on the LED
      }                           //
    else {                        // otherwise...
      ledflag=0;                  // make status flag LOW
      digitalWrite(led,LOW);      // and turn off the LED
    }
  delay(1000);                    // w
   Serial.print(button);

}
}

