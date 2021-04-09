#include "CutDisc.h"
#include <iostream>

CutDisc::CutDisc(int xc, int yc, int zc, int radius, int h, int axis)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->radius = radius;
    this->h = h;
    this->axis = axis;
}

void CutDisc::draw(Sculptor &s){
    std::cout<< "  > cut Disc at (" <<xc<<", "<<yc<<", "<<zc<<")\n";
    s.cutDisc(xc, yc, zc, radius, h, axis);
}
