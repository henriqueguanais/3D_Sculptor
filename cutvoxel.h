#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "geometricfigure.h"


class CutVoxel : public GeometricFigure 
{
    public:
        CutVoxel(int x, int y, int z);
        ~CutVoxel();
        virtual void draw(Sculptor &t);
};

#endif 