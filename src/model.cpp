#include <model.h>

#include <iostream>

model_cls voxelmodel;

model_cls::model_cls()
{
}

model_cls::~model_cls()
{
    for (int y = 0; y < max.y; y++)
    {
        for (int z = 0; z < max.z; z++)
        {
            free(VoxelData[y][z]);
        }
        free(VoxelData[y]);
    }
    free(VoxelData);
}

void model_cls::CreateVoxel()
{
    VoxelData = (double ***)(malloc(sizeof(double **) * max.y));
    for (int y = 0; y < max.y; y++)
    {
        VoxelData[y] = (double **)(malloc(sizeof(double *) * max.z));
        for (int z = 0; z < max.z; z++)
        {
            VoxelData[y][z] = (double *)(malloc(sizeof(double) * max.x));
            for (int x = 0; x < max.x; x++)
            {
                VoxelData[y][z][x] = 0;
            }
        }
    }

    // center point
    center.x = (max.x + min.x) / 2;
    center.y = (max.y + min.y) / 2;
    center.z = (max.z + min.z) / 2;
}

// set which voxel are DONE (model)
void model_cls::SetVoxelData(int mode)
{
    // 點 model
    if (mode == 0)
    {
        for (int y = 0; y < max.y; y++)
        {
            for (int z = 0; z < max.z; z++)
            {
                for (int x = 0; x < max.x; x++)
                {
                    if (z == 64 && x == 64)
                    {
                        // model: DONE
                        VoxelData[y][z][x] = 0;
                    }
                    else // CLOSE FAR
                    {
                        VoxelData[y][z][x] = MAX_DIST;
                    }
                }
            }
        }
    }
    // 1字型 model
    if (mode == 1)
    {
        for (int y = 0; y < max.y; y++)
        {
            for (int z = 0; z < max.z; z++)
            {
                for (int x = 0; x < max.x; x++)
                {
                    if ((z == 48 || z == 49 || z == 50 || z == 51 || z == 52 || z == 53 || z == 54 || z == 55 || z == 56 || z == 57 || z == 58 || z == 59 || z == 60 || z == 61 || z == 62 || z == 63 || z == 64 || z == 65 || z == 66 || z == 67 || z == 68 || z == 69 || z == 70 || z == 71 || z == 72 || z == 73 || z == 74 || z == 75 || z == 76 || z == 77 || z == 78 || z == 79 || z == 80) && x == 64) // DONE
                    {
                        VoxelData[y][z][x] = 0;
                    }
                    else // CLOSE FAR
                    {
                        VoxelData[y][z][x] = MAX_DIST;
                    }
                }
            }
        }
    }
    // V字型 model
    if (mode == 2)
    {
        for (int y = 0; y < max.y; y++)
        {
            for (int z = 0; z < max.z; z++)
            {
                for (int x = 0; x < max.x; x++)
                {
                    // DONE
                    if ((z == 46 || z == 47) && (x == 47 || x == 81))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 48 || z == 49) && (x == 48 || x == 80))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 50 || z == 51) && (x == 49 || x == 79))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 52 || z == 53) && (x == 50 || x == 78))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 54 || z == 55) && (x == 51 || x == 77))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 56 || z == 57) && (x == 52 || x == 76))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 58 || z == 59) && (x == 53 || x == 75))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 60 || z == 61) && (x == 54 || x == 74))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 62 || z == 63) && (x == 55 || x == 73))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    if ((z == 64 || z == 65) && (x == 56 || x == 72))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 66 || z == 67) && (x == 57 || x == 71))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 68 || z == 69) && (x == 58 || x == 70))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 70 || z == 71) && (x == 59 || x == 69))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 72 || z == 73) && (x == 60 || x == 68))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 74 || z == 75) && (x == 61 || x == 67))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 76 || z == 77) && (x == 62 || x == 66))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 78 || z == 79) && (x == 63 || x == 65))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else if ((z == 80 || z == 81) && (x == 64))
                    {
                        VoxelData[0][z][x] = 0;
                    }
                    else
                    {
                        VoxelData[0][z][x] = MAX_DIST;
                    }
                }
            }
        }
    }
    if (mode == 3)
    {
        for (int z = 0; z < max.z; z++)
        {
            for (int x = 0; x < max.x; x++)
            {
                // DONE
                if (z == 3 && (x == 3 || x == 4 || x == 5 || x == 6 || x == 8 || x == 9 || x == 10 || x == 11))
                {
                    VoxelData[0][z][x] = 0;
                }
                else if ((z == 4 || z == 5 || z == 6) && (x == 3 || x == 6 || x == 8 || x == 11))
                {
                    VoxelData[0][z][x] = 0;
                }
                else if (z == 7 && (x == 3 || x == 6 || x == 7 || x == 8 || x == 11))
                {
                    VoxelData[0][z][x] = 0;
                }
                else if ((z == 8 || z == 9 || z == 10 || z == 11) && (x == 3 || x == 11))
                {
                    VoxelData[0][z][x] = 0;
                }
                else if (z == 12 && (x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8 || x == 9 || x == 10 || x == 11))
                {
                    VoxelData[0][z][x] = 0;
                }
                else
                {
                    VoxelData[0][z][x] = MAX_DIST;
                }
            }
        }
    }

    /*
    // 1字型 model
    if (mode == 1)
    {
        for (int y = 0; y < max.y; y++)
        {
            for (int z = 0; z < max.z; z++)
            {
                for (int x = 0; x < max.x; x++)
                {
                    if ((z == 48 || z == 49 || z == 50 || z == 51 || z == 52 || z == 53 || z == 54 || z == 55 || z == 56 || z == 57 || z == 58 || z == 59 || z == 60 || z == 61 || z == 62 || z == 63 || z == 64 || z == 65 || z == 66 || z == 67 || z == 68 || z == 69 || z == 70 || z == 71 || z == 72 || z == 73 || z == 74 || z == 75 || z == 76 || z == 77 || z == 78 || z == 79 || z == 80) && x == 64) // DONE
                    {
                        VoxelData[y][z][x] = 0;
                    }
                    else // CLOSE FAR
                    {
                        VoxelData[y][z][x] = MAX_DIST;
                    }
                }
            }
        }
    }
    */
}

