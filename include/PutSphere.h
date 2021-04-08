#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "Sculptor.h"
#include "GeometricFigure.h"

class PutSphere : public GeometricFigure
{
private:
    int xc, yc, zc, radius;

public:
    PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float alfa);

    ~PutSphere(){}

    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
