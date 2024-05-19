#include "sculptor.h"

int main(void)
{
    Sculptor homer_simpson(100, 105, 100);

    homer_simpson.setColor(0.984, 0.847, 0.01, 1.0); 
    homer_simpson.putBox(21, 50, 60, 92, 1, 30); // Cabeca
    homer_simpson.cutBox(22, 49, 61, 91, 2, 29); // Cabeca oca
    homer_simpson.putBox(23, 48, 92, 94, 3, 28); // Detalhe cabeca
    homer_simpson.putBox(25, 46, 94, 96, 5, 26); 

    homer_simpson.setColor(1.0, 1.0, 1.0, 1.0);
    homer_simpson.putBox(27, 44, 99, 100, 9, 10); // Cabelo
    homer_simpson.putBox(25, 26, 97, 98, 9, 10);
    homer_simpson.putBox(23, 24, 95, 96, 9, 10);
    homer_simpson.putBox(45, 46, 97, 98, 9, 10);
    homer_simpson.putBox(47, 48, 95, 96, 9, 10);
    homer_simpson.putBox(27, 44, 99, 100, 20, 21); // Cabelo
    homer_simpson.putBox(25, 26, 97, 98, 20, 21);
    homer_simpson.putBox(23, 24, 95, 96, 20, 21);
    homer_simpson.putBox(45, 46, 97, 98, 20, 21);
    homer_simpson.putBox(47, 48, 95, 96, 20, 21);

    // falta cabelo lateral
    
    homer_simpson.setColor(0.9, 0.9, 0.9, 0.9); 
    homer_simpson.putBox(24, 32, 78, 86, 30, 30); // Olho esquerdo
    homer_simpson.setColor(1.0, 1.0, 1.0, 1.0); 
    homer_simpson.putBox(27, 29, 81, 83, 30, 30); // bola do olho esquerdo
    homer_simpson.setColor(0.9, 0.9, 0.9, 0.9); 
    homer_simpson.putBox(39, 47, 78, 86, 30, 30); // Olho direito
    homer_simpson.setColor(1.0, 1.0, 1.0, 1.0); 
    homer_simpson.putBox(42, 44, 81, 83, 30, 30); // bola do olho direito

    homer_simpson.setColor(0.831, 0.788, 0.024, 0.988);
    homer_simpson.putBox(33, 38, 71, 77, 30, 32); // Nariz

    homer_simpson.setColor(0.831, 0.788, 0.024, 0.988);
    homer_simpson.putBox(18, 20, 78, 83, 17, 20); // Orelha esquerda
    homer_simpson.putBox(51, 53, 78, 83, 17, 20); // Orelha direita

    homer_simpson.setColor(0.82, 0.639, 0.439, 1.0); 
    homer_simpson.putBox(21, 50, 60, 70, 28, 30); // Boca
    homer_simpson.putBox(21, 50, 60, 67, 26, 28); // Boca
    homer_simpson.putBox(21, 50, 60, 63, 24, 25); // Boca

    homer_simpson.setColor(1.0, 1.0, 1.0, 1.0);
    homer_simpson.putBox(30, 41, 66, 66, 30, 30); // Labio
    
    homer_simpson.writeOFF("../homer_simpson.off");

}
