#pragma once
#include "Classes.h"
#include "Cube.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>
#include <vector>
#include <queue>

class Rubixu3
{
public:
	Rubixu3();
	~Rubixu3();

	void Init();
	void CleanUp();

	void R();
	void Ri();
	void L();
	void Li();
	void U();
	void Ui();
	void D();
	void Di();
	void F();
	void Fi();
	void B();
	void Bi();

	void applyRotations(int a, int b, int c, int d, int e, int f, int g, int h);
	std::vector<Cube*> *cubes;
};