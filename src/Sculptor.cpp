#include <iostream>
#include <fstream>
#include <cmath>
#include "Sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx, ny = _ny, nz = _nz;
    r = g = b = alfa = 0.5;
    side = 0.5;
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
    std :: cout << "memória alocada para a matriz\n";
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
    if ((x < nx && x >= 0) || (y < ny  && y >= 0) || (z < nz && z >= 0))
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
    if ((x < nx && x >= 0) || (y < ny  && y >= 0)|| (z < nz && z >= 0))
    {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::putBox(int x0, int y0, int z0, int l, int h, int w){
    for (int x = x0; x < x0 + l; x++){
        for(int y = y0; y < y0 + h; y++){
            for(int z = z0; z < z0 + w; z++){
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

void Sculptor::putDisc(int xcenter,int ycenter,int zcenter,int r, int h){
    for (int y = ycenter; y < ycenter+ h; y++){
        for(int x = xcenter - r; x < xcenter + r; x++){
            for(int z = zcenter - (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z < zcenter + (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z++ ){
                Sculptor::putVoxel(x, y, z );
            }
        }
    }
}

void Sculptor::cutDisc(int xcenter,int ycenter,int zcenter,int r, int h){
    for (int y = ycenter; y < ycenter+ h; y++){
        for(int x = xcenter - r; x < xcenter + r; x++){
            for(int z = zcenter - (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z < zcenter + (round(sqrt(pow(r, 2) - pow(x - xcenter, 2)))); z++ ){
                Sculptor::cutVoxel(x, y, z );
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


void Sculptor::writeOFF(char* filename)
{
    std::cout<<"opening file " << filename <<"...\n\n";
    int index = 0, total = 0;
    std :: ofstream file;
    file.open(filename);
    std::cout<< filename <<" file opened!\n\n";
    file << "OFF\n";

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

