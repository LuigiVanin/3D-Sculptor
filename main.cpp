#include <iostream>
#include <cstdlib>
#include "Sculptor.h"
#include <vector>
#include "GeometricFigure.h"
#include "Interpreter.h"

int main(int argc, char* argv[])
{
    std::string path_script(argc > 1 ? argv[1] : "scripts/test.txt");
    std::string path_model(argc > 2 ? argv[2] : "./model.off");
    
    Interpreter Inter;
    std::vector<GeometricFigure*> figs;
    figs = Inter.compile(path_script);
    Sculptor *model = new Sculptor(Inter.getDimX(), Inter.getDimY(), Inter.getDimZ());
    std::cout<<"\nLOG:\n";
    for (int i = 0; i < (int) figs.size(); i++){
        figs[i]->draw(*model);
    }

    model->writeOFF(path_model);

    for(int i = 0; i < (int) figs.size(); i++){
        delete figs[i];
    }
    delete model;

    return 0;
}
