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
const int val = 40;

void setup() {
    pinMode(PIN_Motor_PWMA, OUTPUT);
    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
    pinMode(PIN_Motor_STBY, OUTPUT);
}

//A Motors are Right
//B Motors are Left
void loop() {
    digitalWrite(PIN_Motor_STBY,HIGH);

    if (analogRead(A1) <= val) {
        //A1 = Middle Sensor
        //Both Motors Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
    }
    else if (analogRead(A0) > val) {
        //A0 = Left Sensor
        //Right Motors Backward
        digitalWrite(PIN_Motor_AIN_1,LOW);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_MidL);
        analogWrite(PIN_Motor_PWMB,speed_MidL);
    }
    else if (analogRead(A2) > val) {
        //A2 = Right Sensor
         //Left Motors Backward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,LOW);
        analogWrite(PIN_Motor_PWMA,speed_MidL);
        analogWrite(PIN_Motor_PWMB,speed_MidL);
    }
}