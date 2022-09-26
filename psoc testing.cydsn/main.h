#ifndef MAIN_H
#define MAIN_H

#include "project.h"
    
#include "frame.h"

CY_ISR_PROTO(timerIntISR);
CY_ISR_PROTO(switchIntISR);

uint8 tickCount;

CY_ISR(timerIntISR);
CY_ISR(switchIntISR);

int main(void);

#endif