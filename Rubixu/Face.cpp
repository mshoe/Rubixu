#include "Face.h"

Face::Face(glm::vec3 translation, glm::quat rotation, glm::vec3 color, float size)
{
	vertices = new std::vector<glm::vec3>(4 * 2);
	(*vertices)[0] = glm::vec3(+size / 2, 0, -size / 2);
	(*vertices)[1] = glm::vec3(color.x, color.y, color.z);
	(*vertices)[2] = glm::vec3(-size / 2, 0, -size / 2);
	(*vertices)[3] = glm::vec3(color.x, color.y, color.z);
	(*vertices)[4] = glm::vec3(-size / 2, 0, +size / 2);
	(*vertices)[5] = glm::vec3(color.x, color.y, color.z);
	(*vertices)[6] = glm::vec3(+size / 2, 0, +size / 2);
	(*vertices)[7] = glm::vec3(color.x, color.y, color.z);

	translationMatrix = glm::translate(translationMatrix, translation);
	rotationMatrix = glm::toMat4(rotation);
	scaleMatrix = glm::scale(scaleMatrix, glm::vec3(size, size, size));

	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
}

Face::~Face()
{
	delete vertices;
}

void Face::rotate(glm::quat rotation)
{
	rotationMatrix = glm::toMat4(rotation);
}

void Face::translate(glm::vec3 translation)
{
	translationMatrix = glm::translate(translationMatrix, translation);
}

void Face::scale(float scale)
{
	scaleMatrix = glm::scale(scaleMatrix, glm::vec3(scale, scale, scale));
}

void Face::updateVertices()
{
	modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;

	glm::vec4 v0 = glm::vec4((*vertices)[0], 1.f);
	glm::vec4 v1 = glm::vec4((*vertices)[2], 1.f);
	glm::vec4 v2 = glm::vec4((*vertices)[4], 1.f);
	glm::vec4 v3 = glm::vec4((*vertices)[6], 1.f);
	v0 = modelMatrix * v0;
	v1 = modelMatrix * v1;
	v2 = modelMatrix * v2;
	v3 = modelMatrix * v3;
	(*vertices)[0] = glm::vec3(v0);
	(*vertices)[2] = glm::vec3(v1);
	(*vertices)[4] = glm::vec3(v2);
	(*vertices)[6] = glm::vec3(v3);
}
