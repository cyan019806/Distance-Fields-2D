#ifndef DRAWMODEL_H
#define DRAWMODEL_H
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "MatrixStack.h"
#include "background.h"
#include "Object.h"
#include "Camera.h"
#include "Shader.h"


void Shader_Create();
void Shader_init(glm::vec3 position, glm::vec3 front, bool blinn);
void ViewProjection_Create(glm::mat4 viewMatrix, float zoom, int width, int height);

void Model_Voxel_Create(unsigned int VAO, int size);
void Model_Curve_Create(unsigned int VAO, int size);
void Model_Test_Create(unsigned int VAO, int size);

extern MatrixStack model;
extern MatrixStack view;
extern MatrixStack projection;

#endif