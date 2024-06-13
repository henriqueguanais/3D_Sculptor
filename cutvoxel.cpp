#include "cutvoxel.h"

CutVoxel::CutVoxel(int x, int y, int z) 
{
    this->x0 = x;
    this->y0 = y;
    this->z0 = z;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

CutVoxel::~CutVoxel() {}

void CutVoxel::draw(Sculptor &t)
{ 
    t.putVoxel(x0, y0, z0); 
}