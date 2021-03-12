#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor v(10, 10, 10);

    cout << "hello world" << endl;

    cout << v.v[0][0][0].r << endl;

    v.setColor(1, 1, 1, 1);
    v.getColors();

    v.putVoxel(0, 0, 0);

    v.setColor(1,0,0,1);
    for (int i = 0; i < 10; i++){
        v.setColor(((float) (rand()%10))/10,((float) (rand()%10))/10,((float) (rand()%10))/10,1);
        v.putVoxel(rand()%10, rand()%10, rand()%10);
    }
//    v.putVoxel(3, 0, 8);
//    v.putVoxel(9, 9, 10);
    std :: cout << v.v[0][0][0].isOn << std:: endl;

    v.writeOFF((char*) "models/test.off");
    return 0;
}
