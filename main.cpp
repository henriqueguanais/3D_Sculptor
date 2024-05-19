#include "sculptor.h"

/**
 * \mainpage 
 * @brief Projeto Escultor 3D
 * \authors 
 * Ramon Vinícius Ferreira de Souza \n
 * Henrique Antônio Guanais Corneau
*/
int main(void)
{
    Sculptor homer_simpson(100, 105, 100);

    homer_simpson.setColor(0.984, 0.847, 0.01, 1.0); 
    homer_simpson.putBox(21, 50, 63, 92, 1, 30); // Cabeca
    homer_simpson.cutBox(22, 49, 64, 91, 2, 29); // Cabeca oca
    homer_simpson.putBox(23, 48, 92, 94, 3, 28); // Detalhe cabeca
    homer_simpson.putBox(25, 46, 94, 96, 5, 26); 
    homer_simpson.putBox(23, 48, 61, 63, 3, 28); 
    homer_simpson.putBox(25, 46, 59, 60, 5, 26);

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

    int alternar_cabelo = 1;
    for(int i = 0; i < 8; i++) {
        homer_simpson.putBox(51, 51, 84 + alternar_cabelo, 85 + alternar_cabelo, 14 - 2*i, 15 - 2*i); // Cabelo lateral direita
        homer_simpson.putBox(20, 20, 84 + alternar_cabelo, 85 + alternar_cabelo, 14 - 2*i, 15 - 2*i); // Cabelo lateral esquerda
        alternar_cabelo *= -1;
    }
    for(int i = 0; i < 15; i++) {
        homer_simpson.putBox(21 + 2*i, 22 + 2*i, 84 + alternar_cabelo, 85 + alternar_cabelo, 0, 0); // Cabelo traseiro
        alternar_cabelo *= -1;
    }

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
    homer_simpson.putBox(21, 50, 63, 70, 28, 30); // Boca
    homer_simpson.putBox(21, 50, 63, 67, 26, 28); // Boca
    homer_simpson.putBox(21, 50, 63, 65, 24, 25); // Boca
    homer_simpson.putBox(23, 48, 61, 63, 22, 28); 
    homer_simpson.putBox(25, 46, 59, 60, 20, 26);

    homer_simpson.setColor(1.0, 1.0, 1.0, 1.0);
    homer_simpson.putBox(30, 41, 66, 66, 30, 30); // Labio

    homer_simpson.setColor(0.9, 0.9, 0.9, 0.9);
    homer_simpson.putSphere(35, 40, 16, 20); // Corpo
    homer_simpson.cutBox(15, 55, 20, 60, 96, 100); // Tirar sobras
    homer_simpson.cutSphere(35, 40, 18, 17); // Corpo oco

    homer_simpson.putBox(49, 61, 49, 55, 10, 18); // Manga direita
    homer_simpson.cutBox(50, 60, 50, 51, 11, 17); // Manga oca
    homer_simpson.putBox(9, 21, 49, 55, 10, 18); // Manga esquerda
    homer_simpson.cutBox(10, 20, 50, 51, 11, 17); // Manga oca

    for(int i = 0; i < 3; i++) {
        homer_simpson.cutBox(9 + i, 9 + i, 53 + i, 55, 10, 18); // Detalhe manga esquerda
        homer_simpson.cutBox(61 - i, 61 - i, 53 + i, 55, 10, 18); // Detalhe manga direita
    }

    homer_simpson.setColor(0.984, 0.847, 0.01, 1.0);
    homer_simpson.putBox(52, 61, 20, 48, 10, 18); // Mao direita 
    homer_simpson.putBox(53, 60, 21, 47, 11, 17); // Mao oca
    homer_simpson.putBox(9, 18, 20, 48, 10, 18); // Mao esquerda 
    homer_simpson.putBox(10, 17, 21, 47, 11, 17); // Mao oca

    homer_simpson.writeOFF("../homer_simpson.off");

}
