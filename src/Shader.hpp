#ifndef SHADER_H
#define SHADER_H

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

private:
    unsigned int compileVertexShader(const char *vertexShaderSource); 
    unsigned int compileFragmentShader(const char *fragmentShaderSource); 
    void linkFragmentsToProgram(unsigned int vertexShader, unsigned int fragmentShader);
};


#endif
