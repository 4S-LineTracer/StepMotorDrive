/*
 * 共有変数
*/
#include "sharedvars.h"

// Motor
unsigned char MOTOR_STATE = MOTOR_STOP;
unsigned char MOTOR_SPEED = 0;

// State machine
unsigned char AGV_STATE = AGV_BOOT;
