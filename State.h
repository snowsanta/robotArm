#pragma once

#include <iostream>

#include "./OpenGL/GLEW/include/glew.h"
#include "./OpenGL/GLFW/include/glfw3.h"
#include "./OpenGL/glm/glm/glm.hpp"
#include "./OpenGL/glm/glm/gtc/type_ptr.hpp"
  
#define PI 3.14

/*
Contains state variables for the arm
Variables contain degree of rotation for both parts
*/

class State
{
public:
	State(float speed);
	~State();

	float bicep[3], forearm[2];
	void GetInput(GLFWwindow* window);

private:
	double mouseX, mouseY;
	float frameDuration, last, curr, speed;
	int width, height;
};
