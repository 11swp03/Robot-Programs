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
//Variable
//sets delay variables making it easier to change them all at once
const int FDelay = 3000; //at speed_Min is approx. 2 feet
const int TDelay = 1050; //at speed_Min is approx. 90 degrees
const int HTDelay1 = 1400; //at speed_Min is approx. 315 degrees
const int HFDelay = 4243; //at speed_Min is approx. 2.8284
const int HTDelay2 = 480; //at speed_Min is approx. 45 degrees

//A Motors are Right
//B Motors are Left
//put code in setup so that it only runs once
void setup() {
    pinMode(PIN_Motor_PWMA, OUTPUT); 
    
    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
    pinMode(PIN_Motor_STBY, OUTPUT);

    digitalWrite(PIN_Motor_STBY,HIGH); //turns motor on

    //Move Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(FDelay);

    //Turn Right
        digitalWrite(PIN_Motor_AIN_1,LOW);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(TDelay);

    //Move Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(FDelay);

    //Turn Left
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,LOW);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(TDelay);

    //Move Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(FDelay);
    
    //Turn Left at Hypotenuse
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,LOW);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(HTDelay1);

    //Move Forward Along Hypotenuse
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(HFDelay);
    
    //Turn Left off Hypotenuse
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,LOW);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(HTDelay2);
        
    //Move Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
        delay(FDelay);

        //Stop Motor
        analogWrite(PIN_Motor_PWMA,speed_Zero);
        analogWrite(PIN_Motor_PWMB,speed_Zero);
        digitalWrite(PIN_Motor_STBY,LOW);
    
}
//even though no code is in loop, the loop command is still required for syntax
 void loop () {}