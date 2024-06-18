//
// Created by Roger2 on 18/06/2024.
//

#include "Model.h"
#include "assimp/Importer.hpp"
#include <iostream>
#include <assimp/postprocess.h>

void Model::Draw(Shader &shader) 
{
    for(unsigned int i = 0; i < meshes.size(); i++) 
    {
        meshes[i].Draw(shader);
    }
}

void Model::loadModel(std::string path) 
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));

    processNode(scene->mRootNode, scene);
}
