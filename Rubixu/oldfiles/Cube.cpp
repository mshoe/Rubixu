#include "Cube.h"

Cube::Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, float scale)
{
	// Figure out where the colors go
	initColor(color1, face1);

	// Make the vertices
	initVertices();

	// Apply the transformations
	Transform(translation, rotation, scale);
}

Cube::Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, float scale)
{
	initColor(color1, face1);
	initColor(color2, face2);
	initVertices();
	Transform(translation, rotation, scale);
}

Cube::Cube(glm::vec3 translation, glm::quat rotation, glm::vec3 color1, int face1, glm::vec3 color2, int face2, glm::vec3 color3, int face3, float scale)
{
	initColor(color1, face1);
	initColor(color2, face2);
	initColor(color3, face3);
	initVertices();
	Transform(translation, rotation, scale);
}

Cube::~Cube()
{
	CleanUp();
}

void Cube::initVertices()
{
	CleanUp();
	vertices = new std::vector<GLfloat>(4 * 3 * 2 * 6);

	// TOP

	//0
	(*vertices)[0] = -0.5f;
	(*vertices)[1] = +0.5f;
	(*vertices)[2] = +0.5f;
	(*vertices)[3] = color0.x;
	(*vertices)[4] = color0.y;
	(*vertices)[5] = color0.z;

	//1
	(*vertices)[6] = -0.5f;
	(*vertices)[7] = +0.5f;
	(*vertices)[8] = -0.5f;
	(*vertices)[9] = color0.x;
	(*vertices)[10] = color0.y;
	(*vertices)[11] = color0.z;

	//2
	(*vertices)[12] = +0.5f;
	(*vertices)[13] = +0.5f;
	(*vertices)[14] = -0.5f;
	(*vertices)[15] = color0.x;
	(*vertices)[16] = color0.y;
	(*vertices)[17] = color0.z;

	//3
	(*vertices)[18] = +0.5f;
	(*vertices)[19] = +0.5f;
	(*vertices)[20] = +0.5f;
	(*vertices)[21] = color0.x;
	(*vertices)[22] = color0.y;
	(*vertices)[23] = color0.z;

	// FRONT

	//0
	(*vertices)[24] = -0.5f;
	(*vertices)[25] = -0.5f;
	(*vertices)[26] = +0.5f;
	(*vertices)[27] = color1.x;
	(*vertices)[28] = color1.y;
	(*vertices)[29] = color1.z;

	//1
	(*vertices)[30] = -0.5f;
	(*vertices)[31] = +0.5f;
	(*vertices)[32] = +0.5f;
	(*vertices)[33] = color1.x;
	(*vertices)[34] = color1.y;
	(*vertices)[35] = color1.z;

	//2
	(*vertices)[36] = +0.5f;
	(*vertices)[37] = +0.5f;
	(*vertices)[38] = +0.5f;
	(*vertices)[39] = color1.x;
	(*vertices)[40] = color1.y;
	(*vertices)[41] = color1.z;

	//3
	(*vertices)[42] = +0.5f;
	(*vertices)[43] = -0.5f;
	(*vertices)[44] = +0.5f;
	(*vertices)[45] = color1.x;
	(*vertices)[46] = color1.y;
	(*vertices)[47] = color1.z;

	// LEFT

	//0
	(*vertices)[48] = -0.5f;
	(*vertices)[49] = -0.5f;
	(*vertices)[50] = -0.5f;
	(*vertices)[51] = color2.x;
	(*vertices)[52] = color2.y;
	(*vertices)[53] = color2.z;

	//1
	(*vertices)[54] = -0.5f;
	(*vertices)[55] = +0.5f;
	(*vertices)[56] = -0.5f;
	(*vertices)[57] = color2.x;
	(*vertices)[58] = color2.y;
	(*vertices)[59] = color2.z;

	//2
	(*vertices)[60] = -0.5f;
	(*vertices)[61] = +0.5f;
	(*vertices)[62] = +0.5f;
	(*vertices)[63] = color2.x;
	(*vertices)[64] = color2.y;
	(*vertices)[65] = color2.z;

	//3
	(*vertices)[66] = -0.5f;
	(*vertices)[67] = -0.5f;
	(*vertices)[68] = +0.5f;
	(*vertices)[69] = color2.x;
	(*vertices)[70] = color2.y;
	(*vertices)[71] = color2.z;

	// BACK

	//0
	(*vertices)[72] = +0.5f;
	(*vertices)[73] = -0.5f;
	(*vertices)[74] = -0.5f;
	(*vertices)[75] = color3.x;
	(*vertices)[76] = color3.y;
	(*vertices)[77] = color3.z;

	//1
	(*vertices)[78] = +0.5f;
	(*vertices)[79] = +0.5f;
	(*vertices)[80] = -0.5f;
	(*vertices)[81] = color3.x;
	(*vertices)[82] = color3.y;
	(*vertices)[83] = color3.z;

	//2
	(*vertices)[84] = -0.5f;
	(*vertices)[85] = +0.5f;
	(*vertices)[86] = -0.5f;
	(*vertices)[87] = color3.x;
	(*vertices)[88] = color3.y;
	(*vertices)[89] = color3.z;

	//3
	(*vertices)[90] = -0.5f;
	(*vertices)[91] = -0.5f;
	(*vertices)[92] = -0.5f;
	(*vertices)[93] = color3.x;
	(*vertices)[94] = color3.y;
	(*vertices)[95] = color3.z;

	// RIGHT

	//0
	(*vertices)[96] = +0.5f;
	(*vertices)[97] = -0.5f;
	(*vertices)[98] = +0.5f;
	(*vertices)[99] = color4.x;
	(*vertices)[100] = color4.y;
	(*vertices)[101] = color4.z;

	//1
	(*vertices)[102] = +0.5f;
	(*vertices)[103] = +0.5f;
	(*vertices)[104] = +0.5f;
	(*vertices)[105] = color4.x;
	(*vertices)[106] = color4.y;
	(*vertices)[107] = color4.z;

	//2
	(*vertices)[108] = +0.5f;
	(*vertices)[109] = +0.5f;
	(*vertices)[110] = -0.5f;
	(*vertices)[111] = color4.x;
	(*vertices)[112] = color4.y;
	(*vertices)[113] = color4.z;

	//3
	(*vertices)[114] = +0.5f;
	(*vertices)[115] = -0.5f;
	(*vertices)[116] = -0.5f;
	(*vertices)[117] = color4.x;
	(*vertices)[118] = color4.y;
	(*vertices)[119] = color4.z;

	// BOTTOM

	//0
	(*vertices)[120] = -0.5f;
	(*vertices)[121] = -0.5f;
	(*vertices)[122] = -0.5f;
	(*vertices)[123] = color5.x;
	(*vertices)[124] = color5.y;
	(*vertices)[125] = color5.z;

	//1
	(*vertices)[126] = -0.5f;
	(*vertices)[127] = -0.5f;
	(*vertices)[128] = +0.5f;
	(*vertices)[129] = color5.x;
	(*vertices)[130] = color5.y;
	(*vertices)[131] = color5.z;

	//2
	(*vertices)[132] = +0.5f;
	(*vertices)[133] = -0.5f;
	(*vertices)[134] = +0.5f;
	(*vertices)[135] = color5.x;
	(*vertices)[136] = color5.y;
	(*vertices)[137] = color5.z;

	//3
	(*vertices)[138] = +0.5f;
	(*vertices)[139] = -0.5f;
	(*vertices)[140] = -0.5f;
	(*vertices)[141] = color5.x;
	(*vertices)[142] = color5.y;
	(*vertices)[143] = color5.z;
}

