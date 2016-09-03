#include "Rubixu3.h"

Rubixu3::Rubixu3(Rubixu *rubixu)
{
	this->rubixu = rubixu;
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
	rotatedCubes = new std::vector<Cube*>(27);

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

	for (int i = 0; i < 27; i++)
		(*rotatedCubes)[i] = (*cubes)[i];

	rotatingFace = 0;
	totalRotation = 0.f;
	speed = 2.f;
	scramble = false;
	modelMatrix = glm::mat4(1.f);
	Front = glm::vec3(0, 0, 1);
	Back = glm::vec3(0, 0, -1);
	Up = glm::vec3(0, 1, 0);
	Down = glm::vec3(0, -1, 0);
	Right = glm::vec3(1, 0, 0);
	Left = glm::vec3(-1, 0, 0);
}

void Rubixu3::CleanUp()
{
	if (cubes != NULL) {
		for (int i = 0; i < 27; i++)
			delete (*cubes)[i];
		delete cubes;
	}
}

void Rubixu3::Loop()
{
	if (scramble)
		Scramble();
	Rotate();
}

void Rubixu3::Scramble()
{
	if (rotatingFace == 0) {
		int randomList[] = {1, 3, 5, 7, 9, 11};
		int random = rand() % 5;
		rotatingFace = randomList[random];
		std::cout << randomList[random] << std::endl;
	}
}

void Rubixu3::Rotate()
{
	if (rotatingFace != 0) {
		switch (rotatingFace)
		{
		case ROTATE_RIGHT:
			totalRotation += R();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(2, 8, 26, 20, 5, 17, 23, 11);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_RIGHT_INVERTED:
			totalRotation += Ri();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(2, 20, 26, 8, 5, 11, 23, 17);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_LEFT:
			totalRotation += L();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(6, 0, 18, 24, 3, 9, 21, 15);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_LEFT_INVERTED:
			totalRotation += Li();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(6, 24, 18, 0, 3, 15, 21, 9);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_UP:
			totalRotation += U();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(6, 8, 2, 0, 7, 5, 1, 3);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_UP_INVERTED:
			totalRotation += Ui();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(6, 0, 2, 8, 7, 3, 1, 5);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_DOWN:
			totalRotation += D();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(18, 20, 26, 24, 19, 23, 25, 21);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_DOWN_INVERTED:
			totalRotation += Di();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(18, 24, 26, 20, 19, 21, 25, 23);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_FRONT:
			totalRotation += F();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(0, 2, 20, 18, 1, 11, 19, 9);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_FRONT_INVERTED:
			totalRotation += Fi();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(0, 18, 20, 2, 1, 9, 19, 11);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_BACK:
			totalRotation += B();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(8, 6, 24, 26, 7, 15, 25, 17);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		case ROTATE_BACK_INVERTED:
			totalRotation += Bi();
			if (glm::abs(totalRotation) >= glm::radians(90.f)) {
				applyRotations(8, 26, 24, 6, 7, 17, 25, 15);
				totalRotation = 0.f;
				rotatingFace = 0;
			}
			break;
		default:
			break;
		}
	}
}

void Rubixu3::RotateAll(glm::quat quat)
{
	modelMatrix = glm::toMat4(quat) * modelMatrix;
	Up = quat * Up;
	Down = quat * Down;
	Front = quat * Front;
	Back = quat * Back;
	Right = quat * Right;
	Left = quat * Left;
}

float Rubixu3::R()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int i = 2; i < 27; i += 3) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(rotation, 0, 0)), glm::vec3(-1, 0, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(2, 8, 26, 20, 5, 17, 23, 11);
	return rotation;
}

float Rubixu3::Ri()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int i = 2; i < 27; i += 3) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(rotation, 0, 0)), glm::vec3(1, 0, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(2, 20, 26, 8, 5, 11, 23, 17);
	return rotation;
}

