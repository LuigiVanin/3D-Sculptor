#include "PutDisc.h"
#include <iostream>

PutDisc::PutDisc(int xc, int yc, int zc, int radius, int h, int axis, float r, float g, float b, float alfa)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->radius = radius;
    this->h = h;
    this->axis = axis;
    this->r = r;
    this->g = g;
    this->b = b;
    this->alfa = alfa;
}

void PutDisc::draw(Sculptor &s){
    std::cout<< "  > draw Disc at (" <<xc<<", "<<yc<<", "<<zc<<")\n";
    s.setColor(r, g, b, alfa);
    s.putDisc(xc, yc, zc, radius, h, axis);
}
