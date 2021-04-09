#include <iostream>
#include <fstream>
#include <cmath>
#include "Sculptor.h"
#include <queue>
#include <string>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    std::cout<< "\n==SCULPTOR INIT==\n\n";
    nx = _nx, ny = _ny, nz = _nz;
    r = g = b = alfa = 0.5;
    side = 0.5;
    alocaMemoria();
}

Sculptor:: ~Sculptor()
{
    for (int x = 0; x < nx; x++){
        for(int y = 0; y<ny; y++){
            delete v[x][y];
        }
    }

    for (int x = 0; x < nx; x++){
        delete v[x];
    }

    delete v;

    std::cout<< "\n==SCULPTOR FINISHED==\n";
}

void Sculptor::alocaMemoria()
{
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
    std :: cout << "\nmatrix memory alocated\n";
}

void Sculptor::limpaVoxels(void)
{
    std::queue<int> q;
    int lx,ly,lz;
    for(int x=1; x<nx-1; x++){
        for(int y=1; y<ny-1; y++){
            for(int z=1; z<nz-1; z++){
                if((v[x][y][z].isOn == true) &&
                (v[x+1][y][z].isOn == true) &&
                (v[x-1][y][z].isOn == true) &&
                (v[x][y+1][z].isOn == true) &&
                (v[x][y-1][z].isOn == true) &&
                (v[x][y][z+1].isOn == true) &&
                (v[x][y][z-1].isOn == true)){
                    q.push(x);
                    q.push(y);
                    q.push(z);
                }
            }
        }
    }
    while(!q.empty()){
        lx=q.front(); q.pop();
        ly=q.front(); q.pop();
        lz=q.front(); q.pop();
        v[lx][ly][lz].isOn = false;
    }
    std::cout<< "\nfile optimazed(cleanig non visible Voxels)!\n" << std::endl;
}

void Sculptor::setColor(float _r, float _g, float _b, float _alfa){
    r = _r;
    g = _g;
    b = _b;
    alfa = _alfa;
}

