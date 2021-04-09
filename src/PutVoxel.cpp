#include "PutVoxel.h"
#include <iostream>

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float alfa)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->alfa = alfa;
}

void PutVoxel::draw(Sculptor &s)
{
    std::cout<< "  > draw Voxel at (" <<x<<", "<<y<<", "<<z<<")\n";
    s.setColor(r, g, b, alfa);
    s.putVoxel(x, y, z);
}
