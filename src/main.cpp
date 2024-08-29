#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Shader.h"
#include "background.h"
#include "Object.h"
#include "Camera.h"
#include "model.h"
#include "DrawModel.h"
#include "MarchingCubeTables.h"
#include <thread>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

// time
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// light
bool blinn = false;

// camera
Camera camera(glm::vec3(5.f, 10.0f, 5.f), glm::vec3(0.0f, 1.0f, 0.0f));

int start = 0;

// 擴散方式
int mode;

// thread (speed up)
std::thread t1;

bool flag = false;

Node *CloseHead = voxelmodel.CloseList;
Node *DoneHead;
Node *FarHead;

glm::fvec3 *color = isoSurface.ColorMap;

int main()
{
	// glfw initialize
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	// glfw window creation
	GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Distance_Fields", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// glfwSetKeyCallback(window, keyPressFunc);
	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ImGui setting
	const char *glsl_version = "#version 330";
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	(void)io;

	// setup Dear ImGui style
	ImGui::StyleColorsDark();
	ImGui::StyleColorsLight();
	// Setup Platform/ Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// create shader
	Shader_Create();

	// create model
	voxelmodel.CreateVoxel();
	voxelmodel.SetVoxelData(0);
	voxelmodel.CreateLinkedList();

	// Set color map
	isoSurface.create_color_map();

	createBackground();

	// test_curve();

	Object Voxel(background.voxel);
	Object Curve(background.curve);
	// Object Test(background.test);

	glEnable(GL_DEPTH_TEST);
	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// imGui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("Distance Fields");
		// show the process of Distance Fields compution
		if (ImGui::Button("Points"))
		{
			mode = 0;
			start = 1;
			CloseHead = voxelmodel.CloseList;
			DoneHead = voxelmodel.DoneList;
			FarHead = voxelmodel.FarList;
		}
		// show the diffusion by lines
		if (ImGui::Button("Lines"))
		{
			mode = 1;
			start = 1;
			// set the range
			voxelmodel.boundary_min = {voxelmodel.center.x, voxelmodel.center.y, voxelmodel.min.z};
			voxelmodel.boundary_max = {voxelmodel.center.x, voxelmodel.center.y, voxelmodel.max.z};
			CloseHead = voxelmodel.CloseList;
			DoneHead = voxelmodel.DoneList;
			FarHead = voxelmodel.FarList;
		}
		// show the diffusion by plane
		if (ImGui::Button("Planes"))
		{
			mode = 2;
			start = 1;
			// set the range
			voxelmodel.boundary_min = {voxelmodel.center.x, voxelmodel.center.y, voxelmodel.center.z};
			voxelmodel.boundary_max = {voxelmodel.center.x, voxelmodel.center.y, voxelmodel.center.z};
			CloseHead = voxelmodel.CloseList;
			DoneHead = voxelmodel.DoneList;
			FarHead = voxelmodel.FarList;
		}
		if (ImGui::Button("iso-curve"))
		{
			mode = 3;
			start = 1;
			CloseHead = voxelmodel.CloseList;
			DoneHead = voxelmodel.DoneList;
			FarHead = voxelmodel.FarList;
		}
		ImGui::End();

		// move(keyboard & mouse)
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Shader_init(camera.Position, camera.Front, blinn);
		ViewProjection_Create(camera.GetViewMatrix(), camera.Zoom, SCR_WIDTH, SCR_HEIGHT);
		// draw model
		if (start == 0)
		{
			Model_Voxel_Create(Voxel.VAO, background.voxel.size());
		}
		else
		{
			if (mode == 0)
			{
				if (CloseHead != NULL)
				{
					Node *target = voxelmodel.StartFastMarching(CloseHead, DoneHead, FarHead);
					CloseHead = voxelmodel.DeleteFirstNode(target);
				}
				else if (flag == false)
				{
					voxelmodel.FindMinAndMaxDist();
					flag = true;
				}
				// show the finally 
				// else
				// {
				// 	PointsRenewBackground();
				// 	Voxel.renewVBO(background.voxel);
				// 	Model_Voxel_Create(Voxel.VAO, background.voxel.size());
				// }
				PointsRenewBackground();
				Voxel.renewVBO(background.voxel);
				Model_Voxel_Create(Voxel.VAO, background.voxel.size());
			}
			else if (mode == 1)
			{
				if (CloseHead != NULL)
				{
					Node *target = voxelmodel.StartFastMarching(CloseHead, DoneHead, FarHead);
					CloseHead = voxelmodel.DeleteFirstNode(target);
				}
				else if (flag == false)
				{
					voxelmodel.FindMinAndMaxDist();
					flag = true;
				}
				else // draw after Distance Fields compute
				{
					int time = 100000;
					if (voxelmodel.boundary_min.x >= voxelmodel.min.x && voxelmodel.boundary_max.x < voxelmodel.max.x)
					{
						LinesRenewBackground(voxelmodel.boundary_min.x, voxelmodel.boundary_max.x);
						Voxel.renewVBO(background.voxel);
						while (time--)
						{
							Model_Voxel_Create(Voxel.VAO, background.voxel.size());
						}
						voxelmodel.boundary_min.x--;
						voxelmodel.boundary_max.x++;
					}
					Model_Voxel_Create(Voxel.VAO, background.voxel.size());
				}
			}
			else if (mode == 2)
			{
				if (CloseHead != NULL)
				{
					Node *target = voxelmodel.StartFastMarching(CloseHead, DoneHead, FarHead);
					CloseHead = voxelmodel.DeleteFirstNode(target);
				}
				else if (flag == false)
				{
					voxelmodel.FindMinAndMaxDist();
					flag = true;
				}
				else // draw after Distance Fields compute
				{
					int time = 100000;
					if ((voxelmodel.boundary_min.x >= voxelmodel.min.x && voxelmodel.boundary_max.x < voxelmodel.max.x) && (voxelmodel.boundary_min.z >= voxelmodel.min.z && voxelmodel.boundary_max.z < voxelmodel.max.z))
					{
						PlanesRenewBackground(voxelmodel.boundary_min.z, voxelmodel.boundary_max.z, voxelmodel.boundary_min.x, voxelmodel.boundary_max.x);
						Voxel.renewVBO(background.voxel);
						while (time--)
						{
							Model_Voxel_Create(Voxel.VAO, background.voxel.size());
						}
						voxelmodel.boundary_min.z--;
						voxelmodel.boundary_max.z++;
						voxelmodel.boundary_min.x--;
						voxelmodel.boundary_max.x++;
					}
					Model_Voxel_Create(Voxel.VAO, background.voxel.size());
				}
			}
			else if (mode == 3)
			{
				if (CloseHead != NULL)
				{
					Node *target = voxelmodel.StartFastMarching(CloseHead, DoneHead, FarHead);
					CloseHead = voxelmodel.DeleteFirstNode(target);
				}
				else if (flag == false)
				{
					voxelmodel.FindMinAndMaxDist();
					// // show the finally 
					// for (int i = 0; i < voxelmodel.max_dist; i++)
					// {
					// 	// int i = 2;
					// 	isoSurface.Polygonise(i);
					// // 	std::cout << i << " ";
					// }
					flag = true;
				}
				// else
				// {
					for (int i = 0; i < 64; i++)
					{
						// int i = 2;
						isoSurface.Polygonise(i);
						// 	std::cout << i << " ";
						Curve.renewVBO(background.curve);
						Model_Curve_Create(Curve.VAO, background.curve.size());
					}
				// }
			}
		}
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	voxelmodel.FreeNode(voxelmodel.DoneList);
	// voxelmodel.FreeNode(voxelmodel.CLOSE);
	// voxelmodel.FreeNode(voxelmodel.FAR);
	// isoSurface.delete_color_map();
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		camera.ProcessKeyboard(UP, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(DOWN, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		camera.ProcessKeyboard(PITCHUP, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		camera.ProcessKeyboard(PITCHDOWN, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
		camera.ProcessKeyboard(YAWUP, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		camera.ProcessKeyboard(YAWDOWN, deltaTime);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void createThread()
{
	if (t1.joinable())
	{
		t1.join();
	}
	// t1 = std::thread(runthreadSomIter);
}