#ifndef MESH
#define MESH

#include<glad/glad.h>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class Mesh{
private:
	GLuint VAO, VBO, EBO;
    unsigned int indexCount;

public:
    Mesh(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices);
    void draw();
    ~Mesh();
};
#endif