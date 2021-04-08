#include "PutSphere.h"
#include <iostream>

PutSphere::PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float alfa)
{
    this->xc = xc;
    this->yc = yc;
    this->zc = zc;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->alfa = alfa;
}

void PutSphere::draw(Sculptor &s){
    std::cout<< "\nteste draw Sphere\n";
    s.setColor(r, g, b, alfa);
    s.putSphere(xc, yc, zc, radius);
}
