#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8
#define LightO 11
#define BUTTON 10

//Ultrasonic Sensor Presets
const int Echo = 12;
const int Trig = 13;

const int Echo2 = A2;
const int Trig2 = A1;

int Flag = 0;
int Flag2 = 0;

void setup(){
   pinMode(PIN_Motor_PWMA, OUTPUT);
   pinMode(PIN_Motor_AIN_1, OUTPUT);
   pinMode(PIN_Motor_PWMB, OUTPUT);
   pinMode(PIN_Motor_BIN_1, OUTPUT);
   pinMode(PIN_Motor_STBY, OUTPUT);
   pinMode(LightO, OUTPUT);
   digitalWrite(PIN_Motor_STBY,HIGH); //turns motor on
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

//copy
int Distance_test2(){
   digitalWrite(Trig2, LOW);
   delayMicroseconds(2);
   digitalWrite(Trig2, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trig2, LOW);
   long Fdistance2 = pulseIn(Echo2, HIGH);
   Fdistance2 = Fdistance2/148;//converts time delay to distance
   return (int)Fdistance2;
   }


void openDoor(){
digitalWrite(PIN_Motor_AIN_1,LOW);
         digitalWrite(PIN_Motor_BIN_1,LOW);
         analogWrite(PIN_Motor_PWMA,127);
         analogWrite(PIN_Motor_PWMB,127);
         delay (3100);
         analogWrite(PIN_Motor_PWMA,0);
         analogWrite(PIN_Motor_PWMB,0);
         delay (6000);
         digitalWrite(PIN_Motor_AIN_1,HIGH);
         digitalWrite(PIN_Motor_BIN_1,HIGH);
         analogWrite(PIN_Motor_PWMA,127);
         analogWrite(PIN_Motor_PWMB,127);
         delay (2800);
}

void loop(){
   //move declarations out of the loop
   long inches; //make floating point variable to hold distance
   pinMode(Trig, OUTPUT);//Tell Trig pin to output sound
   pinMode(Echo, INPUT);
   int middleDistance = Distance_test();//runs distance test sub-routine
   int ButtonState = digitalRead(BUTTON);
   pinMode(BUTTON, INPUT);

//declarations for second ultrasonic sensor
long inches2; //make floating point variable to hold distance
   pinMode(Trig2, OUTPUT);//Tell Trig pin to output sound
   pinMode(Echo2, INPUT);
   int middleDistance2 = Distance_test2();//runs distance test sub-routine
   int ButtonState2 = digitalRead(BUTTON);
   pinMode(BUTTON, INPUT);

//First Ultrasonic Sensor
   if (ButtonState == 0 && Flag == 0){
      Flag = 1;
   }
   else if (ButtonState == 0 && Flag == 1){
      Flag = 0;
   }
   if (Flag == 1){
      digitalWrite(LightO, HIGH);
      // closes door if distance from cat is greater than 8"
      if (middleDistance >= 5){
         analogWrite(PIN_Motor_PWMA,0);
         analogWrite(PIN_Motor_PWMB,0);
      }
      // opens door otherwise
      else{
         openDoor();
      }
   }
   else {
      analogWrite(PIN_Motor_PWMA,0);
      analogWrite(PIN_Motor_PWMB,0);
      digitalWrite(LightO, LOW);
   }
   //-------------------------------------------------------------
   //Second Sensor
   if (ButtonState2 == 0 && Flag2 == 0){
      Flag2 = 1;
   }
   else if (ButtonState2 == 0 && Flag2 == 1){
      Flag2 = 0;
   }
   if (Flag2 == 1){
      digitalWrite(LightO, HIGH);
      // closes door if distance from cat is greater than 8"
      if (middleDistance2 >= 5){
         analogWrite(PIN_Motor_PWMA,0);
         analogWrite(PIN_Motor_PWMB,0);
      }
      // opens door otherwise
      else{
         openDoor();
      }
   }
   else {
      analogWrite(PIN_Motor_PWMA,0);
      analogWrite(PIN_Motor_PWMB,0);
      digitalWrite(LightO, LOW);
   }

}
