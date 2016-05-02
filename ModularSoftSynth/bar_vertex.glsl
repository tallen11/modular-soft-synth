#version 330 core

layout(location = 0) in vec2 vertexPosition_modelspace;
uniform float height;
uniform float time;
uniform mat4 rotationMatrix;

const float PI = 3.141592f;
const float rotFreq = 0.04f;

void main()
{
    float x = vertexPosition_modelspace.x - 1.0f;
    float y = vertexPosition_modelspace.y;
    
//    float rotAngle = 2.0f * PI * rotFreq * time;
//    mat4 rotMat;
//    rotMat[0] = vec4(cos(rotAngle), sin(rotAngle), 0.0f, 0.0f);
//    rotMat[1] = vec4(-sin(rotAngle), cos(rotAngle), 0.0f, 0.0f);
//    rotMat[2] = vec4(0.0f, 0.0f, 1.0f, 0.0f);
//    rotMat[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);
//    
//    float angle = (((x - (-1.0f))* (2.0f * PI - 0.0f)) / (1.0f - (-1.0f)));
//    float angleSine = sin(angle);
//    float angleCos = cos(angle);
//    gl_Position = vec4(y * angleCos + 0.1f * angleCos + 0.08f * height * angleCos,
//                       y * angleSine + 0.1f * angleSine + 0.08f * height * angleSine,
//                       0.0, 1.0) * rotMat;
    
    gl_Position = vec4(x, y, 0.0f, 1.0f);
}