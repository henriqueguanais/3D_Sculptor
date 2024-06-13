#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) 
{
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

CutEllipsoid::~CutEllipsoid() {}

void CutEllipsoid::draw(Sculptor &t) 
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
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}