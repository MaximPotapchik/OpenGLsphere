#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <string>

#include "Shader.h"
#include "Mesh.h"
#include "Primitives.h"
#include "Camera.h"

const int width = 800;
const int height = 800;

int main(){
	if (!glfwInit()) 
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "My GLFW Window", NULL, NULL);

	glfwMakeContextCurrent(window);
	
	gladLoadGL();
	glViewport(0, 0, width, height);

	glEnable(GL_DEPTH_TEST);

	Camera camera(width, height);

	MeshData sphere = generateSphere(1.0f, 30, 30);

	Shader shader("shaders/vertex.vert", "shaders/fragment.frag");



	Mesh sphereMesh(sphere.vertices, sphere.indices);



	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	

	while (!glfwWindowShouldClose(window)) {
		
   		camera.Inputs(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Activate();  

		glm::mat4 cameraMatrix = camera.getCameraMatrix();
		shader.setMat4("camMatrix", cameraMatrix);
		
		sphereMesh.draw();

        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    }

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}