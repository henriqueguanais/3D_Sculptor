#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H
#include "sculptor.h"

class GeometricFigure 
{
    protected:
        int x0, y0, z0;
        float r, g, b, a;

    public:
        /**
         * @brief Construct a new Geometric Figure object
         * 
         */
        GeometricFigure();

        /**
         * @brief Destroy the Geometric Figure object
         * 
         */
        virtual ~GeometricFigure();

        /**
         * @brief Função draw
         * 
         * @param t 
         */
        virtual void draw(Sculptor &t) = 0;
};

#endif 