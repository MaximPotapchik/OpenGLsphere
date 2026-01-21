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

GLfloat vertices[] = {
    // positions         // colors
    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   
};

GLuint indices[] = {
	0, 3, 5,
	3, 2, 4, 
	5, 4, 1 
};

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
	glViewport(0, 0, 800, 800);


	Shader shader("shaders/vertex.vert", "shaders/fragment.frag");

	std::vector<GLfloat> verticesVec(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));
    std::vector<GLuint> indicesVec(indices, indices + sizeof(indices) / sizeof(indices[0]));

	Mesh triangle(verticesVec, indicesVec);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	while (!glfwWindowShouldClose(window)) {

   
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		shader.Activate();          
		triangle.draw();

        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    }

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}