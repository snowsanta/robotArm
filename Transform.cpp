#include "transform.h"

Transform::Transform(float sizeFactor, glm::vec3 dimensions)
	:sizeFactor(sizeFactor), dimensions(dimensions)
{
}

Transform::~Transform()
{
}

void Transform::transform(float bicep[3], float forearm[2]) {

	// rotate temp matrix with bicep angles
	glm::mat4 temp = glm::mat4(1.0f);
	temp = glm::translate(temp, sizeFactor * dimensions * glm::vec3(0.0f, -0.5f, 0.0f));
	temp = glm::rotate(temp, bicep[0], glm::vec3(0.0f, 0.0f, 1.0f));
	temp = glm::rotate(temp, bicep[1], glm::vec3(1.0f, 0.0f, 0.0f));
	temp = glm::rotate(temp, bicep[2], glm::vec3(0.0f, 1.0f, 0.0f));

	// scale and store for bicep matrix
	bicepMat = temp;
	bicepMat = glm::translate(bicepMat, sizeFactor * dimensions * glm::vec3(0.0f, 0.5f, 0.0f));
	bicepMat = glm::scale(bicepMat, sizeFactor * dimensions);

	// overlap forearm angle transformations
	// scale and store for forearm matrix
	foreArmMat = temp;
	foreArmMat = glm::translate(foreArmMat, sizeFactor * dimensions * glm::vec3(0.0f, 1.0f, 0.0f));
	foreArmMat = glm::rotate(foreArmMat, -forearm[0], glm::vec3(0.0f, 0.0f, 1.0f));
	foreArmMat = glm::rotate(foreArmMat, -forearm[1], glm::vec3(1.0f, 0.0f, 0.0f));
	foreArmMat = glm::translate(foreArmMat, sizeFactor * dimensions * glm::vec3(0.0f, 0.5f, 0.0f));
	foreArmMat = glm::scale(foreArmMat, sizeFactor * dimensions);
}