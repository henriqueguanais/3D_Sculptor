#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "geometricfigure.h"

class PutVoxel : public GeometricFigure 
{
    public:
        PutVoxel(int x, int y, int z, float r, float g, float b, float a); 
        ~PutVoxel();                                                       
        virtual void draw(Sculptor &t);                                    
};

#endif 