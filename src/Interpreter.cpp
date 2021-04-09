#include "Interpreter.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Sculptor.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"

Interpreter::Interpreter()
{
}

std::vector<GeometricFigure*> Interpreter::compile(std::string filename)
{
    std::ifstream f;
    std::vector<GeometricFigure*> figs;
    std::string keyWord;
    std::string s;
    std::stringstream ss;
    int x0, y0, z0, l, h, w, xr, yr, yz, radius;

    f.open(filename.c_str());

    std::cout<< "trying to open " << filename << " file...  ";
    if (!f.is_open()){
        std::cout<<"failed to open file\n";
        exit(0);
    }

    std::cout<<"file opened SUCEFULLY!!\n";

    while(f.good())
    {
        std::getline(f, s);
        if(f.good())
        {
            ss.clear();
            ss.str(s);
            ss >> keyWord;

            if(ss.good()){
                if(keyWord.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                }

                else if(keyWord.compare("putVoxel") == 0){
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> alfa;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, alfa));
                }

                else if(keyWord.compare("putSphere") == 0){
                    ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> alfa;
                    figs.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, alfa));
                }
                else if(keyWord.compare("putBox") == 0){
                    ss >> x0 >> y0 >> z0 >> l >> h >> w >> r >> g >> b >> alfa;
                    figs.push_back(new PutBox(x0, y0, z0, l, h, w, r, g, b, alfa));
                }
            }
        }
    }
    f.close();
    return figs;
}

int Interpreter::getDimX()
{
    return dimx;
}

int Interpreter::getDimY()
{
    return dimy;
}

int Interpreter::getDimZ()
{
    return dimz;
}
