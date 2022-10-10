#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8

//Motor Speed Presets
//sets motor speed variables
const int speed_Zero = 0; //0% duty load
const int speed_Min = 64; //25% duty load
const int speed_MidL = 127; //50% duty load
const int speed_MidH = 191; //75% duty load
const int speed_Max = 255; //100% duty load
//Ultrasonic Sensor Presets
const int Echo = 12;
const int Trig = 13;
//Line Sensor Presets
int LT_R = analogRead(A0);
int LT_M = analogRead(A1);
int LT_L = analogRead(A2);

void setup(){
    pinMode(PIN_Motor_PWMA, OUTPUT);

    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
    pinMode(PIN_Motor_STBY, OUTPUT);

    digitalWrite(PIN_Motor_STBY,HIGH); //turns motor on

    Serial.begin(9600);
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

   Serial.print(inches);
  Serial.print(" in, ");
  Serial.print("LT_R = ");
  Serial.print(LT_R);
  Serial.print(", LT_M = ");
  Serial.print(LT_M);
  Serial.print(", LT_L = ");
  Serial.println(LT_L);
  Serial.println();

  delay(100);

   // moves forward if distance from object is greater than 8"
   if (middleDistance >= 8){
      if (LT_M > 100){
         digitalWrite(PIN_Motor_AIN_1,HIGH);
         digitalWrite(PIN_Motor_BIN_1,HIGH);
         analogWrite(PIN_Motor_PWMA,speed_MidL);
         analogWrite(PIN_Motor_PWMB,speed_MidL);
      }
      else if (LT_R > 100){
         digitalWrite(PIN_Motor_AIN_1,HIGH);
         digitalWrite(PIN_Motor_BIN_1,HIGH);
         analogWrite(PIN_Motor_PWMA,speed_Min);
         analogWrite(PIN_Motor_PWMB,speed_MidH);
      }
      else if (LT_L > 100) {
         digitalWrite(PIN_Motor_AIN_1,HIGH);
         digitalWrite(PIN_Motor_BIN_1,HIGH);
         analogWrite(PIN_Motor_PWMA,speed_MidH);
         analogWrite(PIN_Motor_PWMB,speed_Min);
      }
   }
   //Slows down otherwise
   else{
      digitalWrite(PIN_Motor_AIN_1,HIGH);
      digitalWrite(PIN_Motor_BIN_1,HIGH);
      analogWrite(PIN_Motor_PWMA,speed_Min);
      analogWrite(PIN_Motor_PWMB,speed_Min);
   }
}
