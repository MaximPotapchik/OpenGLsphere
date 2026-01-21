#version 330 core
out vec4 FragColor;  // Output: the final pixel color

in vec3 color;  // Input: interpolated color from vertex shader

void main()
{
    FragColor = vec4(color, 1.0);  // Set pixel color
}