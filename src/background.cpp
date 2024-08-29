#include "MarchingCubeTables.h"
#include "background.h"

Background background = {};

void createBackground()
{
    Node *DoneHead = voxelmodel.DoneList;
    Node *CloseHead = voxelmodel.CloseList;
    Node *FarHead = voxelmodel.FarList;

    while (DoneHead != NULL)
    {
        int z = DoneHead->pos.z;
        int y = DoneHead->pos.y;
        int x = DoneHead->pos.x;
        float color_r = 0.1;

        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});

        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});

        DoneHead = DoneHead->next;
    }

    while (CloseHead != NULL)
    {
        int z = CloseHead->pos.z;
        int y = CloseHead->pos.y;
        int x = CloseHead->pos.x;
        double color_r = 0.5;

        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.5f, 0.5f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.5f, 0.5f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});

        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.5f, 0.5f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.5f, 0.5f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.5f, 0.5f}});

        CloseHead = CloseHead->next;
    }

    while (FarHead != NULL)
    {
        int z = FarHead->pos.z;
        int y = FarHead->pos.y;
        int x = FarHead->pos.x;
        double color_r = 1.0;

        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});

        background.voxel.push_back(Vertex{{1.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f + y, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 1.0f, 1.0f}});

        FarHead = FarHead->next;
    }
}

void PointsRenewBackground()
{
    background.voxel.clear();
    Node *DoneHead = voxelmodel.DoneList;
    Node *CloseHead = voxelmodel.CloseList;
    glm::fvec3 color;
    while (DoneHead != NULL)
    {
        int z = DoneHead->pos.z;
        int x = DoneHead->pos.x;
        int dist = DoneHead->distance;

        for (int i = 0; i < 64; i++)
        {
            if (dist % 64 == i)
                color = isoSurface.ColorMap[i];
        }

        background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});

        background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});

        DoneHead = DoneHead->next;
    }

    // while (CLOSE_head != NULL)
    // {
    //     int z = CLOSE_head->z;
    //     int x = CLOSE_head->x;
    //     double color_r = (voxelmodel.voxel[z][x] - voxelmodel.min_dist) / (voxelmodel.max_dist - voxelmodel.min_dist);

    //     background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
    //     background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
    //     background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});

    //     background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
    //     background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});
    //     background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {(float)color_r, 0.0f, 0.0f}});

    //     CLOSE_head = CLOSE_head->next;
    // }
}

void LinesRenewBackground(int xmin, int xmax)
{
    background.voxel.clear();
    Node *DoneHead = voxelmodel.DoneList;
    Node *CloseHead = voxelmodel.CloseList;
    while (DoneHead != NULL)
    {
        int z = DoneHead->pos.z;
        int x = DoneHead->pos.x;
        int dist = DoneHead->distance;

        if (x >= xmin && x <= xmax)
        {
            glm::fvec3 color;
            for (int i = 0; i < 64; i++)
            {
                if (dist % 64 == i)
                    color = isoSurface.ColorMap[i];
            }

            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});

            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        }
        DoneHead = DoneHead->next;
    }
}

void PlanesRenewBackground(int zmin, int zmax, int xmin, int xmax)
{
    background.voxel.clear();
    Node *DoneHead = voxelmodel.DoneList;
    Node *CloseHead = voxelmodel.CloseList;
    while (DoneHead != NULL)
    {
        int z = DoneHead->pos.z;
        int x = DoneHead->pos.x;
        int dist = DoneHead->distance;
        if ((z >= zmin && z <= zmax) && (x >= xmin && x <= xmax))
        {
            glm::fvec3 color;
            for (int i = 0; i < 64; i++)
            {
                if (dist % 64 == i)
                    color = isoSurface.ColorMap[i];
            }

            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});

            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        }
        DoneHead = DoneHead->next;
    }
}

void ShowDistance(int assign_dist)
{
    background.voxel.clear();
    Node *DoneHead = voxelmodel.DoneList;
    while (DoneHead != NULL)
    {
        int z = DoneHead->pos.z;
        int x = DoneHead->pos.x;
        int dist = DoneHead->distance;
        if (dist < assign_dist)
        {
            glm::fvec3 color;
            for (int i = 0; i < 64; i++)
            {
                if (dist % 64 == i)
                    color = isoSurface.ColorMap[i];
            }

            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});

            background.voxel.push_back(Vertex{{1.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 1.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
            background.voxel.push_back(Vertex{{0.0f + x, 0.0f, 0.0f + z}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {color.r, color.g, color.b}});
        }
        DoneHead = DoneHead->next;
    }
}

void destroyBackground()
{
    background.voxel.clear();
}