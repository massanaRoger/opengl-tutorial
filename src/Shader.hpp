#ifndef SHADER_H
#define SHADER_H

#include "glm/ext/matrix_float4x4.hpp"
#include <glad/glad.h>
#include <string>

class Shader
{
public:
    unsigned int ID;

    // Constructor that reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Function to activate the shader
    void use();

    // Utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, glm::mat4 value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;

private:
    unsigned int compileVertexShader(const char *vertexShaderSource); 
    unsigned int compileFragmentShader(const char *fragmentShaderSource); 
    void linkFragmentsToProgram(unsigned int vertexShader, unsigned int fragmentShader);
};


#endif
