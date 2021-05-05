#include <iostream>

// import OPENGL dependencies
#include "./OpenGL/GLEW/include/glew.h"
#include "./OpenGL/GLFW/include/glfw3.h"
#include "./OpenGL/glm/glm/glm.hpp"
#include"./OpenGL/glm/glm/gtc/type_ptr.hpp"

// include project classes
#include "Mesh.h"
#include "Shader.h"
#include "State.h"
#include "Transform.h"

// define constants
#define SPEED 0.7f
#define SIZE_FACTOR 0.1f
#define DIMENSIONS glm::vec3(1.0f, 4.0f, 1.0f)
#define LIGHT_SOURCE glm::vec3(128.0f, 50.0f, -100.0f)
#define COLOR glm::vec3(0.3f, 0.3f, 0.3f)

// function to define quit
void winQuit(GLFWwindow* window){
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	// initiation glfw
	if (!glfwInit()){
		std::cout << "GLFW failed" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// creating window
	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "robotArm", NULL, NULL);
	glfwSetWindowPos(window, 100, 100);
	if (window == NULL) {
		std::cout << "OPENGL failed" << std::endl;
		glfwTerminate();
		return -1;
	}

	// more glfw stuff
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW failed" << std::endl;
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glEnable(GL_DEPTH_TEST);


	// initiating object and shaders
	Shader Shader("Shaders/vShader.glsl", "Shaders/fShader.glsl");
	Mesh Mesh("cube.obj");
	//Model cubeModel = loadModel("cube.obj");
	//Mesh model;
	//model.load("cube.obj");

	// initiating state and transformation helper
	State State(SPEED);
	Transform Transform(SIZE_FACTOR, DIMENSIONS);

	while (!glfwWindowShouldClose(window)) {

		winQuit(window);

		// clear screen
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// set shader and put light source
		Shader.Use();
		Shader.setUniform3("lightSource", LIGHT_SOURCE);
		Shader.setUniform3("color", COLOR);

		// look for input
		State.GetInput(window);

		// prepare transform matrices
		Transform.transform(State.bicep, State.forearm);

		// draw bicep
		Shader.setUniform4("transformMat", Transform.bicepMat);
		Mesh.draw();
		//drawModelVertex(2.0, cubeModel);
		//drawModelFaces(cubeModel);

		// draw forearm
		Shader.setUniform4("transformMat", Transform.foreArmMat);
		Mesh.draw();
		//drawModelVertex(2.0, cubeModel);
		//drawModelFaces(cubeModel);

		// swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}