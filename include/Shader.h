#ifndef SHADER
#define SHADER

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class Shader{
private:
	void compileErrors(unsigned int shader, const char* type);
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Activate();
    void Delete();

};
#endif