#include "CutSphere.h"
#include <iostream>

CutSphere::CutSphere(int xc, int yc, int zc, int radius)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->radius = radius;
}

void CutSphere::draw(Sculptor &s){
    std::cout<< "  > cut Sphere at (" <<xc<<", "<<yc<<", "<<zc<<")\n";
    s.setColor(r, g, b, alfa);
    s.cutSphere(xc, yc, zc, radius);
}
