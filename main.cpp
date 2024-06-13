#include <iostream>
#include "sculptor.h"
#include "readtxt.h"

int main(void)
{
    ReadTXT arquivo("../input.txt");
    Sculptor figura(arquivo.getX(), arquivo.getY(), arquivo.getZ());

    arquivo.draw(figura);
    figura.writeOFF("../output.off");

    return 0;
}
