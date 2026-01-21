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

GLfloat vertices[] = {
    // positions         // colors
    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   
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

	GLFWwindow* window = glfwCreateWindow(800, 600, "My GLFW Window", NULL, NULL);

	Shader shader("shaders/vertex.vert", "shaders/fragment.frag");

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Position attribute (location = 0 in shader)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color attribute (location = 1 in shader)
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	while (!glfwWindowShouldClose(window)) {

   
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		shader.Activate();           // Use the shader program
		glBindVertexArray(VAO);      // Bind the vertex data
		glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    }

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}