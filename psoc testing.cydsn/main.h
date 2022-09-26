#ifndef MAIN_H
#define MAIN_H

#include "project.h"
    
#include "frame.h"

CY_ISR_PROTO(timerIntISR);
CY_ISR_PROTO(switchIntISR);

uint8 tickCount;
uint8 reset;
uint8 curFrame;
uint8 nextFrame;

CY_ISR(timerIntISR);
CY_ISR(switchIntISR);

int main(void);

#endif