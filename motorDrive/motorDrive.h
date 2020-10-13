/*
 *  
*/
#ifndef _MOTORDRIVE_H_
#define _MOTORDRIVE_H_

#include "func.h"

/* ------- */

#ifdef DEBUG
    #include <stdio.h>
#endif

/* ------- */

extern int MOTOR_STATE;

/* ------- */

void motorDrive();
void stepOutput();

#endif