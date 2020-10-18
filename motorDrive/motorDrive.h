/*
 * 
*/
#ifndef _MOTORDRIVE_H_
#define _MOTORDRIVE_H_

#define DEBUG // エミュレーションを有効化
#ifdef DEBUG
    #include <stdio.h>
    #include "sharedvars.h"
    #include "registors.h"
#endif

#include "accTable.h"

/* ---- functions ---- */

void motorDrive(unsigned char* motorState, unsigned char* motorSpeed);
void stepOutput();
void calcPulseFreqTableIndex(unsigned int* index, unsigned char* motorState, unsigned char* motorSpeed);

#endif