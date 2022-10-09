#ifndef FRAME_H
#define FRAME_H

#include "project.h"


struct frame {
    int pos;
    
    int blockA;
};


struct frameList {
    int frameCount;
    struct frame frameList[];
};

struct frameList scene;

void createScene();

#endif