void model_cls::ComputeFirstDistance()
{
    for (int y = min.y; y < max.y; y++)
    {
        for (int z = min.z; z < max.z; z++)
        {
            for (int x = min.x; x < max.x; x++)
            {
                if (VoxelData[y][z][x] == 0)
                {
                    // if (y - 1 >= min.y)
                    // {
                    //     if (VoxelData[y - 1][y][x] != 0)
                    //         VoxelData[y][y][x] = 1;
                    // }
                    // if (y + 1 <= max.y)
                    // {
                    //     if (VoxelData[y + 1][y][x] != 0)
                    //         VoxelData[y][y][x] = 1;
                    // }
                    if (z - 1 >= min.z)
                    {
                        if (VoxelData[y][z - 1][x] != 0)
                            VoxelData[y][z - 1][x] = 1;
                    }
                    if (z + 1 <= max.z)
                    {
                        if (VoxelData[y][z + 1][x] != 0)
                            VoxelData[y][z + 1][x] = 1;
                    }
                    if (x - 1 >= min.x)
                    {
                        if (VoxelData[y][z][x - 1] != 0)
                            VoxelData[y][z][x - 1] = 1;
                    }
                    if (x + 1 <= max.x)
                    {
                        if (VoxelData[y][z][x + 1] != 0)
                            VoxelData[y][z][x + 1] = 1;
                    }
                }
            }
        }
    }
    // for (int z = 0; z < max.z; z++)
    // {
    //     for (int y = 0; y < max.y; y++)
    //     {
    //         for (int x = 0; x < max.x; x++)
    //         {
    //             std::cout << VoxelData[z][y][x] << " ";
    //         }
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
}

void model_cls::GetInitNeighborState(Node *Type)
{
    Node *head = Type;

    while (head != NULL)
    {
        for (int n = 0; n < head->neighbor_num; n++)
        {
            if (VoxelData[head->neighbor[n].y][head->neighbor[n].z][head->neighbor[n].x] == 0) // DONE
            {
                head->neighbor_state[n] = 0;
            }
            else if (VoxelData[head->neighbor[n].y][head->neighbor[n].z][head->neighbor[n].x] == MAX_DIST) // FAR
            {
                head->neighbor_state[n] = 2;
            }
            else // CLOSE
            {
                head->neighbor_state[n] = 1;
            }
        }
        head = head->next;
    }
}

void model_cls::AddInitNode(Node **head, double value, int y, int z, int x, int current_state, int count)
{
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->neighbor = (glm::ivec3 *)(malloc(sizeof(glm::ivec3) * count));
    new_node->neighbor_state = (int *)(malloc(sizeof(int) * count));
    new_node->distance = value;
    new_node->pos.z = z;
    new_node->pos.y = y;
    new_node->pos.x = x;
    new_node->state = current_state;
    new_node->neighbor_num = count;
    new_node->next = NULL;

    int c = 0;
    if (z - 1 >= min.z)
    {
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].z = z - 1;
        new_node->neighbor[c].x = x;
        c++;
    }
    if (z + 1 < max.z)
    {
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].z = z + 1;
        new_node->neighbor[c].x = x;
        c++;
    }
    if (x - 1 >= min.x)
    {
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].z = z;
        new_node->neighbor[c].x = x - 1;
        c++;
    }
    if (x + 1 < max.x)
    {
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].z = z;
        new_node->neighbor[c].x = x + 1;
        c++;
    }

    if (*head == NULL) // first node
    {
        *head = new_node;
        return;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        return;
    }
}

