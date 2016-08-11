#pragma once
#include "Cube.h"

class Rubixu3
{
public:
	Rubixu3();
	~Rubixu3();

	void Init();
	void CleanUp();

	std::vector<Cube*> *cubes;
};