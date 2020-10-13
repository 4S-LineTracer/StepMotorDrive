/*
 * ステッピングモータ駆動
*/
#include "motorDrive.h"

void motorDrive(){
    stepOutput();
}

void stepOutput(){
    static int index = 0;

    #ifndef DEBUG
        //bios_step_output(index);
    #else
        printf("bios_step_output: %d\n", index);
    #endif

    // インデックスを移動する
    index++;
    if(index > 3){
        index = 0;
    }
}