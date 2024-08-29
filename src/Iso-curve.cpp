#include "MarchingCubeTables.h"

iso_cls isoSurface;

iso_cls::iso_cls()
{
}
iso_cls::~iso_cls()
{
}

void iso_cls::create_color_map()
{
    // int colorSize = 64;
    // ColorMap = (glm::fvec3*)malloc(sizeof(glm::fvec3) * colorSize);
    for (int i = 0; i < 10; i++)
    {
        ColorMap[i].r = 0.1f * (i % 10);
        ColorMap[i].g = 0.0f;
        ColorMap[i].b = 0.1f * (i % 10);
    }
    ColorMap[10].r = 1.0f, ColorMap[10].g = 0.0f, ColorMap[10].b = 1.0f;
    for (int i = 11; i < 20; i++)
    {
        ColorMap[i].r = 1.0f - 0.1 * (i % 10);
        ColorMap[i].g = 0.0f;
        ColorMap[i].b = 1.0f;
    }
    ColorMap[20].r = 0.0f, ColorMap[20].g = 0.0f, ColorMap[20].b = 1.0f;
    for (int i = 21; i < 30; i++)
    {
        ColorMap[i].r = 0.0f;
        ColorMap[i].g = 0.1 * (i % 10);
        ColorMap[i].b = 1.0f;
    }
    ColorMap[30].r = 0.0f, ColorMap[30].g = 1.0f, ColorMap[30].b = 1.0f;
    for (int i = 31; i < 40; i++)
    {
        ColorMap[i].r = 0.0f;
        ColorMap[i].g = 1.0f;
        ColorMap[i].b = 1.0f - 0.1f * (i % 10);
    }
    ColorMap[40].r = 0.0f, ColorMap[40].g = 1.0f, ColorMap[40].b = 0.0f;
    for (int i = 41; i < 50; i++)
    {
        ColorMap[i].r = 0.1f * (i % 10);
        ColorMap[i].g = 1.0f;
        ColorMap[i].b = 0.0f;
    }
    ColorMap[50].r = 1.0f, ColorMap[50].g = 1.0f, ColorMap[50].b = 0.0f;
    for (int i = 51; i < 60; i++)
    {
        ColorMap[i].r = 1.0f;
        ColorMap[i].g = 1.0f - 0.1 * (i % 10);
        ColorMap[i].b = 0.0f;
    }
    ColorMap[60].r = 1.0f, ColorMap[60].g = 0.0f, ColorMap[60].b = 0.0f;
    for (int i = 61; i < 65; i++)
    {
        ColorMap[i].r = 1.0f;
        ColorMap[i].g = 0.1 * (i % 4);
        ColorMap[i].b = 0.1 * (i % 4);
    }
    // for (int i = 0; i < 64; i++)
    // {
    //     ColorMap[i].r = 0.0f;
    //     ColorMap[i].g = 0.0f;
    //     ColorMap[i].b = 0.0f;
    // }
    // for (int i = 0; i < 11; i++)
    // {
    //     ColorMap[i].r = 1.0f;
    //     ColorMap[i].g = 0.1f * (i % 11);
    //     ColorMap[i].b = 0.0f;
    // }
    // for (int i = 11; i < 20; i++)
    // {
    //     ColorMap[i].r = 1.0f - 0.1 * (i % 10);
    //     ColorMap[i].g = 1.0f;
    //     ColorMap[i].b = 0.0f;
    // }
    // ColorMap[20].r = 0.0f, ColorMap[20].g = 1.0f, ColorMap[20].b = 0.0f;
    // for (int i = 21; i < 30; i++)
    // {
    //     ColorMap[i].r = 0.0f;
    //     ColorMap[i].g = 1.0f;
    //     ColorMap[i].b = 0.1f * (i % 10);
    // }
    // ColorMap[30].r = 0.0f, ColorMap[30].g = 1.0f, ColorMap[30].b = 1.0f;
    // for (int i = 31; i < 40; i++)
    // {
    //     ColorMap[i].r = 0.0f;
    //     ColorMap[i].g = 1.0 - 0.1f * (i % 10);
    //     ColorMap[i].b = 1.0f;
    // }
    // ColorMap[40].r = 0.0f, ColorMap[40].g = 0.0f, ColorMap[40].b = 1.0f;
    // for (int i = 41; i < 50; i++)
    // {
    //     ColorMap[i].r = 0.1f * (i % 10);
    //     ColorMap[i].g = 0.0f;
    //     ColorMap[i].b = 1.0f;
    // }
    // ColorMap[50].r = 1.0f, ColorMap[50].g = 0.0f, ColorMap[50].b = 1.0f;
    // for (int i = 51; i < 60; i++)
    // {
    //     ColorMap[i].r = 1.0f;
    //     ColorMap[i].g = 0.0f;
    //     ColorMap[i].b = 1.0 - 0.1f * (i % 10);
    // }
    // ColorMap[60].r = 1.0f, ColorMap[60].g = 0.0f, ColorMap[60].b = 0.0f;
    // for (int i = 61; i < 65; i++)
    // {
    //     ColorMap[i].r = 1.0f;
    //     ColorMap[i].g = 0.1f * (i % 4);
    //     ColorMap[i].b = 0.0f;
    // }
    // std::cout << "Color Map: ";
    // for(int i = 0; i < 64; i++)
    // {
    //     std::cout << "(" << ColorMap[i].r << ", " << ColorMap[i].g << ", " << ColorMap[i].b << ") ";
    // }
}

