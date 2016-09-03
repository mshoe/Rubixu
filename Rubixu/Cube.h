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

enum face {
	FACE_WHITE = 0,
	FACE_BLUE = 1,
	FACE_RED = 2,
	FACE_GREEN = 3,
	FACE_ORANGE = 4,
	FACE_YELLOW = 5
};

struct Cube
{
public:
	Cube() { initVertices(); };
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, float scale);
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, float scale);
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, float scale);
	Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, glm::vec3 color3, int face3, float scale);
	~Cube();

	void initVertices();
	void initColor(glm::vec3 color, int face);

	void CleanUp();

	// Transformations
	glm::vec3 translation;
	glm::quat rotation;
	float scale = 1.f;

	/*glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;*/

	glm::mat4 modelMatrix;

	void Transform(glm::vec3 translation, glm::quat rotation, float scale);
	void Translate(glm::vec3 translation);
	void Rotate(glm::quat rotation);
	void Scale(float scale);
	void rotateAround(glm::quat rotation, glm::vec3 point);
	void updateModelMatrix();
	std::vector<GLfloat> outputVertices();

	std::vector<GLfloat> *vertices = NULL;
	
	// colors
	glm::vec3 color0;
	glm::vec3 color1;
	glm::vec3 color2;
	glm::vec3 color3;
	glm::vec3 color4;
	glm::vec3 color5;

	
};