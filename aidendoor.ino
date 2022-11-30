#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define Light1 6
#define PIN_Motor_AIN_1 7
#define LightO 11
#define BUTTON 10

//Ultrasonic Sensor Presets
const int Echo = 12;
const int Trig = 13;

int Flag = 0;

void setup(){
   Serial.begin(9600);

   pinMode(PIN_Motor_PWMA, OUTPUT);
   pinMode(PIN_Motor_AIN_1, OUTPUT);
   pinMode(Light1, OUTPUT);
   pinMode(LightO, OUTPUT);
   pinMode(PIN_Motor_STBY, OUTPUT);
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


void loop(){
   //move declarations out of the loop

   long inches; //make floating point variable to hold distance
   pinMode(Trig, OUTPUT);//Tell Trig pin to output sound
   pinMode(Echo, INPUT);
   int middleDistance = Distance_test();//runs distance test sub-routine
   int ButtonState = digitalRead(BUTTON);
   pinMode(BUTTON, INPUT);


   if (ButtonState == 0 && Flag == 0){
      Flag = 1;
   }
   else if (ButtonState == 0 && Flag == 1){
      Flag = 0;
   }

   if (Flag == 1){
      digitalWrite(LightO, HIGH);
      digitalWrite(Light1, LOW);
      // closes door if distance from cat is greater than 8"
      if (middleDistance >= 10){
         digitalWrite(PIN_Motor_AIN_1,HIGH);
         analogWrite(PIN_Motor_PWMA,127);
         delay (5000);
      }
      // opens door otherwise
      else{
         digitalWrite(PIN_Motor_AIN_1,LOW);
         analogWrite(PIN_Motor_PWMA,127);
         delay (5000);
      }
   }
   else {
      digitalWrite(PIN_Motor_AIN_1,LOW);
      analogWrite(PIN_Motor_PWMA,0);
      digitalWrite(Light1, HIGH);
      digitalWrite(LightO, LOW);

   }
   Serial.println(middleDistance);
}