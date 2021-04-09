#include <iostream>
#include <cstdlib>
#include "Sculptor.h"
#include <vector>
#include "GeometricFigure.h"
#include "Interpreter.h"

using namespace std;

int main()
{
    Sculptor *model;

    Interpreter Inter;

    std::vector<GeometricFigure*> figs;

    figs = Inter.compile("text_scripts/all.txt");

    model = new Sculptor(Inter.getDimX(), Inter.getDimY(), Inter.getDimZ());

    std::cout<<"\nLOG:\n";
    for (int i = 0; i < (int) figs.size(); i++){
        figs[i]->draw(*model);
    }

    model->putVoxel(Inter.getDimX() - 1, Inter.getDimY() - 1, Inter.getDimZ() - 1);
    model->putVoxel(0, 0, 0);
    model->writeOFF("models/script/all.off");

    for(int i = 0; i < (int) figs.size(); i++){
        delete figs[i];
    }
    delete model;

    return 0;
}
