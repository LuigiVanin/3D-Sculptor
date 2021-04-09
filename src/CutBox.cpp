#include "CutBox.h"
#include <iostream>

CutBox::CutBox(int x0, int y0, int z0, int length, int height, int width)
{
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->length = length;
    this->height = height;
    this->width = width;
}

CutBox::~CutBox()
{
}

void CutBox::draw(Sculptor &s){
    std::cout<< "  > cut Box at (" <<x0<<", "<<y0<<", "<<z0<<")\n";
    //s.setColor(r, g, b, alfa);
    s.cutBox(x0, y0, z0, length, height, width);
}
