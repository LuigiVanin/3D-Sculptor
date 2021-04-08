#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "GeometricFigure.h"
#include "Sculptor.h"

class CutSphere : public GeometricFigure
{
private:
    int xc, yc, zc, radius;

public:
    CutSphere(int xc, int yc, int zc, int radius);

    ~CutSphere(){}

    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
