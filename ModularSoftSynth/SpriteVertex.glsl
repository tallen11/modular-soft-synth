#version 330 core

layout(location = 0) in vec4 vertexPosition_modelSpace;

out vec2 UV;
uniform mat4 model;
uniform mat4 projection;

void main()
{
    UV = vertexPosition_modelSpace.zw;
    gl_Position = projection * model * vec4(vertexPosition_modelSpace.xy, 0.0f, 1.0f);
}