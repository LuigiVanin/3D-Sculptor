#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "../voxel.h"

class Sculptor {
protected:

    int nx,ny,nz; // Dimensions
    float r,g,b,alfa; // Current drawing color
public:
    Voxel ***v;// 3D Matrix on public temporarily for tests
    float lado;
    float delta;


    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();


    void alocaMemoria();
    void setColor(float r_, float g_, float b_, float alpha_);
    void getColors();
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);

    // functions that have yet to be implemented:
    //void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    //void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    //void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    //void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    //void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    //void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(char* filename);
};

#endif // SCULPTOR_H
