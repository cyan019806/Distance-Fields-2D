#ifndef MODEL_H
#define MODEL_H

#include <time.h>
#include <stdlib.h>
#include <glm/glm.hpp>

#include "background.h"
#include "Object.h"

#define MAX_DIST 1.0e10

typedef struct node
{
    glm::ivec3 pos;
    double distance;
    int state; // DONE: 0, CLOSE: 1, FAR: 2
    int neighbor_num;
    glm::ivec3 *neighbor; // neighbor's pos
    int *neighbor_state;  // neighbor's state
    struct node *next;
} Node;

class model_cls
{
public:
    model_cls();
    ~model_cls();

    // model type
    Node *DoneList;
    Node *CloseList;
    Node *FarList;

    Node *sorted;

    // var
    double ***VoxelData;

    // voxel index range
    glm::ivec3 max = {128, 1, 128};
    // glm::ivec3 max = {2048, 2048, 2048};
    glm::ivec3 min = {0, 0, 0};
    // boundary range (cube)
    glm::ivec3 boundary_min;
    glm::ivec3 boundary_max;
    // center
    glm::ivec3 center;
    // distance
    double min_dist = 9999;
    double max_dist = 0;

    void CreateVoxel();
    void SetVoxelData(int mode);
    void CreateLinkedList();
    Node *StartFastMarching(Node *CloseHead, Node *DoneHead, Node *FarHead);
    void ComputeCLOSE(Node *target, int n);
    void ComputeFAR(Node *target, int n);
    void FreeNode(Node *node);
    void ScanLine();
    void FindMinAndMaxDist();
    Node *DeleteFirstNode(Node *head);

private:
    // function
    void ComputeFirstDistance();
    Node *NodeSorting(Node **head);
    Node *InsectionSort(Node **head, Node *current, Node *precious);
    void sortedInsert(Node *newnode);
    Node *SwapNode(Node *ptr1, Node *ptr2);
    void AddInitNode(Node **head, double value, int y, int z, int x, int current_state, int count);
    void AddNode(Node **head, double value, int y, int z, int x, int current_state, int *neighbor_state, int count);
    Node *DeleteNode(Node *current);
    Node *GetCLOSE(Node *CloseList);
    void GetInitNeighborState(Node *Type);
    double Compute(Node *current, Node *target, int index);
    glm::ivec3 SetCoefficient(int last, int next, double last_dist, double next_dist);
    glm::dvec3 GetCoefficient(glm::ivec3 Coef, double u_last, double u_next);

    glm::ivec3 COEF_LAST = {-1.0, 1.0, 0.0};
    glm::ivec3 COEF_NEXT = {0.0, -1.0, 1.0};
    glm::ivec3 COEF_ERROR = {0.0, 0.0, 0.0};
};

extern model_cls voxelmodel;

#endif