#version 330 core
out vec4 FragColor;
  
uniform vec3 objectColor;

in vec3 Ambient;
in vec3 Diffuse;
in vec3 Specular;

void main()
{
    vec3 result = (Ambient + Diffuse + Specular) * objectColor;
    FragColor = vec4(result, 1.0);
}
