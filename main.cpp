#include <iostream>
#include <cstdlib>
#include "Sculptor.h"
#include "PutVoxel.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor sculpture(50, 50, 50);

    sculpture.putVoxel(0, 0, 0);
    sculpture.putVoxel(49, 49,49);

    PutVoxel p(20, 20, 20, 0, 1, 0, 0);
    p.draw(sculpture);

    //sculpture.putSphere(24, 24, 0, 35);

    sculpture.writeOFF((char*) "models/test.off");
    return 0;
}
