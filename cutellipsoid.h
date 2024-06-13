#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "geometricfigure.h"

class CutEllipsoid : public GeometricFigure 
{
    protected:
        int rx;
        int ry;
        int rz;

    public:
        CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        ~CutEllipsoid();
        virtual void draw(Sculptor &t);
};

#endif 