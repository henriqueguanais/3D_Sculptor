#include "sculptor.h"

int main(void)
{
    Sculptor teste(100, 100, 100);

    //teste voxel
    teste.setColor(1.0, 1.0, 1.0, 1.0);
    teste.putVoxel(0, 0, 0);
    teste.putVoxel(1, 1, 1);
    teste.cutVoxel(1, 1, 1);

    //teste box
    teste.setColor(0.8, 0.8, 0.8, 1.0);
    teste.putBox(20, 20, 20, 30, 30, 30);
    teste.cutBox(25, 25, 25, 30, 30, 30);

    //teste esfera
    teste.setColor(0.7, 0.7, 0.7, 1.0);
    teste.putSphere(50, 50, 50, 10);
    teste.cutSphere(55, 55, 55, 5);

    //teste Elipse
    teste.setColor(0.7, 0.7, 0.7, 1.0);
    teste.putEllipsoid(75, 75, 75, 5, 5, 10);
    teste.cutEllipsoid(80, 80, 80, 10, 10, 6);

    teste.writeOFF("../teste.off");
}