void Sculptor::putVoxel(int x, int y, int z){
    if ((x < nx && x >= 0) && (y < ny  && y >= 0) && (z < nz && z >= 0))
    {
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].alfa = alfa;
        v[x][y][z].isOn = true;
    }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    if ((x < nx && x >= 0) && (y < ny  && y >= 0) && (z < nz && z >= 0))
    {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int y0, int z0, int length, int height, int width){
    for (int x = x0; x < x0 + length; x++){
        for(int y = y0; y < y0 + height; y++){
            for(int z = z0; z < z0 + width; z++){
                Sculptor::putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int y0, int z0, int l, int h, int w){
    for (int x = x0; x < x0 + l; x++){
        for(int y = y0; y < y0 + h; y++){
            for(int z = z0; z < z0 + w; z++){
                Sculptor::cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putDisc(int xcenter,int ycenter,int zcenter,int r, int h, int axis){
    for (int y = ycenter; y < ycenter+ h; y++){
        for(int x = xcenter - r; x < xcenter + r; x++){
            for(int z = zcenter - (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z < zcenter + (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z++ ){
                if(axis == 0)
                {
                    Sculptor::putVoxel(y, x, z);
                }
                else if(axis == 1)
                {
                    Sculptor::putVoxel(x, y, z);
                }
                else if(axis == 2)
                {
                    Sculptor::putVoxel(x, z, y);
                }
            }
        }
    }
}

void Sculptor::cutDisc(int xcenter,int ycenter,int zcenter,int r, int h, int axis){
    for (int y = ycenter; y < ycenter+ h; y++){
        for(int x = xcenter - r; x < xcenter + r; x++){
            for(int z = zcenter - (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z < zcenter + (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z++ ){
                if(axis == 0)
                {
                    Sculptor::cutVoxel(y, x, z);
                }
                else if(axis == 1)
                {
                    Sculptor::cutVoxel(x, y, z);
                }
                else if(axis == 2)
                {
                    Sculptor::cutVoxel(x, z, y);
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int r){
    for(int x = xcenter - r; x < xcenter + r; x++){
        for(int y = ycenter - r; y < ycenter + r; y++){
            for(int z = zcenter - r; z < zcenter + r; z++){
                if(pow(z - zcenter, 2) + pow(y - ycenter, 2) + pow(x - xcenter, 2) < pow(r, 2)){
                    Sculptor::putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int r){
    for(int x = xcenter - r; x < xcenter + r; x++){
        for(int y = ycenter - r; y < ycenter + r; y++){
            for(int z = zcenter - r; z < zcenter + r; z++){
                if(pow(z - zcenter, 2) + pow(y - ycenter, 2) + pow(x - xcenter, 2) < pow(r, 2)){
                    Sculptor::cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry,int rz){
    for(int x = xcenter - rx; x < xcenter + rx; x++){
        for(int y = ycenter - ry; y < ycenter + ry; y++){
            for(int z = zcenter - rz; z < zcenter + rz; z++){
                if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - ycenter, 2)/pow(ry, 2) + pow(x - xcenter, 2)/pow(rx, 2) < 1){
                    Sculptor::putVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry,int rz){
    for(int x = xcenter - rx; x < xcenter + rx; x++){
        for(int y = ycenter - ry; y < ycenter + ry; y++){
            for(int z = zcenter - rz; z < zcenter + rz; z++){
                if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - ycenter, 2)/pow(ry, 2) + pow(x - xcenter, 2)/pow(rx, 2) < 1){
                    Sculptor::cutVoxel(x, y, z);
                }
            }
        }
    }
}

void Sculptor::writeOFF(std::string filename)
{
    Sculptor::limpaVoxels();

    std::cout<<"trying to open " << filename <<" file... ";
    int index = 0, total = 0;
    std :: ofstream file;
    file.open(filename.c_str());

    if (!file.is_open()){
        std::cout<<"failed to open file\n";
        exit(0);
    }

    std::cout<<" file opened SUCEFULLY!!\n\n";
    file << "OFF\n";
    file << "#File generated by a C++ program created by Luis Felipe Vanin Martins\n";

    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].isOn == true)
                {
                    total++;
                }
            }
        }
    }
    file << total*8 << " " << total*6 << " 0\n";

    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].isOn == true)
                {
                    file << x - side << " " << y + side << " " << z - side << "\n" << std::flush;
                    file << x - side << " " << y - side << " " << z - side << "\n" << std::flush;
                    file << x + side << " " << y - side << " " << z - side << "\n" << std::flush;
                    file << x + side << " " << y + side << " " << z - side << "\n" << std::flush;
                    file << x - side << " " << y + side << " " << z + side << "\n" << std::flush;
                    file << x - side << " " << y - side << " " << z + side << "\n" << std::flush;
                    file << x + side << " " << y - side << " " << z + side << "\n" << std::flush;
                    file << x + side << " " << y + side << " " << z + side << "\n" << std::flush;
                }
            }
        }
    }
    total = 0;

    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].isOn == true)
                {
                    index = total*8;
                    //1°
                    file << 4 <<" "<< index + 0 <<" "<< index + 3 <<" "<< index + 2 <<" "<< index + 1 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
                    //2°
                    file << 4 <<" "<< index + 4 <<" "<< index + 5 <<" "<< index + 6 <<" "<< index + 7 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
                    //3°
                    file << 4 <<" "<< index + 0 <<" "<< index + 1 <<" "<< index + 5 <<" "<< index + 4 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
                    //4°
                    file << 4 <<" "<< index + 0 <<" "<< index + 4 <<" "<< index + 7 <<" "<< index + 3 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
                    //5°
                    file << 4 <<" "<< index + 3 <<" "<< index + 7 <<" "<< index + 6 <<" "<< index + 2 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
                    //6°
                    file << 4 <<" "<< index + 1 <<" "<< index + 2 <<" "<< index + 6 <<" "<< index + 5 <<std::fixed;
                    file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";

                    total++;
                }
            }
        }
    }

    file.close();
    std::cout<<filename<<" closed sucesseful!\n\n";
}

