/*
 * 共通ヘッダ
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#define DEBUG

/* ---- processes for debug environment ---- */
#ifdef DEBUG
    #include <stdio.h>
    #include "sharedvars.h"
    #include "registors.h"
#endif

/* -------- */

#include "accTable.h"

#endif