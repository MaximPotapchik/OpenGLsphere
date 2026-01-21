#version 330 core
layout (location = 0) in vec3 aPos;    // Input: vertex position
layout (location = 1) in vec3 aColor;  // Input: vertex color

out vec3 color;  // Output: pass color to fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0);  // Required: final screen position
    color = aColor;                  // Pass color along the pipeline
}