void model_cls::AddNode(Node **head, double value, int y, int z, int x, int current_state, int *neighbor_state, int count)
{
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->neighbor = (glm::ivec3 *)(malloc(sizeof(glm::ivec3) * count)); // 每個 Node 鄰居的 index
    new_node->neighbor_state = (int *)(malloc(sizeof(int) * count));         // 每個 Node 鄰居的 state
    new_node->distance = value;
    new_node->pos.y = y;
    new_node->pos.z = z;
    new_node->pos.x = x;
    new_node->state = current_state;
    new_node->neighbor_num = count;
    new_node->next = NULL;

    int c = 0;
    // if (y - 1 >= min.y)
    // {
    //     new_node->neighbor[c].z = z;
    //     new_node->neighbor[c].y = y - 1;
    //     new_node->neighbor[c].x = x;
    //     new_node->neighbor_state[c] = neighbor_state[c];
    //     c++;
    // }
    // if (y + 1 < max.y)
    // {
    //     new_node->neighbor[c].z = z;
    //     new_node->neighbor[c].y = y + 1;
    //     new_node->neighbor[c].x = x;
    //     new_node->neighbor_state[c] = neighbor_state[c];
    //     c++;
    // }
    if (z - 1 >= min.z)
    {
        new_node->neighbor[c].z = z - 1;
        new_node->neighbor[c].x = x;
        new_node->neighbor_state[c] = neighbor_state[c];
        c++;
    }
    if (z + 1 < max.z)
    {
        new_node->neighbor[c].z = z + 1;
        new_node->neighbor[c].x = x;
        new_node->neighbor_state[c] = neighbor_state[c];
        c++;
    }
    if (x - 1 >= min.x)
    {
        new_node->neighbor[c].z = z;
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].x = x - 1;
        new_node->neighbor_state[c] = neighbor_state[c];
        c++;
    }
    if (x + 1 < max.x)
    {
        new_node->neighbor[c].z = z;
        new_node->neighbor[c].y = y;
        new_node->neighbor[c].x = x + 1;
        new_node->neighbor_state[c] = neighbor_state[c];
        c++;
    }

    if (*head == NULL) // first node
    {
        *head = new_node;
        return;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        return;
    }
}

Node *model_cls::DeleteFirstNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *tmp = head;
    head = head->next;
    CloseList = head;
    delete tmp;

    return head;
}

Node *model_cls::DeleteNode(Node *current)
{
    if (current == NULL || current->next == NULL)
        return NULL;
    current->pos.z = current->next->pos.z;
    current->pos.y = current->next->pos.y;
    current->pos.x = current->next->pos.x;
    current->distance = current->next->distance;
    current->neighbor_num = current->next->neighbor_num;
    for (int n = 0; n < current->neighbor_num; n++)
    {
        current->neighbor[n] = current->next->neighbor[n];
        current->neighbor_state[n] = current->next->neighbor_state[n];
    }
    current->next = current->next->next;

    return current;
}

Node *model_cls::GetCLOSE(Node *CLOSE)
{
    Node *head = CLOSE;
    return head;
}

glm::ivec3 model_cls::SetCoefficient(int last_state, int next_state, double last_dist, double next_dist)
{
    if (last_state == 0 && next_state != 0) // DONE & !=DONE
    {
        return COEF_LAST;
    }
    else if (last_state != 0 && next_state == 0) // !=DONE & DONE
    {
        return COEF_NEXT;
    }
    else if (last_state == 0 && next_state == 0) // both DONE
    {
        if (last_dist <= next_dist)
            return COEF_LAST;
        else
            return COEF_NEXT;
    }
    else
        return COEF_ERROR;
}

glm::dvec3 model_cls::GetCoefficient(glm::ivec3 Coef, double u_last, double u_next)
{
    glm::dvec3 coef;
    coef.x = Coef.y * Coef.y;
    coef.y = 2 * (Coef.x * Coef.y * u_last + Coef.y * Coef.z * u_next);
    coef.z = ((Coef.x * u_last) * (Coef.x * u_last)) + ((Coef.z * u_next) * (Coef.z * u_next));

    return coef;
}

