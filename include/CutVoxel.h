#ifndef CUTVOXEL_H_INCLUDED
#define CUTVOXEL_H_INCLUDED
#include "GeometricFigure.h"

class CutVoxel : public GeometricFigure
{
private:
    int x, y, z;

public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel(){}

    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H_INCLUDED
