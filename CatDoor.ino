#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8
const int BUTON = 10;
int ButtonState = 0;
int Flag = 0;

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
   Serial.print(button);
}
