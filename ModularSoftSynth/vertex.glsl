#version 330 core

layout(location = 0) in vec2 vertexPosition_modelspace;

const float PI = 3.141592f;

void main()
{
    float x = vertexPosition_modelspace.y - 1.0f;
    float y = vertexPosition_modelspace.x;
    
//    float angle = (((x - (-1.0f))* (2.0f * PI - 0.0f)) / (1.0f - (-1.0f)));
//    gl_Position = vec4(y * cos(angle), y * sin(angle), 0.0, 1.0);
    
    gl_Position = vec4(x, y, 0.0f, 1.0f);
}