#include "RenderEngine.h"

RenderEngine::RenderEngine(Rubixu *rubixu)
{
	this->rubixu = rubixu;
	Init();
}

RenderEngine::~RenderEngine()
{
	CleanUp();
}

void RenderEngine::Init()
{
	CleanUp();

	rubixu3 = rubixu->rubixu3;
	camera = new Camera(glm::vec3(5.0f, 5.0f, 10.0f));
	camera->ProcessMouseMovement(-100, -100);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	rubixuShader = new Shader("..\\Rubixu\\Shaders\\shader.vs", "..\\Rubixu\\Shaders\\shader.frag");

	(*rubixuShader).Use();
	RenderRubixu();
	
	//rotate3(45.f, 1.f, 1.f, 0.f);
}

void RenderEngine::CleanUp()
{
	if (rubixuShader != NULL) {
		Shader *temp = rubixuShader;
		delete temp;
	}
	if (camera != NULL) {
		Camera *temp = camera;
		delete temp;
	}
}

glm::mat4 RenderEngine::rotate3(glm::mat4 model, float angle, float x, float y, float z)
{
	model = glm::rotate(model, glm::radians(angle), glm::vec3(x, y, z));
	return model;
}

void RenderEngine::zoom(GLfloat zoom_value)
{
	camera->Zoom += zoom_value;
}

void RenderEngine::moveCameraPosition(Camera_Movement direction, GLfloat deltaTime)
{
	camera->ProcessKeyboard(direction, deltaTime);
}

void RenderEngine::moveCameraDirection(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
	camera->ProcessMouseMovement(xoffset, yoffset, constrainPitch);
}

void RenderEngine::RenderRubixu()
{
	std::cout << "rendering rubixu..." << std::endl;

	// 4 vertices per face, 6 faces per cube
	// 3 values (xyz) per vertice, 3 values (rgb) per color

	// 6 faces per cube
	
	std::vector<GLuint> indices(6 * 6 * 27);
	for (int i = 0; i < 6 * 27; i++) {
		indices[i * 6 + 0] = i * 4 + 0;
		indices[i * 6 + 1] = i * 4 + 1;
		indices[i * 6 + 2] = i * 4 + 3;
		indices[i * 6 + 3] = i * 4 + 1;
		indices[i * 6 + 4] = i * 4 + 2;
		indices[i * 6 + 5] = i * 4 + 3;
	}

	std::vector<GLfloat> vertices(4 * 3 * 2 * 6 * 27);
	for (int i = 0; i < 27; i++) {
		std::vector<GLfloat> temp = (*rubixu3->cubes)[i]->outputVertices();
		for (int j = 0; j < 4 * 3 * 2 * 6; j++)
			vertices[i * 4 * 3 * 2 * 6 + j] = temp[j];
	}

	GLuint VAO, VBO, EBO;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	std::cout << "test 2" << std::endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	std::cout << "test 3" << std::endl;
	glBindVertexArray(VAO);

	std::cout << "test 4" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	std::cout << "test 4.5" << std::endl;
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices.front(), GL_STATIC_DRAW);
	std::cout << "test 5" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices.front(), GL_STATIC_DRAW);
	std::cout << "test 6" << std::endl;
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	std::cout << "test 7" << std::endl;
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	std::cout << "test 8" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	std::cout << "test 9" << std::endl;
		
	glBindVertexArray(0);
	/*glDeleteVertexArrays(1, &VAO);*/
	/*glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);*/

	/*glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);*/

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	//glBindVertexArray(VAO);

	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, (vertices).size() * sizeof(GLfloat), &vertices.front(), GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices.front(), GL_STATIC_DRAW);

	//// Position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	//glEnableVertexAttribArray(0);

	//// Color attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	//glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	//glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	std::cout << "...complete" << std::endl;
}

void RenderEngine::Render()
{
	//RenderRubixu();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	(*rubixuShader).Use();

	float angle = rubixu->deltaTime * 45.f;
	/*rotate3(angle, 0.f, 1.f, 0.f);*/

	// view
	GLuint viewLoc = glGetUniformLocation((*rubixuShader).Program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	// perspective
	glm::mat4 projection = glm::perspective(camera->Zoom, (float)rubixu->image_width / (float)rubixu->image_height, 0.1f, 100.0f);
	GLuint projectionLoc = glGetUniformLocation((*rubixuShader).Program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// model
	//glm::mat4 model;
	GLuint modelCubeLoc = glGetUniformLocation((*rubixuShader).Program, "modelCube");
	GLuint modelRubixuLoc = glGetUniformLocation((*rubixuShader).Program, "modelRubixu");

	//modelMatrix = rotate3(modelMatrix, angle, 0.f, 1.f, 0.f);

	//glUniformMatrix4fv(modelRubixuLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	for (int i = 0; i < 27; i++) {
		//(*rubixu3->cubes)[i]->modelMatrix = rotate3((*rubixu3->cubes)[i]->modelMatrix, angle, 0.f, 1.f, 0.f);
		//(*rubixu3->cubes)[i]->rotateAround(glm::quat(glm::vec3(0, glm::radians(45.f * rubixu->deltaTime), 0)), glm::vec3(0, 0, 0));
		//(*rubixu3->cubes)[i]->updateModelMatrix();
		glUniformMatrix4fv(modelCubeLoc, 1, GL_FALSE, glm::value_ptr(/*(*rubixu3->cubes)[0]->modelMatrix*/(*rubixu3->cubes)[i]->modelMatrix));
		
		
		glBindVertexArray(1);
		glDrawElementsBaseVertex(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0, i * 4 * 3 * 2);
		//TIL: second parameter is indices (elements), 4th parameter is vertex data (xyzrgb)

		//glDrawElements(GL_TRIANGLES, 4 * 3 * 2 * 6 * 27, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
	
	SDL_GL_SwapWindow(rubixu->mainWindow);
}