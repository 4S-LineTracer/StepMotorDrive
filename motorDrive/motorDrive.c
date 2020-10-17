/*
 * ステッピングモータ駆動
*/
#include "motorDrive.h"

void motorDrive(){
    static unsigned int pulseIndex = 0;

    // パルス周波数テーブル参照先を計算
    calcPulseFreqTableIndex(&pulseIndex, &MOTOR_STATE, &MOTOR_SPEED);

    // GRA1に設定
    GRA1 = accTable[pulseIndex];

    // 励磁
    stepOutput();
}

// パルス周波数テーブルを読み込む位置をずらす
// TODO: ここMOTOR_SPEEDとMOTOR_STATE関数内で書き換えること…ありますね
// パルスが一定以上になったらMOTOR_CONSTとかMOTOR_STOPにしなきゃならんもんな
void calcPulseFreqTableIndex(unsigned int* index, unsigned char* motorState, unsigned int* motorSpeed){
    switch (*motorState) {
        case MOTOR_STOP:
            GRA1 = 0x00;
            break;
        
        case MOTOR_ACCEL:
            break;

        case MOTOR_CONST:
            
            break;

        case MOTOR_BREAK:
            
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
