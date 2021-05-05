#pragma once

#include<iostream>
#include<string>
#include<fstream>

#include "./OpenGL/GLEW/include/glew.h"
#include "./OpenGL/GLFW/include/glfw3.h"
#include "./OpenGL/glm/glm/glm.hpp"
#include"./OpenGL/glm/glm/gtc/type_ptr.hpp"

/*
Compiles and links shaders to newly formed context
*/

class Shader {

public:

	Shader(const char* VertexShader, const char* FragmentShader);
	~Shader();

	void Use();
	void setUniform3(const char* location, glm::fvec3 value);
	void setUniform4(const char* location, glm::mat4 value);

private:

	GLuint program;
	std::string loadSource(const char* filepath);
};

