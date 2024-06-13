#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "geometricfigure.h"

class CutSphere : public GeometricFigure 
{
    protected:
        int radius;

    public:
        CutSphere(int xcenter, int ycenter, int zcenter, int radius);
        ~CutSphere();
        virtual void draw(Sculptor &t);
};

#endif  