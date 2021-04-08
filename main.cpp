#include <iostream>
#include <cstdlib>
#include "Sculptor.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"

using namespace std;

int main()
{
    //main temporarily for testss
    Sculptor sculpture(50, 50, 50);

    sculpture.putVoxel(0, 0, 0);
    sculpture.putVoxel(49, 49,49);

    PutVoxel p(20, 20, 20, 0, 1, 0, 0);
    CutVoxel c(20, 20, 20);
    PutBox b(5, 5, 5, 10, 10, 10, 0, 1, 0, 0);
    CutBox cb(5, 5, 5, 5, 5, 5);
    PutSphere ps(35, 35, 35, 10, 1, 0, 0, 0);
    CutSphere cs(40, 40, 40, 10);
    PutEllipsoid e(10, 10, 35, 15, 10, 10, 0, 0, 1, 0);

    p.draw(sculpture);
    c.draw(sculpture);
    b.draw(sculpture);
    cb.draw(sculpture);
    ps.draw(sculpture);
    cs.draw(sculpture);
    e.draw(sculpture);

    //sculpture.putSphere(24, 24, 0, 35);

    sculpture.writeOFF((char*) "models/test.off");
    return 0;
}
