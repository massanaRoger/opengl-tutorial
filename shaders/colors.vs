#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

out vec3 Ambient;
out vec3 Diffuse;
out vec3 Specular;

void main()
{
    float ambientStrength = 0.1;
    Ambient = ambientStrength * lightColor;

    vec3 fragPos = vec3(model * vec4(aPos, 1.0));

    vec3 norm = normalize(aNormal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    Diffuse = diff * lightColor;

    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    Specular = specularStrength * spec * lightColor;

	gl_Position = projection * view * model * vec4(aPos, 1.0);
}
