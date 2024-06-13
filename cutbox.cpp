#include "cutbox.h"

/**
 * @brief Construct a new Cut Box:: Cut Box object
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param z0 
 * @param z1 
 */
CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) 
{
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;
}

/**
 * @brief Destroy the Cut Box:: Cut Box object
 * 
 */
CutBox::~CutBox() {}

/**
 * @brief Retira uma caixa sólida na matriz
 * 
 * @param t 
 */
void CutBox::draw(Sculptor &t) 
{
    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                t.cutVoxel(i, j, k);
            }
        }
    }
}