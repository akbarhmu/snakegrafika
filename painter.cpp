#include "painter.hpp"
#include "GL/gl.h"
#include "math.h"
#include "stdlib.h"
#include<iostream>

using namespace std;

void Painter::bar(int x1, int y1, int x2, int y2) 
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void Painter::brick_bar(int x1, int y1, int x2, int y2)
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

int GetNumCircleSegments(float r) 
{
    return 15 * sqrtf(r);
}

void Painter::circle(int cx, int cy, int r) 
{
    glColor3f(rand() % 256 / 255.0, rand() % 256 / 255.0, rand() % 256 / 255.0); 
    int num_segments = GetNumCircleSegments(r);
    float theta = 2 * 3.1415926 / float(num_segments);
    float c = cosf(theta); 
    float s = sinf(theta);
    float t;

    float x = r; 
    float y = 0;

    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++) {
        glVertex2f(x + cx, y + cy);  		
        t = x;
        x = c * x - s * y; 
        y = s * t + c * y;
    }
    glEnd();

}