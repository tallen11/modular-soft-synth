#version 330 core

out vec3 color;

void main()
{
    color = vec3(gl_FragCoord.y, gl_FragCoord.y, gl_FragCoord.y);
}