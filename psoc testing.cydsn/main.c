#include "main.h"
#include "frame.h"

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
            
            pin12_0_Write(scene.frameList[curFrame].port12[0]);
            pin12_1_Write(scene.frameList[curFrame].port12[1]);
            pin12_2_Write(scene.frameList[curFrame].port12[2]);
            pin12_3_Write(scene.frameList[curFrame].port12[3]);
            pin12_4_Write(scene.frameList[curFrame].port12[4]);
            pin12_5_Write(scene.frameList[curFrame].port12[5]);
            pin12_6_Write(scene.frameList[curFrame].port12[6]);
            pin12_7_Write(scene.frameList[curFrame].port12[7]);
        }
    }
}

void createScene() {
    scene.frameCount = 2;
    
    scene.frameList[0].pos = 0;
    
    scene.frameList[0].port12[0] = 1;
    scene.frameList[0].port12[3] = 1;
    scene.frameList[0].port12[6] = 1;
    
    scene.frameList[1].pos = 15;
    
    scene.frameList[1].port12[3] = 1;
}

/* [] END OF FILE */
