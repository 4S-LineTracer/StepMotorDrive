/*
 * ステッピングモータ駆動
*/
#include "motorDrive.h"

// itask_motorからの実行を想定
void motorDrive(unsigned char* motorState, unsigned char* motorSpeed){
    static unsigned int pulseIndex = 0;

    // GRA1に設定
    GRA1 = accTable[pulseIndex];
    #ifdef DEBUG
        printf("index: %d\n", pulseIndex);
    #endif

    // 励磁
    if(*motorState != MOTOR_STOP){
        stepOutput();
    }

    // パルス周波数テーブルの参照先を移動する
    calcPulseFreqTableIndex(&pulseIndex, motorState, motorSpeed);
}

// パルス周波数テーブルを読み込む位置を移動
void calcPulseFreqTableIndex(unsigned int* index, unsigned char* motorState, unsigned char* motorSpeed){
    // TODO: Switchは最善手ではないかも
    switch (*motorState) {
        case MOTOR_STOP:
            // do nothing in MOTOR_STOP
            break;
        
        case MOTOR_ACCEL:
            // インデックスを加算
            (*index)++;

            // インデックス位置>=最大速度なら状態遷移
            if(*index >= 399){
                *motorState = MOTOR_CONST;
                *index = 399;
                break;
            }

            break;

        case MOTOR_CONST:
            // do nothing in MOTOR_CONST
            break;

        case MOTOR_BREAK:
            // インデックスを減算
            (*index)--;

            // indexが0になったら状態遷移
            if(*index == 0){
                *motorState = MOTOR_STOP;
                break;
            }
            break;
        
        default:
            break;
    }
}

// ステッピングモータに励磁信号を出力
void stepOutput(){
    static int index = 0;

    #ifndef DEBUG
        //bios_step_output(index);
    #else
        printf("bios_step_output: %d\n", index);
    #endif

    // インデックスを移動する
    index++;
    index &= 3;
}
