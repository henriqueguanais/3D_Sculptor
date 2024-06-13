#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "geometricfigure.h"

class PutSphere : public GeometricFigure 
{
    private:
        int radius;

    public:
        PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
        ~PutSphere();
        virtual void draw(Sculptor &t);
};

#endif 