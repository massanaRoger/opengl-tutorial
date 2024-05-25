#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float offset;

out vec3 ourColor;

void main()
{
    vec3 vec_with_offset = aPos + vec3(offset, 0, offset);
    gl_Position = vec4(vec_with_offset, 1.0);
    ourColor = aColor;
}

