#include "Camera.h"

Camera::Camera(int width, int height)
{
    position = glm::vec3(0.0f, 0.0f, 5.0f);
    orientation = glm::vec3(0.0f, 0.0f, 0.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    
    moveSpeed = 0.05f;
    zoomSpeed = 0.1f;
    
    fov = 45.0f;
    aspectRatio = (float)width / (float)height;
    nearPlane = 0.1f;
    farPlane = 100.0f;
}

glm::mat4 Camera::getCameraMatrix()
{
    glm::mat4 view = glm::lookAt(position, orientation, up);

    glm::mat4 projection = glm::perspective(
        glm::radians(fov),
        aspectRatio,
        nearPlane,
        farPlane
    );
     return projection * view;
}

void Camera::Inputs(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) 
    {
        position.y += moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) 
    {
        position.y -= moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) 
    {
        position.x -= moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) 
    {
        position.x += moveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) 
    {
        
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) 
    {
        
    }
}