double model_cls::Compute(Node *current, Node *target, int index)
{
    int num_x = 0, num_y = 0, num_z = 0;
    for (int n = 0; n < current->neighbor_num; n++) // store neighbor's num
    {
        if (current->pos.x == current->neighbor[n].x)
        {
            num_x++;
        }
        else if (current->pos.z == current->neighbor[n].z)
        {
            num_z++;
        }
    }
    glm::ivec3 CoefX, CoefY, CoefZ;
    glm::dvec3 Coefx, Coefy, Coefz;

    if (num_z == 2 && num_x == 2)
    {
        // Z direction
        CoefZ = SetCoefficient(current->neighbor_state[2], current->neighbor_state[3], VoxelData[0][current->pos.z][current->neighbor[2].x], VoxelData[0][current->pos.z][current->neighbor[3].x]);
        Coefz = GetCoefficient(CoefZ, VoxelData[0][current->pos.z][current->neighbor[2].x], VoxelData[0][current->pos.z][current->neighbor[3].x]);

        // X direction
        CoefX = SetCoefficient(current->neighbor_state[0], current->neighbor_state[1], VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[1].z][current->pos.x]);
        Coefx = GetCoefficient(CoefX, VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[1].z][current->pos.x]);
    }
    else if (num_z == 1 && num_x == 2)
    {
        CoefZ = SetCoefficient(current->neighbor_state[2], current->neighbor_state[2], VoxelData[0][current->pos.z][current->neighbor[2].x], VoxelData[0][current->pos.z][current->neighbor[2].x]);
        Coefz = GetCoefficient(CoefZ, VoxelData[0][current->pos.z][current->neighbor[2].x], VoxelData[0][current->pos.z][current->neighbor[2].x]);

        CoefX = SetCoefficient(current->neighbor_state[0], current->neighbor_state[1], VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[1].z][current->pos.x]);
        Coefx = GetCoefficient(CoefX, VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[1].z][current->pos.x]);
    }
    else if (num_z == 2 && num_x == 1)
    {
        CoefZ = SetCoefficient(current->neighbor_state[1], current->neighbor_state[2], VoxelData[0][current->pos.z][current->neighbor[1].x], VoxelData[0][current->pos.z][current->neighbor[2].x]);
        Coefz = GetCoefficient(CoefZ, VoxelData[0][current->pos.z][current->neighbor[1].x], VoxelData[0][current->pos.z][current->neighbor[2].x]);

        CoefX = SetCoefficient(current->neighbor_state[0], current->neighbor_state[0], VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[0].z][current->pos.x]);
        Coefx = GetCoefficient(CoefX, VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[0].z][current->pos.x]);
    }
    else if (num_z == 1 && num_x == 1)
    {
        CoefZ = SetCoefficient(current->neighbor_state[1], current->neighbor_state[1], VoxelData[0][current->pos.z][current->neighbor[1].x], VoxelData[0][current->pos.z][current->neighbor[1].x]);
        Coefz = GetCoefficient(CoefZ, VoxelData[0][current->pos.z][current->neighbor[1].x], VoxelData[0][current->pos.z][current->neighbor[1].x]);

        CoefX = SetCoefficient(current->neighbor_state[0], current->neighbor_state[0], VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[0].z][current->pos.x]);
        Coefx = GetCoefficient(CoefX, VoxelData[0][current->neighbor[0].z][current->pos.x], VoxelData[0][current->neighbor[0].z][current->pos.x]);
    }

    double a, b, c, u_now;
    a = Coefx.x + Coefz.x;
    b = Coefx.y + Coefz.y;
    c = Coefx.z + Coefz.z - 1.0;

    u_now = ((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a);
    return u_now;
}

void model_cls::ComputeCLOSE(Node *target, int index)
{
    Node *current = target;
    while (current != NULL)
    {
        if (current->pos.x == target->neighbor[index].x && current->pos.z == target->neighbor[index].z)
            break;
        current = current->next;
    }
    int r_index = 0;
    if (index == 0)
        r_index = 1;
    if (index == 1)
        r_index = 0;
    if (index == 2)
        r_index = 3;
    if (index == 3)
        r_index = 2;

    double value = Compute(current, target, r_index);

    if (value < VoxelData[0][target->neighbor[index].z][target->neighbor[index].x]) // new distance smaller than old -> rewnew
    {
        VoxelData[0][target->neighbor[index].z][target->neighbor[index].x] = value;
        Node *head = CloseList;
        Node *precious = CloseList;
        int first = 0;
        while (head != NULL)
        {
            if (head->pos.z == target->neighbor[index].z && head->pos.x == target->neighbor[index].x)
            {
                head->distance = value;
                head->state = 1;
                CloseList= InsectionSort(&CloseList, head, precious);
                break;
            }
            if (first == 0)
                first++;
            else
                precious = precious->next;

            head = head->next;
        }
    }
}

