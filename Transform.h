#pragma once

#include <iostream>

#include "./OpenGL/GLEW/include/glew.h"
#include "./OpenGL/GLFW/include/glfw3.h"
#include "./OpenGL/glm/glm/glm.hpp"
#include "./OpenGL/glm/glm/gtc/type_ptr.hpp"

/*
Transforms the position in accordance to updates in state variables
*/

class Transform
{
public:
	Transform::Transform(float sizeFactor, glm::vec3 dimensions);
	Transform::~Transform();

	glm::mat4 bicepMat, foreArmMat;
	void transform(float bicep[3], float forearm[2]);

private:
	float sizeFactor;
	glm::vec3 dimensions;
};

