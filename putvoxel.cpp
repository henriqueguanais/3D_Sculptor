#include "putvoxel.h"

/**
 * @brief Construct a new Put Voxel:: Put Voxel object
 * 
 * @param x 
 * @param y 
 * @param z 
 * @param r 
 * @param g 
 * @param b 
 * @param a 
 */
PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a) 
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
 * @brief Destroy the Put Voxel:: Put Voxel object
 * 
 */
PutVoxel::~PutVoxel() {}

/**
 * @brief Insere um voxel na matriz
 * 
 * @param t 
 */
void PutVoxel::draw(Sculptor &t) 
{
    t.setColor(r, g, b, a);
    t.putVoxel(x0, y0, z0);
}