#ifndef PUTBOX_H
#define PUTBOX_H
#include "GeometricFigure.h"

class PutBox : public GeometricFigure{
private:
    int x0, y0, z0, length, height, width;

public:
    PutBox(int x0, int y0, int z0, int length, int height, int width, float r, float g, float b, float alfa);

    ~PutBox(){}

    void draw(Sculptor &s);

};

#endif // PUTBOX_H
