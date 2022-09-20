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