/*
 * 共有変数
*/
#ifndef _SHAREDVARS_H_
#define _SHAREDVARS_H_

    // Motor
    #define MOTOR_STOP  0
    #define MOTOR_ACCEL 1
    #define MOTOR_CONST 2
    #define MOTOR_BREAK 3
    extern unsigned char MOTOR_STATE;
    extern unsigned char MOTOR_SPEED;

    // State machine
    #define AGV_BOOT 0
    #define AGV_BOOT_ALM 1
    #define AGV_READY 2
    #define AGV_READY_ALM 3
    #define AGV_RUN 4
    #define AGV_SEARCH 5
    #define AGV_RUN_ALM 6

    extern unsigned char AGV_STATE;

#endif
