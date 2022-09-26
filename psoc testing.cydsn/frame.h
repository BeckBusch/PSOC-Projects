#ifndef FRAME_H_
#define FRAME_H_

#include "project.h"

struct frame {
    int pos;
    
    int port12[8];
};

struct frameList {
    int frameCount;
    struct frame frameList[];
};

struct frameList scene;

void createScene();

#endif