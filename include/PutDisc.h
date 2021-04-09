#ifndef PUTDISC_H
#define PUTDISC_H
#include "GeometricFigure.h"
#include "Sculptor.h"


class PutDisc : public GeometricFigure
{
private:
    int xc, yc, zc, radius, h, axis;

public:
    PutDisc(int xc, int yc, int zc, int radius, int h, int axis, float r, float g, float b, float alfa);

    ~PutDisc(){}

    void draw(Sculptor &s);
};

#endif // PUTDISC_H
