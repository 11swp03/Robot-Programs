#include <arduino.h>

#define PIN_Motor_STBY 3
#define PIN_Motor_PWMA 5
#define PIN_Motor_PWMB 6
#define PIN_AIN_1 7
#define PIN_BIN_1 8

//Motor Speed Presets
int speed_Zero = 0;
int speed_Min = 64;
int speed_MidL = 127;
int speed_MidH = 191;
int speed_Max = 255;
//Analog Pin and Variable
int analogPin = A1;
int val = 40;

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

    if (analogRead(analogPin) <= val) {
        //Both Motors Forward
        digitalWrite(PIN_Motor_AIN_1,HIGH);
        digitalWrite(PIN_Motor_BIN_1,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_Min);
        analogWrite(PIN_Motor_PWMB,speed_Min);
    }
    else {
        //Right Motors Backward
        digitalWrite(PIN_Motor_AIN,LOW);
        digitalWrite(PIN_Motor_BIN,HIGH);
        analogWrite(PIN_Motor_PWMA,speed_MidL);
        analogWrite(PIN_Motor_PWMB,speed_MidL);
    }
}