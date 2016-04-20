#version 330 core

layout(location = 0) in vec2 vertexPosition_modelspace;

void main()
{
    gl_Position = vec4(vertexPosition_modelspace.y - 1.0, vertexPosition_modelspace.x, 0.0, 1.0);
}