void model_cls::ComputeFAR(Node *target, int index)
{
    Node *current = FarList;
    while (current != NULL)
    {
        if (current->pos.z == target->neighbor[index].z && current->pos.x == target->neighbor[index].x)
            break;
        current = current->next;
    }
    int r_index = 0;
    if (index == 0)
        r_index = 1;
    if (index == 1)
        r_index = 0;
    if (index == 2)
        r_index = 3;
    if (index == 3)
        r_index = 2;

    double value = Compute(current, target, r_index);

    if (value < VoxelData[0][target->neighbor[index].z][target->neighbor[index].x]) // new distance smaller  than old -> need to renew
    {
        VoxelData[0][target->neighbor[index].z][target->neighbor[index].x] = value;
        VoxelData[0][current->pos.z][current->pos.x] = value;
        current->distance = value;
        current->state = 1;
        // add to CLOSE and remove from FAR
        Node *CloseHead = target;
        Node *FarHead = FarList;
        Node *DoneHead = DoneList;
        AddNode(&CloseHead, value, 0, current->pos.z, current->pos.x, current->state, current->neighbor_state, current->neighbor_num);
        while (CloseHead != NULL)
        {
            for (int n = 0; n < CloseHead->neighbor_num; n++)
            {
                if (CloseHead->neighbor[n].z == current->pos.z && CloseHead->neighbor[n].x == current->pos.x)
                {
                    CloseHead->neighbor_state[n] = current->state;
                }
            }
            CloseHead = CloseHead->next;
        }
        while (FarHead != NULL)
        {
            for (int n = 0; n < FarHead->neighbor_num; n++)
            {
                if (FarHead->neighbor[n].z == current->pos.z && FarHead->neighbor[n].x == current->pos.x)
                {
                    FarHead->neighbor_state[n] = current->state;
                }
            }
            FarHead = FarHead->next;
        }
        while (DoneHead != NULL)
        {
            for (int n = 0; n < DoneHead->neighbor_num; n++)
            {
                if (DoneHead->neighbor[n].z == current->pos.z && DoneHead->neighbor[n].x == current->pos.x)
                {
                    DoneHead->neighbor_state[n] = current->state;
                }
            }
            DoneHead = DoneHead->next;
        }
        current = DeleteNode(current);
    }
    else // new distance bigger than old
    {
        Node *DoneHead = DoneList;
        current->state = 0; // state -> 0 and add to DONE
        AddNode(&DoneHead, value, 0, current->pos.z, current->pos.x, current->state, current->neighbor_state, current->neighbor_num);
        Node *CloseHead = target;
        Node *FarHead = FarList;
        while (CloseHead != NULL)
        {
            for (int n = 0; n < CloseHead->neighbor_num; n++)
            {
                if (CloseHead->neighbor[n].z == current->pos.z && CloseHead->neighbor[n].x == current->pos.x)
                {
                    CloseHead->neighbor_state[n] = current->state;
                }
            }
            CloseHead = CloseHead->next;
        }
        while (FarHead != NULL)
        {
            for (int n = 0; n < FarHead->neighbor_num; n++)
            {
                if (FarHead->neighbor[n].z == current->pos.z && FarHead->neighbor[n].x == current->pos.x)
                {
                    FarHead->neighbor_state[n] = current->state;
                }
            }
            FarHead = FarHead->next;
        }
        while (DoneHead != NULL)
        {
            for (int n = 0; n < DoneHead->neighbor_num; n++)
            {
                if (DoneHead->neighbor[n].z == current->pos.z && DoneHead->neighbor[n].x == current->pos.x)
                {
                    DoneHead->neighbor_state[n] = current->state;
                }
            }
            DoneHead = DoneHead->next;
        }
        current = DeleteNode(current);
        current = current->next;
    }
}
// rendering
Node *model_cls::StartFastMarching(Node *CloseHead, Node *DoneHead, Node *FarHead)
{
    // Every time add the Minimum distance to DONE
    Node *target = GetCLOSE(CloseHead);
    target->state = 0;
    // std::cout << "target: " << "(" << target->pos.z << ", " << target->pos.x << ")" << std::endl;
    AddNode(&DoneList, target->distance, target->state, target->pos.z, target->pos.x, target->state, target->neighbor_state, target->neighbor_num);
    Node *CloseHead2 = target;
    Node *DoneHead2 = DoneList;
    Node *FarHead2 = FarList;
    // renew the neighbor's state
    while (CloseHead2 != NULL)
    {
        for (int n = 0; n < CloseHead2->neighbor_num; n++)
        {
            if (CloseHead2->neighbor[n].z == target->pos.z && CloseHead2->neighbor[n].x == target->pos.x)
            {
                CloseHead2->neighbor_state[n] = target->state;
            }
        }
        CloseHead2 = CloseHead2->next;
    }
    while (FarHead2 != NULL)
    {
        for (int n = 0; n < FarHead2->neighbor_num; n++)
        {
            if (FarHead2->neighbor[n].z == target->pos.z && FarHead2->neighbor[n].x == target->pos.x)
            {
                FarHead2->neighbor_state[n] = target->state;
            }
        }
        FarHead2 = FarHead2->next;
    }
    while (DoneHead2 != NULL)
    {
        for (int n = 0; n < DoneHead2->neighbor_num; n++)
        {
            if (DoneHead2->neighbor[n].z == target->pos.z && DoneHead2->neighbor[n].x == target->pos.x)
            {
                DoneHead2->neighbor_state[n] = target->state;
            }
        }
        DoneHead2 = DoneHead2->next;
    }

    for (int n = 0; n < target->neighbor_num; n++)
    {
        if (target->neighbor_state[n] == 1) // CLOSE
        {
            ComputeCLOSE(target, n);
        }
        else if (target->neighbor_state[n] == 2) // FAR
        {
            ComputeFAR(target, n);
        }
    }

    CloseHead = CloseList;
    DoneHead = DoneList;
    FarHead = FarList;

    return target;
}

