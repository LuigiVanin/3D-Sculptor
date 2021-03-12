#include <iostream>
#include <fstream>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor v(1, 1, 1);

    cout << "hello world" << endl;

    cout << v.v[0][0][0].r << endl;

    v.setColor(0.1, 0.9, 0.3, 0);
    v.getColors();

    v.putVoxel(0, 0, 0);
//    v.putVoxel(3, 0, 8);
//    v.putVoxel(9, 9, 10);
    std :: cout << v.v[0][0][0].isOn << std:: endl;

    v.writeOFF((char*) "models/test.txt");
    return 0;
}
