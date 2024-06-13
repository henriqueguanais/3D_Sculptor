#ifndef READTXT_H
#define READTXT_H
#include <vector>
#include "geometricfigure.h"

class ReadTXT 
{
    private:
        int nx, ny, nz;
        std::vector<GeometricFigure*> vetor;
        std::vector<GeometricFigure*>::iterator it;

    public:
        ReadTXT(const char* filename);  
        ~ReadTXT();                    
        void draw(Sculptor& t);         
                                   
        int getX();                    
        int getY();                     
        int getZ();                     
};

#endif