#include <iostream>
#include <fstream>
#include "sculptor.h"

/**
 * @brief Construct a new Sculptor:: Sculptor object
 * 
 * @param _nx 
 * @param _ny 
 * @param _nz 
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    if (nx <= 0 or ny <= 0 or nz <= 0)
    {
        throw std::invalid_argument("As dimensões fornecidas para o construtor de Sculptor são inválidas. Certifique-se de que nx, ny e nz sejam maiores que zero.");
    }

    v = new Voxel **[nx];
    v[0] = new Voxel *[nx * ny];
    v[0][0] = new Voxel[nx * ny * nz];

    for (int i = 0; i < nx; i++)
    {
        v[i] = v[0] + i * ny;

        for (int j = 0; j < ny; j++)
        {
            v[i][j] = v[0][0] + (i * ny + j) * nz;
        }
    }
}

/**
 * @brief Destroy the Sculptor:: Sculptor object
 * 
 */
Sculptor::~Sculptor()
{
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

/**
 * @brief Define a cor (r, g, b) e a transparência 
 * 
 * @param r 
 * @param g 
 * @param b 
 * @param a 
 */
void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/**
 * @brief Cria um único Voxel dentro da matriz
 * 
 * @param x 
 * @param y 
 * @param z 
 */
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

/**
 * @brief Retira um único Voxel da matriz
 * 
 * @param x 
 * @param y 
 * @param z 
 */
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].show = false;
}

/**
 * @brief Cria uma caixa sólida na matriz
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param z0 
 * @param z1 
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                v[i][j][k].show = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

/**
 * @brief Retira uma caixa sólida da matriz
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param z0 
 * @param z1 
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                v[i][j][k].show = false;
            }
        }
    }
}

/**
 * @brief Cria uma esfera sólida na matriz
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param radius 
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int x0 = xcenter - radius;
    int x1 = xcenter + radius;
    int y0 = ycenter - radius;
    int y1 = ycenter + radius;
    int z0 = zcenter - radius;
    int z1 = zcenter + radius;
    int ro2 = 0;
    int r2 = radius * radius;

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                ro2 = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);
                if (ro2 <= r2)
                {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

/**
 * @brief Retira uma esfera sólida da matriz
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param radius 
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int x0 = xcenter - radius;
    int x1 = xcenter + radius;
    int y0 = ycenter - radius;
    int y1 = ycenter + radius;
    int z0 = zcenter - radius;
    int z1 = zcenter + radius;
    int ro2 = 0;
    int r2 = radius * radius;

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                ro2 = (i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter);
                if (ro2 <= r2)
                {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

/**
 * @brief Cria um elipsóide sólido na matriz
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param rx 
 * @param ry 
 * @param rz 
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = zcenter + rz;
    double r;

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                r = ((i - xcenter) * (i - xcenter) / (rx * rx)) + ((j - ycenter) * (j - ycenter) / (ry * ry)) + ((k - zcenter) * (k - zcenter) / (rz * rz));
                if (r <= 1)
                {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

/**
 * @brief Retira um elipsóide sólido da matriz
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param rx 
 * @param ry 
 * @param rz 
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x0 = xcenter - rx;
    int x1 = xcenter + rx;
    int y0 = ycenter - ry;
    int y1 = ycenter + ry;
    int z0 = zcenter - rz;
    int z1 = zcenter + rz;
    double r;

    for (int i = x0; i <= x1; i++)
    {
        for (int j = y0; j <= y1; j++)
        {
            for (int k = z0; k <= z1; k++)
            {
                r = ((i - xcenter) * (i - xcenter) / (rx * rx)) + ((j - ycenter) * (j - ycenter) / (ry * ry)) + ((k - zcenter) * (k - zcenter) / (rz * rz));
                if (r <= 1)
                {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

/**
 * @brief Cria um arquivo no formato OFF
 * 
 * @param filename 
 */
void Sculptor::writeOFF(const char *filename)
{
    std::ofstream fout;

    int numVoxels = 0;
    int f = 0;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show == true)
                {
                    numVoxels++;
                }
            }
        }
    }

    fout.open(filename);

    fout << "OFF\n";
    fout << 8 * numVoxels << " " << 6 * numVoxels << " " << 0 << "\n";
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show)
                {
                    fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                    fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                }
            }
        }
    }

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].show)
                {
                    fout << 4 << " " << 0 + f << " " << 3 + f << " " << 2 + f << " " << 1 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << 4 << " " << 4 + f << " " << 5 + f << " " << 6 + f << " " << 7 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << 4 << " " << 0 + f << " " << 1 + f << " " << 5 + f << " " << 4 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << 4 << " " << 0 + f << " " << 4 + f << " " << 7 + f << " " << 3 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << 4 << " " << 3 + f << " " << 7 + f << " " << 6 + f << " " << 2 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << 4 << " " << 1 + f << " " << 2 + f << " " << 6 + f << " " << 5 + f << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    f += 8;
                }
            }
        }
    }

    fout.close();
}