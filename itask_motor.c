/*
 * ステッピングモータ制御タスク
*/
#include "itask_motor.h"
#include "motorDrive.h"

void itask_motor(){
    motorDrive(&MOTOR_STATE, &MOTOR_SPEED);
}
