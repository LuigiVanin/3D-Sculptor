#include <iostream>
#include <cstdlib>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor sculpture(50, 50, 50);

    cout << "hello world" << endl;

    sculpture.putVoxel(0, 0, 0);
    sculpture.putVoxel(49, 49,49);

    sculpture.writeOFF((char*) "models/test.off");
    return 0;
}