float Rubixu3::L()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int i = 0; i < 27; i += 3) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(rotation, 0, 0)), glm::vec3(1, 0, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(6, 0, 18, 24, 3, 9, 21, 15);
	return rotation;
}

float Rubixu3::Li()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int i = 0; i < 27; i += 3) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(rotation, 0, 0)), glm::vec3(1, 0, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(6, 24, 18, 0, 3, 15, 21, 9);
	return rotation;
}

float Rubixu3::U()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int i = 0; i < 9; i++) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(0, rotation, 0)), glm::vec3(0, 1, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(6, 8, 2, 0, 7, 5, 1, 3);
	return rotation;
}

float Rubixu3::Ui()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int i = 0; i < 9; i++) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(0, rotation, 0)), glm::vec3(0, 1, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(6, 0, 2, 8, 7, 3, 1, 5);
	return rotation;
}

float Rubixu3::D()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int i = 18; i < 27; i++) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(0, rotation, 0)), glm::vec3(0, 1, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}
	
	//applyRotations(18, 20, 26, 24, 19, 23, 25, 21);
	return rotation;
}

float Rubixu3::Di()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int i = 18; i < 27; i++) {
		(*rotatedCubes)[i]->rotateAround(glm::quat(glm::vec3(0, rotation, 0)), glm::vec3(0, 1, 0));
		(*rotatedCubes)[i]->updateModelMatrix();
	}

	//applyRotations(18, 24, 26, 20, 19, 21, 25, 23);
	return rotation;
}

float Rubixu3::F()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int k = 0; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*rotatedCubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, rotation)), glm::vec3(0, 0, 1));
			(*rotatedCubes)[k + i]->updateModelMatrix();
		}
	}

	//applyRotations(0, 2, 20, 18, 1, 11, 19, 9);
	return rotation;
}

float Rubixu3::Fi()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int k = 0; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*rotatedCubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, rotation)), glm::vec3(0, 0, 1));
			(*rotatedCubes)[k + i]->updateModelMatrix();
		}
	}

	//applyRotations(0, 18, 20, 2, 1, 9, 19, 11);
	return rotation;
}

float Rubixu3::B()
{
	float rotation = glm::radians(90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(90.f) - totalRotation;
	for (int k = 6; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*rotatedCubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, rotation)), glm::vec3(0, 0, 1));
			(*rotatedCubes)[k + i]->updateModelMatrix();
		}
	}

	//applyRotations(8, 6, 24, 26, 7, 15, 25, 17);
	return rotation;
}

float Rubixu3::Bi()
{
	float rotation = glm::radians(-90.f) * rubixu->deltaTime * speed;
	if (glm::abs(totalRotation + rotation) > glm::radians(90.f))
		rotation = glm::radians(-90.f) - totalRotation;
	for (int k = 6; k < 27; k += 9) {
		for (int i = 0; i < 3; i++) {
			(*rotatedCubes)[k + i]->rotateAround(glm::quat(glm::vec3(0, 0, rotation)), glm::vec3(0, 0, 1));
			(*rotatedCubes)[k + i]->updateModelMatrix();
		}
	}
	
	//applyRotations(8, 26, 24, 6, 7, 17, 25, 15);
	return rotation;
}

void Rubixu3::applyRotations(int a, int b, int c, int d, int e, int f, int g, int h)
{
	Cube *temp1, *temp2;

	temp2 = (*rotatedCubes)[a];
	temp1 = (*rotatedCubes)[b];
	(*rotatedCubes)[b] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[c];
	(*rotatedCubes)[c] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[d];
	(*rotatedCubes)[d] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[a];
	(*rotatedCubes)[a] = temp2;

	temp2 = (*rotatedCubes)[e];
	temp1 = (*rotatedCubes)[f];
	(*rotatedCubes)[f] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[g];
	(*rotatedCubes)[g] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[h];
	(*rotatedCubes)[h] = temp2;
	temp2 = temp1;
	temp1 = (*rotatedCubes)[e];
	(*rotatedCubes)[e] = temp2;
}