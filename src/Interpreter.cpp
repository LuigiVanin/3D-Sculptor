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
#include "CutDisc.h"
#include "PutDisc.h"

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
    int x0, y0, z0, l, h, w, xr, yr, zr, radius, axis;

    f.open(filename.c_str());

    std::cout<< "> Trying to open \"" << filename << "\" file...  ";
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

                else if(keyWord.compare("putEll") == 0){
                    ss >> x0 >> y0 >> z0 >> xr >> yr >> zr >> r >> g >> b >> alfa;
                    figs.push_back(new PutEllipsoid(x0, y0, z0, xr, yr, zr, r, g, b, alfa));
                }

                else if(keyWord.compare("putDisc") == 0){
                    ss >> x0 >> y0 >> z0 >> radius >> h >> axis >> r >> g >> b >> alfa;
                    figs.push_back(new PutDisc(x0, y0, z0, radius, h, axis, r, g, b, alfa));
                }

                else if(keyWord.compare("cutVoxel") == 0){
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0, y0, z0));
                }

                else if(keyWord.compare("cutSphere") == 0){
                    ss >> x0 >> y0 >> z0 >> radius;
                    figs.push_back(new CutSphere(x0, y0, z0, radius));
                }

                else if(keyWord.compare("cutBox") == 0){
                    ss >> x0 >> y0 >> z0 >> l >> h >> w;
                    figs.push_back(new CutBox(x0, y0, z0, l, h, w));
                }

                else if(keyWord.compare("cutEll") == 0){
                    ss >> x0 >> y0 >> z0 >> xr >> yr >> zr;
                    figs.push_back(new CutEllipsoid(x0, y0, z0, xr, yr, zr));
                }

                else if(keyWord.compare("cutDisc") == 0){
                    ss >> x0 >> y0 >> z0 >> radius >> h >> axis;
                    figs.push_back(new CutDisc(x0, y0, z0, radius, h, axis));
                }

                else {
                    f.close();
                    std::cout <<"\nKeyWord \"" << keyWord << "\" not defined\n";
                    exit(1);
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
