#include "DrawModel.h"

MatrixStack model;
MatrixStack view;
MatrixStack projection;

Shader shader;

// shader_cls drawModel;

// shader_cls::shader_cls()
// {

// }

// shader_cls::~shader_cls()
// {
//     destroyBackground();
//     Voxel.Object_del();
// }

void Shader_Create()
{
    // shader
    shader = Shader("shader/shader.vs", "shader/shader.fs");
    // Voxel = Object(background.voxel);
}

void Shader_init(glm::vec3 position, glm::vec3 front, bool blinn) {
    shader.use();
    shader.setVec3("viewPos", position);
    shader.setVec3("lightPos", position);
    shader.setInt("blinn", blinn);
}

void ViewProjection_Create(glm::mat4 viewMatrix, float zoom, int width, int height) {
    view.Save(viewMatrix);
    projection.Save(glm::perspective(glm::radians(zoom), (float)width/(float)height, 0.0001f, 1000.0f));
    shader.setMat4("view", view.Top());
    shader.setMat4("projection", projection.Top());
    // shader.setVec3("viewPos", position);
    // shader.setVec3("lightPos", lightPos);
}

void Model_Voxel_Create(unsigned int VAO, int size)
{
    model.Push();
    model.Save(glm::translate(model.Top(), glm::vec3(0.0f, 0.0f, 0.0f)));
    shader.setMat4("model", model.Top());
    shader.setBool("shader", true);
    shader.setBool("ifTex", false);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, size);
    model.Pop();
}

void Model_Curve_Create(unsigned int VAO, int size)
{
    model.Push();
    model.Save(glm::translate(model.Top(), glm::vec3(0.0f, 0.0f, 0.0f)));
    shader.setMat4("model", model.Top());
    shader.setBool("shader", true);
    shader.setBool("ifTex", false);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, size);
    model.Pop();
}

void Model_Test_Create(unsigned int VAO, int size)
{
    model.Push();
    model.Save(glm::translate(model.Top(), glm::vec3(0.0f, 0.0f, 0.0f)));
    shader.setMat4("model", model.Top());
    shader.setBool("shader", true);
    shader.setBool("ifTex", false);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, size);
    model.Pop();
}