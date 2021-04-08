#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "GeometricFigure.h"
#include "Sculptor.h"


class CutEllipsoid : public GeometricFigure
{
private:
    int xc, yc, zc, xr, yr, zr;

public:
    CutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr);

    ~CutEllipsoid(){}

    void draw(Sculptor &s);

};

#endif // CUTELLIPSOID_H
