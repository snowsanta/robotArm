#include "State.h"

State::State(float speed)
	: speed(speed), curr(0)
{
	memset(bicep, 0, 3 * sizeof(float));
	memset(forearm, 0, 2 * sizeof(float));
}

State::~State()
{
}

void State::GetInput(GLFWwindow* window) {

	// For constant pacing in unconstant frame rate
	curr = glfwGetTime();
	frameDuration = curr - last;
	last = curr;

	// Keyboard input
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		if (bicep[0] >= -PI/2 && bicep[0] <= PI/2) {
			bicep[0] += speed * frameDuration;
		}
		else {
			bicep[0] = (bicep[0] > 0) ? 1.56 : -1.56;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		if (bicep[0] >= -PI/2 && bicep[0] <= PI/2) {
			bicep[0] -= speed * frameDuration;
		}
		else {
			bicep[0] = (bicep[0] > 0) ? 1.56 : -1.56;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		if (bicep[1] >= -PI && bicep[1] <= PI) {
			bicep[1] += 2 * speed * frameDuration;
		}
		else {
			bicep[1] = (bicep[1] > 0) ? 3.13 : -3.13;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		if (bicep[1] >= -PI && bicep[1] <= PI) {
			bicep[1] -= 2 * speed * frameDuration;
		}
		else {
			bicep[1] = (bicep[1] > 0) ? 3.13 : -3.13;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		if (bicep[2] >= -PI / 2 && bicep[2] <= PI / 2) {
			bicep[2] += speed * frameDuration;
		}
		else {
			bicep[2] = (bicep[2] > 0) ? 1.56 : -1.56;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		if (bicep[2] >= -PI/2 && bicep[2] <= PI/2) {
			bicep[2] -= speed * frameDuration;
		}
		else {
			bicep[2] = (bicep[2] > 0) ? 1.56 : -1.56;
		}
	}

	// Mouse input
	glfwGetWindowSize(window, &width, &height);
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if (mouseX >= 0 && mouseX < width && mouseY >= 0 && mouseY < height) {
		forearm[0] = PI * (mouseX - (width / 2)) / width;
		forearm[1] = PI * (mouseY - (height / 2)) / height;
	}

}
