#include "CutVoxel.h"
#include <iostream>

CutVoxel::CutVoxel(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    //std::cout<< "\nteste construtor\n";
}

void CutVoxel::draw(Sculptor &s)
{
    std::cout<< "  > cut Voxel at (" <<x<<", "<<y<<", "<<z<<")\n";
//    s.setColor(r, g, b, alfa);
    s.cutVoxel(x, y, z);
}
