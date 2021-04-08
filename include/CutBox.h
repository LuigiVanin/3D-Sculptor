#ifndef CUTBOX_H
#define CUTBOX_H
#include "GeometricFigure.h"

class CutBox : public GeometricFigure
{
private:
    int x0, y0, z0, length, height, width;;
public:
    CutBox(int x0, int y0, int z0, int length, int height, int width);

    ~CutBox();

    void draw(Sculptor &s);

};

#endif // CUTBOX_H
