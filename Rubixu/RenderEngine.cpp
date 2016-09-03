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
	light = rubixu->light;
	camera = new Camera(glm::vec3(0.0f, 0.0f, 10.0f));

	//modelMatrix = glm::mat4(1.f);

	//camera->ProcessMouseMovement(-100, -100);
	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	rubixuShader = new Shader("..\\Rubixu\\Shaders\\lighting.vs", "..\\Rubixu\\Shaders\\lighting.frag");
	lampShader = new Shader("..\\Rubixu\\Shaders\\lamp.vs", "..\\Rubixu\\Shaders\\lamp.frag");

	//(*rubixuShader).Use();
	RenderRubixu();

	
	
	//rotate3(45.f, 1.f, 1.f, 0.f);
}

void RenderEngine::CleanUp()
{
	if (rubixuShader != NULL) {
		Shader *temp = rubixuShader;
		delete temp;
	}
	if (lampShader != NULL) {
		Shader *temp = lampShader;
		delete temp;
	}
	if (camera != NULL) {
		Camera *temp = camera;
		delete temp;
	}
}

void RenderEngine::rotate3(glm::quat quat)
{
	modelMatrix = glm::toMat4(quat) * modelMatrix;
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

	// position = 0, normal = 1, color = 2
	std::vector<GLfloat> vertices(4 * 3 * 3 * 6 * 27);
	for (int i = 0; i < 27; i++) {
		std::vector<GLfloat> temp = (*rubixu3->cubes)[i]->outputVertices();
		/*for (int j = 0; j < 4 * 3 * 3 * 6; j++)
			vertices[i * 4 * 3 * 3 * 6 + j] = temp[j];*/
		for (int j = 0; j < 6; j++) {
			// calculate the normal of the face
			glm::vec3 a(
				temp[j * 4 * 3 * 2 + 0], 
				temp[j * 4 * 3 * 2 + 1], 
				temp[j * 4 * 3 * 2 + 2]
			);

			glm::vec3 b(
				temp[j * 4 * 3 * 2 + 6 + 0], 
				temp[j * 4 * 3 * 2 + 6 + 1], 
				temp[j * 4 * 3 * 2 + 6 + 2]
			);

			glm::vec3 c(
				temp[j * 4 * 3 * 2 + 12 + 0],
				temp[j * 4 * 3 * 2 + 12 + 1],
				temp[j * 4 * 3 * 2 + 12 + 2]
			);

			glm::vec3 normal = /*glm::normalize*/(glm::cross(c - a, b - a));

			for (int k = 0; k < 4; k++) {
				// insert them and other vertex attributes into vertices
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 0] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 0];
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 1] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 1];
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 2] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 2];
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 3] = normal.x;
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 4] = normal.y;
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 5] = normal.z;
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 6] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 3];
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 7] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 4];
				vertices[i * 4 * 3 * 3 * 6 + j * 4 * 3 * 3 + k * 3 * 3 + 8] = temp[j * 4 * 3 * 2 + k * 3 * 2 + 5];
			}
		}
	}

	GLuint VBO, EBO;
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices.front(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices.front(), GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Color attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
		
	glBindVertexArray(0);
	
	std::cout << "light source..." << std::endl;
	std::vector<GLfloat> lightVert(4 * 3 * 2 * 6);
	lightVert = light->outputVertices();

	//std::cout << lightVert.size() << std::endl;

	std::vector<GLuint> lightIndices(6 * 6);
	for (int i = 0; i < 6; i++) {
		lightIndices[i * 6 + 0] = i * 4 + 0;
		lightIndices[i * 6 + 1] = i * 4 + 1;
		lightIndices[i * 6 + 2] = i * 4 + 3;
		lightIndices[i * 6 + 3] = i * 4 + 1;
		lightIndices[i * 6 + 4] = i * 4 + 2;
		lightIndices[i * 6 + 5] = i * 4 + 3;
	}

	GLuint lightVBO, lightEBO;
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &lightVBO);
	glDeleteBuffers(1, &lightEBO);
	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO);
	glGenBuffers(1, &lightEBO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, lightVert.size() * sizeof(GLfloat), &lightVert.front(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, lightIndices.size() * sizeof(GLuint), &lightIndices.front(), GL_STATIC_DRAW);

	// Set the vertex attributes (only position data for our lamp)
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); 

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	std::cout << "...complete" << std::endl;
}

void RenderEngine::Render()
{
	//RenderRubixu();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*light->translation.x = 4 * glm::cos(0.2f * rubixu->totalTime);
	light->translation.z = 4 * glm::sin(0.2f * rubixu->totalTime);
	light->updateModelMatrix();*/

	float angle = rubixu->deltaTime * glm::radians(45.f);

	//rotate3(glm::quat(glm::vec3(0, angle, 0)));
	//camera->rotateAround(glm::quat(glm::vec3(angle, 0, 0)), glm::vec3(0,0,0));

	rubixuShader->Use();
	GLint lightColorLoc = glGetUniformLocation(rubixuShader->Program, "lightColor");
	glUniform3f(lightColorLoc, rubixu->light->color0[0], rubixu->light->color0[1], rubixu->light->color0[2]);
	//glUniform3f(lightColorLoc, 1.f, 1.f, 1.f);

	// view
	GLuint viewLoc = glGetUniformLocation((*rubixuShader).Program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	// perspective
	glm::mat4 projection = glm::perspective(camera->Zoom, (float)rubixu->image_width / (float)rubixu->image_height, 0.1f, 100.0f);
	GLuint projectionLoc = glGetUniformLocation((*rubixuShader).Program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// model
	GLuint modelLoc = glGetUniformLocation((*rubixuShader).Program, "model");

	// world lamp coordinates
	glm::vec3 lightPos = rubixu->light->translation;
	GLint lightPosLoc = glGetUniformLocation(rubixuShader->Program, "lightPos");
	glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

	// world camera coordinates
	GLint viewPosLoc = glGetUniformLocation(rubixuShader->Program, "viewPos");
	glUniform3f(viewPosLoc, camera->Position.x, camera->Position.y, camera->Position.z);

	for (int i = 0; i < 27; i++) {
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(rubixu3->modelMatrix * (*rubixu3->cubes)[i]->modelMatrix));
		
		glBindVertexArray(VAO);
		glDrawElementsBaseVertex(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0, i * 4 * 6);
		//TIL: second parameter is indices count, 5th parameter is offset in elements

		glBindVertexArray(0);
	}

	// LAMP

	lampShader->Use();

	// view
	viewLoc = glGetUniformLocation((*lampShader).Program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	// perspective
	projectionLoc = glGetUniformLocation((*lampShader).Program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// model
	modelLoc = glGetUniformLocation((*lampShader).Program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(rubixu->light->modelMatrix));
	
	glBindVertexArray(lightVAO);
	glDrawElementsBaseVertex(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(0);

	SDL_GL_SwapWindow(rubixu->mainWindow);
}