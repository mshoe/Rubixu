#pragma once
#include "Classes.h"
#include "Cube.h"
#include "Rubixu.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#include <vector>
#include <queue>

enum RotatingFace {
	ROTATE_RIGHT = 1,
	ROTATE_RIGHT_INVERTED = 2,
	ROTATE_LEFT = 3,
	ROTATE_LEFT_INVERTED = 4,
	ROTATE_UP = 5,
	ROTATE_UP_INVERTED = 6,
	ROTATE_DOWN = 7,
	ROTATE_DOWN_INVERTED = 8,
	ROTATE_FRONT = 9,
	ROTATE_FRONT_INVERTED = 10,
	ROTATE_BACK = 11,
	ROTATE_BACK_INVERTED = 12
};

class Rubixu3
{
public:
	Rubixu3(Rubixu *rubixu);
	~Rubixu3();

	void Init();
	void CleanUp();

	void Loop();

	void Scramble();
	bool scramble;

	void Rotate();
	void RotateAll(glm::quat);

	float R();
	float Ri();
	float L();
	float Li();
	float U();
	float Ui();
	float D();
	float Di();
	float F();
	float Fi();
	float B();
	float Bi();

	void applyRotations(int a, int b, int c, int d, int e, int f, int g, int h);
	std::vector<Cube*> *cubes;
	std::vector<Cube*> *rotatedCubes;

	glm::vec3 Up, Front, Left, Right, Back, Down;
	glm::mat4 modelMatrix;

	int rotatingFace;
	float totalRotation;
	float speed;

	Rubixu *rubixu;
};