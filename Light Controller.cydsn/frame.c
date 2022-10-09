#include "frame.h"

void createScene() {
    scene.frameCount = 3;
    
    scene.frameList[0].pos = 0;
    scene.frameList[0].blockA = 0b00000001;
    
    scene.frameList[1].pos = 5;
    scene.frameList[1].blockA = 0b00000010;
    
    scene.frameList[1].pos = 10;
    scene.frameList[1].blockA = 0b00000010;
    
    scene.frameList[2].pos = 15;
    scene.frameList[2].blockA = 0b00000100;
}