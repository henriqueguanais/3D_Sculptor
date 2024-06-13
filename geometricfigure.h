#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H
#include "sculptor.h"

class GeometricFigure 
{
    protected:
        int x0, y0, z0;
        float r, g, b, a;

    public:
        GeometricFigure();
        virtual ~GeometricFigure();
        virtual void draw(Sculptor &t) = 0;
};

#endif 