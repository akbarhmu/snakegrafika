#pragma once
#include "unistd.h"

class Painter {
    public:
        void bar(int x1, int y1, int x2, int y2);
        void brick_bar(int x1, int y1, int x2, int y2);
        void circle(int cx, int cy, int r);
};