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

void Rubixu3::R()
{
	for (int i = 2; i < 27; i += 3) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(glm::radians(-90.f), 0, 0)), glm::vec3(1, 0, 0));
	}

	applyRotations(2, 8, 26, 20, 5, 17, 23, 11);
}

void Rubixu3::Ri()
{
	for (int i = 2; i < 27; i += 3) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(glm::radians(90.f), 0, 0)), glm::vec3(1, 0, 0));
	}

	applyRotations(2, 20, 26, 8, 5, 11, 23, 17);
}

void Rubixu3::L()
{
	for (int i = 0; i < 27; i += 3) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(glm::radians(90.f), 0, 0)), glm::vec3(1, 0, 0));
	}

	applyRotations(7, 0, 18, 24, 4, 9, 21, 15);
}

void Rubixu3::Li()
{
	for (int i = 0; i < 27; i += 3) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(glm::radians(-90.f), 0, 0)), glm::vec3(1, 0, 0));
	}

	applyRotations(7, 24, 18, 0, 4, 15, 21, 9);
}

void Rubixu3::U()
{
	for (int i = 0; i < 9; i++) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(0, glm::radians(-90.f), 0)), glm::vec3(0, 1, 0));
	}

	applyRotations(6, 8, 2, 0, 7, 5, 1, 3);
}

void Rubixu3::Ui()
{
	for (int i = 0; i < 9; i++) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(0, glm::radians(90.f), 0)), glm::vec3(0, 1, 0));
	}

	applyRotations(6, 0, 2, 8, 7, 3, 1, 5);
}

void Rubixu3::D()
{
	for (int i = 18; i < 27; i++) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(0, glm::radians(90.f), 0)), glm::vec3(0, 1, 0));
	}
}

void Rubixu3::Di()
{
	for (int i = 0; i < 9; i++) {
		(*cubes)[i]->rotateAround(glm::quat(glm::vec3(0, glm::radians(-90.f), 0)), glm::vec3(0, 1, 0));
	}
}

void Rubixu3::F()
{
	for (int k = 0; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*cubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, glm::radians(-90.f))), glm::vec3(0, 0, 1));
		}
	}

	applyRotations(0, 2, 20, 18, 1, 11, 19, 9);
}

void Rubixu3::Fi()
{
	for (int k = 0; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*cubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, glm::radians(90.f))), glm::vec3(0, 0, 1));
		}
	}

	applyRotations(0, 18, 20, 2, 1, 9, 19, 11);
}

void Rubixu3::B()
{
	for (int k = 6; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*cubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, glm::radians(90.f))), glm::vec3(0, 0, 1));
		}
	}

	applyRotations(9, 7, 24, 26, 8, 15, 25, 17);
}

void Rubixu3::Bi()
{
	for (int k = 6; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*cubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, glm::radians(-90.f))), glm::vec3(0, 0, 1));
		}
	}
	applyRotations(9, 26, 24, 7, 8, 17, 25, 15);
}

void Rubixu3::applyRotations(int a, int b, int c, int d, int e, int f, int g, int h)
{
	Cube *temp1, *temp2;

	temp2 = (*cubes)[a];
	temp1 = (*cubes)[b];
	(*cubes)[b] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[c];
	(*cubes)[c] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[d];
	(*cubes)[d] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[a];
	(*cubes)[a] = temp2;

	temp2 = (*cubes)[e];
	temp1 = (*cubes)[f];
	(*cubes)[f] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[g];
	(*cubes)[g] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[h];
	(*cubes)[h] = temp2;
	temp2 = temp1;
	temp1 = (*cubes)[e];
	(*cubes)[e] = temp2;
}