void model_cls::CreateLinkedList()
{
    ComputeFirstDistance();
    // create linked list
    Node *DoneHead = DoneList, *CloseHead = CloseList, *FarHead = FarList;
    int count = 0;
    for (int y = 0; y < max.y; y++)
    {
        for (int z = 0; z < max.z; z++)
        {
            for (int x = 0; x < max.x; x++)
            {
                if (z != min.z)
                    count++;
                if (z != max.z - 1)
                    count++;
                if (x != min.x)
                    count++;
                if (x != max.x - 1)
                    count++;
                if (VoxelData[y][z][x] == 0) // DONE
                {
                    AddInitNode(&DoneHead, 0, y, z, x, 0, count);
                }
                else if (VoxelData[y][z][x] == 1) // CLOSE
                {
                    AddInitNode(&CloseHead, 1, y, z, x, 1, count);
                }
                else // FAR
                {
                    AddInitNode(&FarHead, MAX_DIST, y, z, x, 2, count);
                }
                count = 0;
            }
        }
    }

    DoneList = DoneHead;
    CloseList = CloseHead;
    FarList = FarHead;

    // store the neighbor's state
    GetInitNeighborState(DoneList);
    GetInitNeighborState(CloseList);
    GetInitNeighborState(FarList);

    DoneList = DoneHead;
    CloseList = CloseHead;
    FarList = FarHead;
}

