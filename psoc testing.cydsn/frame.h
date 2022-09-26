#ifndef FRAME_H
#define FRAME_H

#include "project.h"

struct frame {
    int port12[8];
};

struct frameList {
    int frameCount;
    struct frame frameList[];
};

#endif