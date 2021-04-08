#ifndef PUTVOXEL_H_INCLUDED
#define PUTVOXEL_H_INCLUDED
#include "GeometricFigure.h"

class PutVoxel : public GeometricFigure{
private:
    int x, y, z;

public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float alfa);
    ~PutVoxel(){}

    void draw(Sculptor &s);
};



#endif // PUTVOXEL_H_INCLUDED
