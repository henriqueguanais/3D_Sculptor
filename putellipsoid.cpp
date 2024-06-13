#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a) 
{
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutEllipsoid::~PutEllipsoid() {}

void PutEllipsoid::draw(Sculptor &t) 
{
    int x = x0 - rx;
    int x1 = x0 + rx;
    int y = y0 - ry;
    int y1 = y0 + ry;
    int z = z0 - rz;
    int z1 = z0 + rz;
    double r;

    for (int i = x; i <= x1; i++)
    {
        for (int j = y; j <= y1; j++)
        {
            for (int k = z; k <= z1; k++)
            {
                r = ((i - x0) * (i - x0) / (rx * rx)) + ((j - y0) * (j - y0) / (ry * ry)) + ((k - z0) * (k - z0) / (rz * rz));
                if (r <= 1)
                {
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}