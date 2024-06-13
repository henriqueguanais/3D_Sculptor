#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "geometricfigure.h"

class PutEllipsoid : public GeometricFigure 
{
    protected:
        int rx;
        int ry;
        int rz;

    public:
        PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
        ~PutEllipsoid();
        virtual void draw(Sculptor &t);
};

#endif  
