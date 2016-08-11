#include "Rubixu3.h"

Rubixu3::Rubixu3()
{
	Init();
}

Rubixu3::~Rubixu3()
{
	CleanUp();
}

void Rubixu3::Init()
{
	CleanUp();
	cubes = new std::vector<Cube*>(27);

	float d = 1.1f;

	(*cubes)[0 ] = new Cube(glm::vec3(-d, +d, +d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 1), 1, glm::vec3(1, 0, 0), 2, 1.f);
	(*cubes)[1 ] = new Cube(glm::vec3( 0, +d, +d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 1), 1, 1.f);
	(*cubes)[2 ] = new Cube(glm::vec3(+d, +d, +d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 1), 1, glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[3 ] = new Cube(glm::vec3(-d, +d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(1, 0, 0), 2, 1.f);
	(*cubes)[4 ] = new Cube(glm::vec3( 0, +d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, 1.f);
	(*cubes)[5 ] = new Cube(glm::vec3(+d, +d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[6 ] = new Cube(glm::vec3(-d, +d, -d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(1, 0, 0), 2, glm::vec3(0, 1, 0), 3, 1.f);
	(*cubes)[7 ] = new Cube(glm::vec3( 0, +d, -d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(0, 1, 0), 3, 1.f);
	(*cubes)[8 ] = new Cube(glm::vec3(+d, +d, -d), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 1), 0, glm::vec3(0, 1, 0), 3, glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[9 ] = new Cube(glm::vec3(-d,  0, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, glm::vec3(1, 0, 0), 2, 1.f);
	(*cubes)[10] = new Cube(glm::vec3( 0,  0, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, 1.f);
	(*cubes)[11] = new Cube(glm::vec3(+d,  0, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[12] = new Cube(glm::vec3(-d,  0,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 0, 0), 2, 1.f);
	(*cubes)[13] = new Cube();
	(*cubes)[14] = new Cube(glm::vec3(+d,  0,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[15] = new Cube(glm::vec3(-d,  0, -d), glm::quat(1, 0, 0, 0), glm::vec3(1, 0, 0), 2, glm::vec3(0, 1, 0), 3, 1.f);
	(*cubes)[16] = new Cube(glm::vec3( 0,  0, -d), glm::quat(1, 0, 0, 0), glm::vec3(0, 1, 0), 3, 1.f);
	(*cubes)[17] = new Cube(glm::vec3(+d,  0, -d), glm::quat(1, 0, 0, 0), glm::vec3(0, 1, 0), 3, glm::vec3(1, 0.5f, 0), 4, 1.f);
	(*cubes)[18] = new Cube(glm::vec3(-d, -d, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, glm::vec3(1, 0, 0), 2, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[19] = new Cube(glm::vec3( 0, -d, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[20] = new Cube(glm::vec3(+d, -d, +d), glm::quat(1, 0, 0, 0), glm::vec3(0, 0, 1), 1, glm::vec3(1, 0.5f, 0), 4, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[21] = new Cube(glm::vec3(-d, -d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 0, 0), 2, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[22] = new Cube(glm::vec3( 0, -d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[23] = new Cube(glm::vec3(+d, -d,  0), glm::quat(1, 0, 0, 0), glm::vec3(1, 0.5f, 0), 4, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[24] = new Cube(glm::vec3(-d, -d, -d), glm::quat(1, 0, 0, 0), glm::vec3(1, 0, 0), 2, glm::vec3(0, 1, 0), 3, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[25] = new Cube(glm::vec3( 0, -d, -d), glm::quat(1, 0, 0, 0), glm::vec3(0, 1, 0), 3, glm::vec3(1, 1, 0), 5, 1.f);
	(*cubes)[26] = new Cube(glm::vec3(+d, -d, -d), glm::quat(1, 0, 0, 0), glm::vec3(0, 1, 0), 3, glm::vec3(1, 0.5f, 0), 4, glm::vec3(1, 1, 0), 5, 1.f);
}

void Rubixu3::CleanUp()
{
	if (cubes != NULL) {
		for (int i = 0; i < 27; i++)
			delete (*cubes)[i];
		delete cubes;
	}
}
