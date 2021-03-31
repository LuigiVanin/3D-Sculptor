#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"

class Sculptor {
protected:

    int nx,ny,nz; // Dimensions
    float r,g,b,alfa; // Current drawing color
    Voxel ***v;// 3D Matrix on public temporarily for tests
    float side;

public:

    Sculptor(int _nx = 1, int _ny = 1, int _nz = 1);
    ~Sculptor();

    void alocaMemoria();
    void limpaVoxels();
    void setColor(float r_, float g_, float b_, float alpha_);
    void getColors();
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int y0, int z0, int l, int h, int w);
    void cutBox(int x0, int y0, int z0, int l, int h, int w);
    void putDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1);
    void cutDisc(int xcenter, int ycenter, int zcenter, int r, int h, int axis = 1);
    void putSphere(int xcenter, int ycenter, int zcenter, int r);
    void cutSphere(int xcenter, int ycenter, int zcenter, int r);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(char* filename);

};

#endif // SCULPTOR_H
