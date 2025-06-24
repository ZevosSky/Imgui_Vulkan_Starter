//
// Created by Gary Yang on 6/23/2025.
//
#include "stdafx.h"



#ifndef CMAKELISTS_TXT_SHADER_H
#define CMAKELISTS_TXT_SHADER_H

class Shader {  // Pure virtual class

  public:

    virtual ~Shader() = default;  // Virtual destructor for proper cleanup

    // Pure virtual methods to be implemented by derived classes
    virtual void compile() = 0;  // Method to compile the shader
    virtual void bind() const = 0;  // Method to bind the shader for use
    virtual void unbind() const = 0;  // Method to unbind the shader


  private:

    std::string Source; // Shader source code
    std::string Name;   // Name of the shader

    // associated pipeline ID
    unsigned int PipelineID;

};

#endif // CMAKELISTS_TXT_SHADER_H
