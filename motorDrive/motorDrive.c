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
    #ifdef DEBUG
        printf("index: %d\n", pulseIndex);
    #endif

    // 励磁
    stepOutput();
}

// パルス周波数テーブルを読み込む位置を移動
// TODO: ここMOTOR_SPEEDとMOTOR_STATE関数内で書き換えること…ありますね
// パルスが一定以上になったらMOTOR_CONSTとかMOTOR_STOPにしなきゃならんもんな
void calcPulseFreqTableIndex(unsigned int* index, unsigned char* motorState, unsigned char* motorSpeed){
    switch (*motorState) {
        case MOTOR_STOP:
            // ITU0,1を止めて、カウンタをリセット
            TSTR &= 0b11111100;
            GRA0 = 0;
            GRA1 = 0;
            break;
        
        case MOTOR_ACCEL:
            TSTR |= 0b00000011;

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
