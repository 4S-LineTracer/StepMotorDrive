/*
 * 単体テスト用main
*/
#include <stdio.h>

#include "common.h"
#include "motorDrive.h"

int main(int argc, char const *argv[]) {
    printf("Hello, World\n");

    MOTOR_STATE = MOTOR_ACCEL;
    MOTOR_SPEED = 255; // パーセンテージ指定 400データ*0.MOTOR_SPEED
    for (int i = 0; i < 2000; i++) {
        motorDrive();
        printf("MOTOR_STATE: %d GRA1: %lu\n", MOTOR_STATE, ((TSTR & 2) >= 1) * GRA1);

        if(MOTOR_STATE == MOTOR_CONST){
            MOTOR_STATE = MOTOR_BREAK;
        }
    }
    
    return 0;
}
