#ifndef PUTBOX_H
#define PUTBOX_H
#include "geometricfigure.h"

class PutBox : public GeometricFigure 
{
    protected:
        int x1, y1, z1;

    public:
        PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
        ~PutBox();
        virtual void draw(Sculptor &t);
};

#endif 