#include "PutBox.h"
#include <iostream>

PutBox::PutBox(int x0, int y0, int z0, int length, int height, int width, float r, float g, float b, float alfa){
    this->x0 = x0;
    this->y0 = y0;
    this->z0 = z0;
    this->length = length;
    this->height = height;
    this->width = width;
    this->r = r;
    this->g = g;
    this->b = b;
    this->alfa = alfa;
}

void PutBox::draw(Sculptor &s){
    std::cout<< "\nteste draw Box\n";
    s.setColor(r, g, b, alfa);
    s.putBox(x0, y0, z0, length, height, width);
}
