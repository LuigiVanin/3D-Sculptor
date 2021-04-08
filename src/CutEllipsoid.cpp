#include "CutEllipsoid.h"
#include <iostream>

CutEllipsoid::CutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->xr = xr;
    this->yr = yr;
    this->zr = zr;
}

void CutEllipsoid::draw(Sculptor &s)
{
    std::cout<< "\nteste draw cut Ellipsoid\n";
    s.cutEllipsoid(xc, yc, zc, xr, yr, zr);
}


