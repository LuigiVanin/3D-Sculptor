#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Sculptor.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor v(20, 20, 20);

    cout << "hello world" << endl;

    v.setColor(1, 1, 1, 1);


    v.putVoxel(0, 0, 0);

    v.setColor(1,0,0,1);

    v.putBox(0,0,0, 19, 19, 19);
    v.cutBox(1,1,1, 18, 19, 18);
 //   for (int i = 0; i < 10; i++){
 //       v.setColor(((float) (rand()%10))/10,((float) (rand()%10))/10,((float) (rand()%10))/10,1);
 //       v.putVoxel(rand()%10, rand()%10, rand()%10);
 //   }


    v.writeOFF((char*) "models/test.off");
    return 0;
}
