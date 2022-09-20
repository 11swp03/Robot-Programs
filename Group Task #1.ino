#include <arduino.h>

//defines which pins do what
#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8

//Motor Speed Presets
const int speed_Zero = 0; //0% duty load
const int speed_Min = 64; //25% duty load
const int speed_MidL = 127; //50% duty load
const int speed_MidH = 191; //75% duty load
const int speed_Max = 255; //100% duty load

//sets delay variables making it easier to change them all at once
const int FDelay = 1500; //at speed_Min is approx. 1 feet
const int TDelay = 1050; //at speed_Min is approx. 90 degrees

void setup () {
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
        delay((2 * FDelay));

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
        delay((3 * FDelay));

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
        delay((4 * FDelay));
}

void loop () {}