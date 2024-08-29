#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Vertex.h"
#include "model.h"
#include "DrawModel.h"
#include "Object.h"

#include <vector>
#include <iostream>

struct Background {
    std::vector<Vertex> voxel;
    std::vector<Vertex> curve;
};

void createBackground();
void destroyBackground();
void PointsRenewBackground();
void LinesRenewBackground(int xmin, int xmax);
void PlanesRenewBackground(int zmin, int zmax, int xmin, int xmax);
void CubesRenewBackground(int ymin, int ymax, int zmin, int zmax, int xmin, int xmax); // 3D

extern struct Background background;

#endif