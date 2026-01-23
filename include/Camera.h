#ifndef CAMERA  
#define CAMERA

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Camera
{
public:
    glm::vec3 position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    float fov;          
    float aspectRatio;  
    float nearPlane;    
    float farPlane;     

    float moveSpeed;
    float zoomSpeed;

    int width;
	int height;

    Camera(int width, int height);

    void UpdatePos();

    glm::mat4 getCameraMatrix();
    void Inputs(GLFWwindow* window);

};








#endif