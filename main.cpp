#include <iostream>
#include "sculptor.h"
#include "readtxt.h"

/**
 * \mainpage
 * @brief 3D Sculptor
 * \authors
 * Ramon Vinícius Ferreira de Souza \n
 * Henrique Antonio Guanais Corneau
 */
int main(void)
{
    ReadTXT arquivo("../input.txt");
    Sculptor figura(arquivo.getX(), arquivo.getY(), arquivo.getZ());

    arquivo.draw(figura);
    figura.writeOFF("../output.off");

    return 0;
}
