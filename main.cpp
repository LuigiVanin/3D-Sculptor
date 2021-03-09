#include <iostream>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor v(1, 3, 8);

    cout << "hello world" << endl;

    cout << v.v[0][0][0].r << endl;

    v.setColor(0.1, 0.9, 0.3, 0);
    v.getColors();

    v.putVoxel(0, 2, 0);
    std :: cout << v.v[0][2][0].isOn << std:: endl;
    return 0;
}
