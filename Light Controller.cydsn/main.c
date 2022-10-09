#include "project.h"
#include "frame.h"

uint8 tickCount;
uint8 reset;
uint8 curFrame;
uint8 nextFrame;

CY_ISR_PROTO(timerIntISR);
CY_ISR_PROTO(switchIntISR);

CY_ISR(timerIntISR) {
    tickCount++;
    if (tickCount > 25) {
        tickCount = 0;
    }
    
    ledPin_Write(!ledPin_Read());
}

CY_ISR(switchIntISR) {
    reset = 1;
}

int main(void) {
    CyGlobalIntEnable;
    tickTimer_Start();
    timerInt_StartEx(timerIntISR);
    
    createScene();
    
    tickCount = 0;
    curFrame = 0;
    nextFrame = 1;
    reset = 0;
    
    for(;;) {
        if (reset) {
        tickCount = 0;
        curFrame = 0;
        reset = 0;
        }
        
        if (nextFrame >= scene.frameCount) {
            nextFrame = 0;
        }
        
        if (tickCount == scene.frameList[nextFrame].pos) {
            curFrame = nextFrame;
            nextFrame++;
            
            Control_Reg_A_Write(scene.frameList[curFrame].blockA);
        }
    }
}

void createScene() {
    scene.frameCount = 5;
    
    scene.frameList[0].pos = 0;
    scene.frameList[0].blockA = 0b00000001;
    
    scene.frameList[1].pos = 5;
    scene.frameList[1].blockA = 0b00000010;
    
    scene.frameList[2].pos = 10;
    scene.frameList[2].blockA = 0b00000100;
    
    scene.frameList[3].pos = 15;
    scene.frameList[3].blockA = 0b00001000;
    
    scene.frameList[4].pos = 20;
    scene.frameList[4].blockA = 0b00010000;
}

/* [] END OF FILE */
