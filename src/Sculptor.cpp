#include <iostream>
#include "Sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx, ny = _ny, nz = _nz;
    r = g = b = alfa = 0.5;
    lado = 0.5;
    delta = 0;
    alocaMemoria();
}

Sculptor:: ~Sculptor(){

}

void Sculptor::alocaMemoria(){
    v = new Voxel**[nx];

    for (int x = 0; x < nx; x++){
        v[x] = new Voxel *[nx];
    }
    for (int x = 0; x < nx; x++){
        for(int y = 0; y<ny; y++){
            v[x][y] = new Voxel [nz];
        }
    }
    for (int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for (int z = 0; z < nz; z++){
                v[x][y][z].r = r;
                v[x][y][z].b = b;
                v[x][y][z].g = g;
                v[x][y][z].alfa = alfa;
                v[x][y][z].isOn = false;
            }
        }
    }
    std :: cout << "fuck the world\n";
}

void Sculptor::setColor(float _r, float _g, float _b, float _alfa){
    r = _r;
    g = _g;
    b = _b;
    alfa = _alfa;
}
void Sculptor::getColors(){
    std::cout <<r <<" "<< g<<" " << b<<" "<< alfa <<std::endl;
}


void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].alfa = alfa;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}
