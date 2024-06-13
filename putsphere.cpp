#include "putsphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) 
{
    this->x0 = xcenter;
    this->y0 = ycenter;
    this->z0 = zcenter;
    this->radius = radius;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

PutSphere::~PutSphere() {}

void PutSphere::draw(Sculptor &t) 
{
    int x = x0 - radius;
    int x1 = x0 + radius;
    int y = y0 - radius;
    int y1 = y0 + radius;
    int z = z0 - radius;
    int z1 = z0 + radius;
    int ro2 = 0;
    int r2 = radius * radius;

    for (int i = x; i <= x1; i++)
    {
        for (int j = y; j <= y1; j++)
        {
            for (int k = z; k <= z1; k++)
            {
                ro2 = (i - x0) * (i - x0) + (j - y0) * (j - y0) + (k - z0) * (k - z0);
                if (ro2 <= r2)
                {
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}