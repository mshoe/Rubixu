#pragma once
#include "Classes.h"
#include "Rubixu.h"
#include "Rubixu3.h"
#include "Cube.h"
#include "TextEngine.h"
#include "Camera.h"
#include "Shader.h"

#include <GL/glew.h>
#include <GL/GL.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>

class RenderEngine
{
public:
	RenderEngine(Rubixu *rubixu);
	~RenderEngine();

	void Init();
	void CleanUp();

	// Camera
	void moveCameraPosition(Camera_Movement direction, GLfloat deltaTime);
	void moveCameraDirection(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch);
	void zoom(GLfloat zoom_value);

	// World
	glm::mat4 modelMatrix;
	void rotate3(glm::quat);

	// Cubes
	void RenderRubixu();
	void Render();

	Camera *camera = NULL;

private:
	Rubixu *rubixu = NULL;
	Rubixu3 *rubixu3 = NULL;
	Cube *light = NULL;
	//TextEngine *text = NULL;
	

	// Shaders
	Shader *rubixuShader = NULL;
	Shader *lampShader = NULL;

	// Vertex array
	GLuint VAO, lightVAO;
};