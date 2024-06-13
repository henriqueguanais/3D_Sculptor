#include "cutvoxel.h"

/**
 * @brief Construct a new Cut Voxel:: Cut Voxel object
 * 
 * @param x 
 * @param y 
 * @param z 
 */
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

/**
 * @brief Destroy the Cut Voxel:: Cut Voxel object
 * 
 */
CutVoxel::~CutVoxel() {}

/**
 * @brief Retira um voxel da matriz
 * 
 * @param t 
 */
void CutVoxel::draw(Sculptor &t)
{ 
    t.putVoxel(x0, y0, z0); 
}