#pragma once
#include "Classes.h"
#include "Face.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#include <vector>

enum face {
	FACE_TOP = 0,
	FACE_FRONT = 1,
	FACE_LEFT = 2,
	FACE_BACK = 3,
	FACE_RIGHT = 4,
	FACE_BOTTOM = 5
};

struct Cube
{
public:
	Cube() { initVertices(); };
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, float scale);
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, float scale);
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, glm::vec3 color3, int face3, float scale);
	~Cube();

	void initVertices();
	void initColor(glm::vec3 color, int face);

	void CleanUp();

	// Transformations
	glm::quat rotation;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	void transform(glm::vec3 translation, glm::quat rotation, float scale);
	void updateVertices();

	std::vector<GLfloat> *vertices = NULL;
private:
	glm::vec3 color0;
	glm::vec3 color1;
	glm::vec3 color2;
	glm::vec3 color3;
	glm::vec3 color4;
	glm::vec3 color5;
};