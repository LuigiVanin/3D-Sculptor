#include <iostream>
#include <cstdlib>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor sculpture(50, 50, 50);

    sculpture.putVoxel(0, 0, 0);
    sculpture.putVoxel(49, 49,49);

    sculpture.putSphere(24, 24, 20, 35);

    sculpture.writeOFF((char*) "models/test.off");
    return 0;
}
