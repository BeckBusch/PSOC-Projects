#include "frame.h"

void createScene() {
    scene.frameCount = 2;
    
    scene.frameList[0].pos = 0;
    
    scene.frameList[0].port12[0] = 1;
    scene.frameList[0].port12[3] = 1;
    scene.frameList[0].port12[6] = 1;
    
    scene.frameList[1].pos = 150;
    
    scene.frameList[1].port12[3] = 1;
}