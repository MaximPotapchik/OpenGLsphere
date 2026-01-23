#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <cmath>




struct MeshData {
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
};

inline MeshData generateSphere(GLfloat radius, GLuint rings, GLuint sectors)
{
    MeshData data;
    const GLfloat PI = 3.14159265359f;
    
    for (GLuint ring = 0; ring <= rings; ring ++)
    {
        GLfloat lattitude = PI * GLfloat(ring) / GLfloat(rings);
        
        for (GLuint sector = 0; sector <= sectors; sector++)
        {
            GLfloat longitude = (GLfloat(sector) / GLfloat(sectors)) * 2 * PI;

            GLfloat x = radius * sin(lattitude) * cos(longitude);
            GLfloat y = radius * cos(lattitude);
            GLfloat z = radius * sin(lattitude) * sin(longitude);

            data.vertices.push_back(x);
            data.vertices.push_back(y);
            data.vertices.push_back(z);

            GLfloat r = (sin(lattitude) + 1.0f) * 0.5f;
            GLfloat g = (cos(longitude) + 1.0f) * 0.5f;
            GLfloat b = (sin(longitude) + 1.0f) * 0.5f;
            
            data.vertices.push_back(r);
            data.vertices.push_back(g);
            data.vertices.push_back(b);
        }
    }

    for (GLuint ring = 0; ring < rings; ring++) {
        for (GLuint sector = 0; sector < sectors; sector++) {
            GLuint current = ring * (sectors + 1) + sector;
            GLuint next = current + sectors + 1;
            
            
            data.indices.push_back(current);
            data.indices.push_back(next);
            data.indices.push_back(current + 1);
            
            data.indices.push_back(current + 1);
            data.indices.push_back(next);
            data.indices.push_back(next + 1);
        }
    }
    return data;
}

#endif