void model_cls::ScanLine()
{
    Node *DoneHead = DoneList;
    Node *CloseHead = CloseList;
    int first = 0;
    for (int y = min.y; y < max.y; y++)
    {
        for (int z = min.z; z < max.z; z++) // +x方向從 z = min 掃描到 z = max-1
        {
            for (int x = min.x; x < max.x; x++)
            {
                if (VoxelData[z][x] == 0)
                {
                    if (first == 0) // 第一次遇到模型表面
                        first++;
                }
                else
                {
                    if (first == 0)
                        VoxelData[0][z][x] *= -1;
                    else
                    {
                        if (z - 1 > min.z)
                        {
                            if (VoxelData[z - 1][x] < 0)
                            {
                                VoxelData[0][z][x] *= -1;
                            }
                        }
                        else if (x - 1 > min.x)
                        {
                            if (VoxelData[0][z][x - 1] < 0)
                            {
                                VoxelData[0][z][x] *= -1;
                            }
                        }
                    }
                }
            }
        }
    }
    // first = 0;
    // for(int z = max - 1; z > min; z--) // -x方向從 z = max-1 掃描到 z = min
    // {
    //     for(int x = max - 1; x > min; x--)
    //     {
    //         if(VoxelData[z][x] == 0)
    //         {
    //             if(first == 0) // 第一次遇到模型表面
    //                 first++;
    //         }
    //         else
    //         {
    //             if(first == 0)
    //                 VoxelData[z][x] *= -1;
    //             else
    //             {
    //                 if(z+1 < max)
    //                 {
    //                     if(VoxelData[z+1][x] < 0)
    //                     {
    //                         VoxelData[z][x] *= -1;
    //                     }
    //                 }
    //                 else if(x+1 < max)
    //                 {
    //                     if(VoxelData[z][x+1] < 0)
    //                     {
    //                         VoxelData[z][x] *= -1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // for(int z = min.z; z < max.z; z++)
    // {
    //     for(int x = min.x; x < max.x; x++)
    //     {
    //         std::cout << VoxelData[z][x] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

void model_cls::FindMinAndMaxDist()
{
    // for (int y = min.y; y < max.y; y++)
    // {
    for (int z = min.z; z < max.z; z++)
    {
        for (int x = min.x; x < max.x; x++)
        {
            if (VoxelData[0][z][x] < min_dist)
            {
                min_dist = VoxelData[0][z][x];
            }
            if (VoxelData[0][z][x] > max_dist)
            {
                max_dist = VoxelData[0][z][x];
            }
        }
    }
    // }
}

void model_cls::sortedInsert(Node *newnode)
{
    // special case for the head end
    if (sorted == NULL || sorted->distance > newnode->distance)
    {
        newnode->next = sorted;
        sorted = newnode;
    }
    else
    {
        Node *current = sorted;
        // locate the node before the point of insertion
        while (current->next != NULL && current->next->distance <= newnode->distance)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

Node *model_cls::InsectionSort(Node **head, Node *current, Node *precious)
{
    Node *start = *head;
    Node *start_next = start->next;
    Node *current_next = current->next;
    while (start_next != NULL)
    {
        if (current->distance >= start->distance && current->distance < start_next->distance) // 找到要插入的位置且此點不為插入點
        {
            if (current->pos.x == start->pos.x && current->pos.z == start->pos.z)
                break;
            Node *tmp = start_next;
            Node *tmp2 = current_next;
            start->next = current;
            current->next = tmp;
            precious->next = tmp2;
            break;
        }
        start = start->next;
        start_next = start->next;
    }
    return *head;
}

void model_cls::FreeNode(Node *node)
{
    Node *current, *tmp;
    current = node;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
}
/*

void model_cls::StartFastMarching(bool flag)
{

    if (flag == false)
    {
        CLOSE_head = voxelmodel.CLOSE;
        DONE_head = voxelmodel.DONE;
        FAR_head = voxelmodel.FAR;
    }

    // 將 CLOSE 中距離值最小的 voxel 加到 DONE
    std::cout << "Start Fast Marching:" << std::endl;
    Node *target = GetCLOSE(CLOSE_head);
    std::cout << "target: " << "(" << target->z << ", " << target->x << ") " << target->distance << std::endl;
    for (int n = 0; n < target->neighbor_num; n++)
    {
        std::cout << "(" << target->neighbor[n].z << " ," << target->neighbor[n].x << ") " << target->neighbor_state[n] << " ";
    }
    std::cout << std::endl;
    target->state = 0;
    AddNode(&DONE, target->distance, target->z, target->x, target->state, target->neighbor_state, target->neighbor_num);
    Node *CLOSE_head2 = target;
    Node *DONE_head2 = DONE;
    Node *FAR_head2 = FAR;
    while (CLOSE_head2 != NULL)
    {
        for (int n = 0; n < CLOSE_head2->neighbor_num; n++)
        {
            if (CLOSE_head2->neighbor[n].z == target->z && CLOSE_head2->neighbor[n].x == target->x)
            {
                CLOSE_head2->neighbor_state[n] = target->state;
                // std::cout << "(" << CLOSE_head2->z << ", " << CLOSE_head2->x << ") ";
                // std::cout << "(" << CLOSE_head2->neighbor[n].z << ", " << CLOSE_head2->neighbor[n].x << ") " << CLOSE_head2->neighbor_state[n] << " ";
            }
        }
        CLOSE_head2 = CLOSE_head2->next;
    }
    // std::cout << std::endl;
    FAR_head2 = FAR;
    while (FAR_head2 != NULL)
    {
        for (int n = 0; n < FAR_head2->neighbor_num; n++)
        {
            if (FAR_head2->neighbor[n].z == target->z && FAR_head2->neighbor[n].x == target->x)
            {
                FAR_head2->neighbor_state[n] = target->state;
                // std::cout << "(" << FAR_head2->z << ", " << FAR_head2->x << ")" << " ";
                // std::cout << "(" << FAR_head2->neighbor[n].z << ", " << FAR_head2->neighbor[n].x << ") " << FAR_head2->neighbor_state[n] << " ";
            }
        }
        FAR_head2 = FAR_head2->next;
    }
    // std::cout << std::endl;
    DONE_head2 = DONE;
    while (DONE_head2 != NULL)
    {
        for (int n = 0; n < DONE_head2->neighbor_num; n++)
        {
            if (DONE_head2->neighbor[n].z == target->z && DONE_head2->neighbor[n].x == target->x)
            {
                DONE_head2->neighbor_state[n] = target->state;
                // std::cout << DONE_head2->z << ", " << DONE_head2->x;
                // std::cout << "(" << DONE_head2->neighbor[n].z << ", " << DONE_head2->neighbor[n].x << ") " << DONE_head2->neighbor_state[n] << " ";
            }
        }
        DONE_head2 = DONE_head2->next;
    }
    // std::cout << std::endl;
    for (int n = 0; n < target->neighbor_num; n++)
    {
        if (target->neighbor_state[n] == 1) // CLOSE
        {
            ComputeCLOSE(target, n);
        }
        else if (target->neighbor_state[n] == 2) // FAR
        {
            ComputeFAR(target, n);
        }
        // RewnewEveryIteration(Voxel);
        // CLOSE_head = target;
        // DONE_head = DONE;
        // FAR_head = FAR;
        // std::cout << "CLOSE: ";
        // while(CLOSE_head != NULL)
        // {
        //     std::cout << "(" << CLOSE_head->z << ", " << CLOSE_head->x << ") " << CLOSE_head->distance << " ";

        //     CLOSE_head = CLOSE_head->next;
        // }
        // std::cout << std::endl;
        // std::cout << "DONE: ";
        // while(DONE_head != NULL)
        // {
        //     std::cout << "(" << DONE_head->z << ", " << DONE_head->x << ") " << DONE_head->distance << " ";
        //     DONE_head = DONE_head->next;
        // }
        // std::cout << std::endl;
        // std::cout << "FAR: ";
        // while(FAR_head != NULL)
        // {
        //     std::cout << "(" << FAR_head->z << ", " << FAR_head->x << ") " << FAR_head->distance << " ";
        //     FAR_head = FAR_head->next;
        // }
        // std::cout << std::endl;
        // CLOSE_head = CLOSE;
        // DONE_head = DONE;
        // FAR_head = FAR;
    }
    // for(int n = 0; n < target->neighbor_num; n++)
    // {
    //     std::cout << target->neighbor[n].z << ", " << target->neighbor[n].x << " " << target->neighbor_state[n] << " ";
    // }
    CLOSE_head = DeleteFirstNode(target);
}

// set which voxel are DONE (model)
void model_cls::SetVoxelData(int mode)
{
    // 1字型 model
    if (mode == 0)
    {
        for (int z = 0; z < max.z; z++)
        {
            for (int x = 0; x < max.x; x++)
            {
                if ((z == 3 || z == 4 || z == 5 || z == 6 || z == 7 || z == 8 || z == 9 || z == 10 || z == 11 || z == 12) && x == 7) // DONE
                {
                    voxel[z][x] = 0;
                    // boundary x, z
                    if (x > current_xmax)
                        current_xmax = x;
                    if (z > current_zmax)
                        current_zmax = z;
                    if (x < current_xmin)
                        current_xmin = x;
                    if (z < current_zmin)
                        current_zmin = z;
                }
                else // CLOSE FAR
                {
                    voxel[z][x] = 255;
                }
            }
        }
    }

Node *model_cls::NodeSorting(Node **head)
{
    int first = 0;
    // set the random seed
    srand(time(NULL));
    Node *current, *current_next;
    current = *head;
    current_next = current->next;
    while (current_next != NULL)
    {
        if (current->distance > current_next->distance)
        {
            current = SwapNode(current, current_next);
            current_next = current->next;
            if (first == 0)
            {
                *head = current;
            }
        }
        else if (current->distance == current_next->distance) // if distances the same, have a probability to swap order
        {
            double r = (double)rand() / (RAND_MAX + 1.0);
            if (r > 0.5)
            {
                current = SwapNode(current, current_next);
                current_next = current->next;
                if (first == 0)
                {
                    *head = current;
                }
            }
        }
        current = current->next;
        current_next = current->next;
        first++;
    }
    return *head;
}

Node *model_cls::SwapNode(Node *ptr1, Node *ptr2)
{
    double tmp_dist;
    int tmp_x, tmp_y, tmp_z, tmp_state, tmp_num;
    int *tmp_neighbor_state = (int *)(malloc(sizeof(int) * ptr2->neighbor_num));
    glm::ivec3 *tmp_neighbor = (glm::ivec3 *)(malloc(sizeof(glm::ivec3) * ptr2->neighbor_num));

    tmp_dist = ptr2->distance;
    tmp_z = ptr2->pos.z;
    // tmp_y = ptr2->pos.y;
    tmp_x = ptr2->pos.x;
    tmp_state = ptr2->state;
    tmp_num = ptr2->neighbor_num;
    for (int n = 0; n < tmp_num; n++)
    {
        tmp_neighbor[n] = ptr2->neighbor[n];
        tmp_neighbor_state[n] = ptr2->neighbor_state[n];
    }

    ptr2->distance = ptr1->distance;
    ptr2->pos.z = ptr1->pos.z;
    // ptr2->pos.y = ptr1->pos.y;
    ptr2->pos.x = ptr1->pos.x;
    ptr2->state = ptr1->state;
    ptr2->neighbor_num = ptr1->neighbor_num;
    for (int n = 0; n < ptr2->neighbor_num; n++)
    {
        ptr2->neighbor[n] = ptr1->neighbor[n];
        ptr2->neighbor_state[n] = ptr1->neighbor_state[n];
    }

    ptr1->distance = tmp_dist;
    ptr1->pos.z = tmp_z;
    // ptr1->pos.y = tmp_y;
    ptr1->pos.x = tmp_x;
    ptr1->state = tmp_state;
    ptr1->neighbor_num = tmp_num;
    for (int n = 0; n < ptr1->neighbor_num; n++)
    {
        ptr1->neighbor[n] = tmp_neighbor[n];
        ptr1->neighbor_state[n] = tmp_neighbor_state[n];
    }

    return ptr1;
}

*/