void Cube::initColor(glm::vec3 color, int face)
{
	switch (face) {
	case FACE_WHITE:
		color0 = color;
		break;
	case FACE_BLUE:
		color1 = color;
		break;
	case FACE_RED:
		color2 = color;
		break;
	case FACE_GREEN:
		color3 = color;
		break;
	case FACE_ORANGE:
		color4 = color;
		break;
	case FACE_YELLOW:
		color5 = color;
		break;
	default:
		break;
	}
}

void Cube::CleanUp()
{
	if (vertices != NULL)
		delete vertices;
}

void Cube::Transform(glm::vec3 translation, glm::quat rotation, float scale)
{
	this->translation += translation;
	translationMatrix = glm::translate(translationMatrix, translation);
	this->rotation = rotation * this->rotation;
	rotationMatrix = glm::toMat4(this->rotation);
	this->scale *= scale;
	scaleMatrix = glm::scale(scaleMatrix, glm::vec3(scale, scale, scale));
	//updateVertices();
}

void Cube::Translate(glm::vec3 translation)
{
	this->translation += translation;
	translationMatrix = glm::translate(translationMatrix, translation);
	//updateVertices();
}

void Cube::Rotate(glm::quat rotation)
{
	this->rotation = rotation * this->rotation;
	rotationMatrix = glm::toMat4(this->rotation);
}

void Cube::Scale(float scale)
{
	this->scale *= scale;
	scaleMatrix = glm::scale(scaleMatrix, glm::vec3(scale, scale, scale));
}

void Cube::rotateAround(glm::quat rotation, glm::vec3 point)
{
	glm::vec3 temp = translation;
	glm::vec3 temp2 = temp - point;
	temp2 = rotation * temp2;
	temp = point + temp2;
	Translate(-translation);
	Translate(temp);
	Rotate(rotation);
}

std::vector<GLfloat> Cube::outputVertices()
{
	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;

	std::vector<GLfloat> temp_vertices(4 * 3 * 2 * 6);

	for (int i = 0; i < 24; i++) {
		glm::vec4 test(
			(*vertices)[i * 3 * 2 + 0],
			(*vertices)[i * 3 * 2 + 1],
			(*vertices)[i * 3 * 2 + 2],
			1.f
		);
		test = modelMatrix * test;
		temp_vertices[i * 3 * 2 + 0] = test.x;
		temp_vertices[i * 3 * 2 + 1] = test.y;
		temp_vertices[i * 3 * 2 + 2] = test.z;
		temp_vertices[i * 3 * 2 + 3] = (*vertices)[i * 3 * 2 + 3];
		temp_vertices[i * 3 * 2 + 4] = (*vertices)[i * 3 * 2 + 4];
		temp_vertices[i * 3 * 2 + 5] = (*vertices)[i * 3 * 2 + 5];
	}

	return temp_vertices;
}
