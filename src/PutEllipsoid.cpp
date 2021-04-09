#include "PutEllipsoid.h"
#include <iostream>

PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr, float r, float g, float b, float alfa)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->xr = xr;
    this->yr = yr;
    this->zr = zr;
    this->r = r;
    this->g = g;
    this->b = b;
    this->alfa = alfa;
}

void PutEllipsoid::draw(Sculptor &s){
    std::cout<< "  > draw Ellipsoid at (" <<xc<<", "<<yc<<", "<<zc<<")\n";
    s.setColor(r, g, b, alfa);
    s.putEllipsoid(xc, yc, zc, xr, yr, zr);
}
