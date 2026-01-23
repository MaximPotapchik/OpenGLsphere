#ifndef SHADER
#define SHADER

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class Shader{
private:
	void compileErrors(unsigned int shader, const char* type);
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Activate();
    void Delete();
    void setMat4(const std::string& name, const glm::mat4& mat);

};
#endif