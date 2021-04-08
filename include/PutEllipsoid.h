#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "Sculptor.h"
#include "GeometricFigure.h"

class PutEllipsoid : public GeometricFigure
{
private:
    int xc, yc, zc, xr, yr, zr;

public:
    PutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr, float r, float g, float b, float alfa);

    ~PutEllipsoid(){}

    void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
