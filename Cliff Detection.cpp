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


void setup() {
    pinMode(PIN_Motor_PWMA, OUTPUT);
    pinMode(PIN_Motor_AIN_1, OUTPUT);
    pinMode(PIN_Motor_PWMB, OUTPUT);
    pinMode(PIN_Motor_BIN_1, OUTPUT);
    pinMode(PIN_Motor_STBY, OUTPUT);
}

void loop() {
    if 
}