void iso_cls::delete_color_map()
{
    free(ColorMap);
}

void iso_cls::Polygonise(int isolevel)
{
    int ntriang;
    // int isolevel = 2;
    int cubeindex = 0, index = 0;

    int edgeTable[16] = {0x0, 0x9, 0x3, 0xa, 0x6, 0x0, 0x5, 0xc, 0xc, 0x5, 0x0, 0x6, 0xa, 0x3, 0x9, 0x0};

    // for(int i = 0; i < 16; i++)
    // {
    //     std::cout << edgeTable[i] << " ";     
    // }
    // std::cout << std::endl;

    background.curve.clear();
    for (int j = 0; j < voxelmodel.max.z - 1; j++)
    {
        for (int k = 0; k < voxelmodel.max.x - 1; k++)
        {
            cubeindex = 0, index = 0;
            if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0000
                cubeindex = 0;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0001
                cubeindex = 1;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0010
                cubeindex = 2;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0011
                cubeindex = 3;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0100
                cubeindex = 4;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0101
                cubeindex = 5;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0110
                cubeindex = 6;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] >= isolevel) // 0111
                cubeindex = 7;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1000
                cubeindex = 8;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1001
                cubeindex = 9;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1010
                cubeindex = 10;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1011
                cubeindex = 11;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1100
                cubeindex = 12;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] >= isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1101
                cubeindex = 13;
            else if (voxelmodel.VoxelData[0][j][k] >= isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1110
                cubeindex = 14;
            else if (voxelmodel.VoxelData[0][j][k] < isolevel && voxelmodel.VoxelData[0][j][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k + 1] < isolevel && voxelmodel.VoxelData[0][j + 1][k] < isolevel) // 1111
                cubeindex = 15;

            glm::vec3 vertlist[4];
            // Cube is entirely in/out of the surface
            if (edgeTable[cubeindex] == 0)
                continue;
                if (edgeTable[cubeindex] & 1)
                {
                    vertlist[index] = VertexInterp(isolevel, glm::vec3(k, 0, j), glm::vec3(k + 1, 0, j), voxelmodel.VoxelData[0][j][k], voxelmodel.VoxelData[0][j][k + 1]);
                    index++;
                }
                if (edgeTable[cubeindex] & 2)
                {
                    vertlist[index] = VertexInterp(isolevel, glm::vec3(k + 1, 0, j), glm::vec3(k + 1, 0, j + 1), voxelmodel.VoxelData[0][j][k + 1], voxelmodel.VoxelData[0][j + 1][k + 1]);
                    index++;
                }
                if (edgeTable[cubeindex] & 4)
                {
                    vertlist[index] = VertexInterp(isolevel, glm::vec3(k + 1, 0, j + 1), glm::vec3(k, 0, j + 1), voxelmodel.VoxelData[0][j + 1][k + 1], voxelmodel.VoxelData[0][j + 1][k]);
                    index++;
                }
                if (edgeTable[cubeindex] & 8)
                {
                    vertlist[index] = VertexInterp(isolevel, glm::vec3(k, 0, j + 1), glm::vec3(k, 0, j), voxelmodel.VoxelData[0][j + 1][k], voxelmodel.VoxelData[0][j][k]);
                    index++;
                }
                for (int i = 0; i < index; i++)
                {
                    // std::cout << "(" << vertlist[i].z << ", " << vertlist[i].x << ")" << " ";
                    background.curve.push_back(Vertex{{vertlist[i].x, 0.0f, vertlist[i].z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {ColorMap[isolevel].r, ColorMap[isolevel].g, ColorMap[isolevel].b}});
                }
        }
    }
}

glm::vec3 iso_cls::VertexInterp(int isolevel, glm::vec3 p1, glm::vec3 p2, double valp1, double valp2)
{
    double mu;
    glm::vec3 p;

    if (abs(isolevel - valp1) < 0.00001)
        return (p1);
    if (abs(isolevel - valp2) < 0.00001)
        return (p2);
    if (abs(valp1 - valp2) < 0.00001)
        return (p1);
    mu = (isolevel - valp1) / (valp2 - valp1);

    p.x = p1.x + mu * (p2.x - p1.x);
    p.y = p1.y + mu * (p2.y - p1.y);
    p.z = p1.z + mu * (p2.z - p1.z);

    return (p);
}