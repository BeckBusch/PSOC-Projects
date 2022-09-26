#include "main.h"

CY_ISR(timerIntISR) {
    tickCount++;
    if (tickCount > 250) {
        tickCount = 0;
    }
    
    ledPin_Write(!ledPin_Read());
}

CY_ISR(switchIntISR) {
    
}
int main(void) {
    CyGlobalIntEnable;
    tickTimer_Start();
    timerInt_StartEx(timerIntISR);
    
    
    for(;;) {
       
    }
}

/* [] END OF FILE */
