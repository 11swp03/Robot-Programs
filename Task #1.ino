#include <arduino.h>

#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_Motor_AIN_1 7
#define PIN_Motor_BIN_1 8

//Motor Speed Presets
const int speed_Zero = 0;
const int speed_Min = 64;
const int speed_MidL = 127;
const int speed_MidH = 191;
const int speed_Max = 255;
//Variable
const int FDelay = 2000;
const int TDelay = 1010;

//A Motors are Right
//B Motors are Left
void setup() {
    pinMode(PIN_Motor_PWMA, OUTPUT);
    
    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
    pinMode(PIN_Motor_STBY, OUTPUT);

    digitalWrite(PIN_Motor_STBY,HIGH);

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
        
        //Stop Motor
        analogWrite(PIN_Motor_PWMA,speed_Zero);
        analogWrite(PIN_Motor_PWMB,speed_Zero);
        digitalWrite(PIN_Motor_STBY,LOW);
    
}
 void loop () {}