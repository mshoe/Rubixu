#pragma once

#include "Classes.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#include <vector>

struct Face
{
public:
	Face(glm::vec3 translation, glm::quat rotation, glm::vec3 color, float scale);
	~Face();

	glm::mat4 rotationMatrix;
	glm::mat4 translationMatrix;
	glm::mat4 scaleMatrix;

	glm::mat4 modelMatrix;

	std::vector<glm::vec3> *vertices;//indices will be 013123

	void rotate(glm::quat rotation);
	void translate(glm::vec3 translation);
	void scale(float scale);
	void updateVertices();
};