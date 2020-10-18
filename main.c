/*
 * 単体テスト用main
*/
#include <stdio.h>

#include "motorDrive.h"
#include "itask_motor.h"

int main(int argc, char const *argv[]) {
    printf("Hello, World\n");

    // init
    MOTOR_STATE = MOTOR_ACCEL;
    MOTOR_SPEED = 255;
    TSTR |= 3;

    for (int i = 0; i < 2000; i++) {
        // タスク実行
        itask_motor();

        printf("MOTOR_STATE: %d GRA1: %lu\n", MOTOR_STATE, ((TSTR & 2) >= 1) * GRA1);

        if(MOTOR_STATE == MOTOR_CONST){
            MOTOR_STATE = MOTOR_BREAK;
        }

        if(MOTOR_STATE == MOTOR_STOP){
            MOTOR_STATE = MOTOR_ACCEL;
        }
        printf("--------\n");
    }
    
    return 0;
}
