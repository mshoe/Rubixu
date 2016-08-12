#include "RenderEngine.h"

RenderEngine::RenderEngine(Rubixu *rubixu)
{
	this->rubixu = rubixu;
	Init();
}

RenderEngine::~RenderEngine()
{
	CleanUp();

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void RenderEngine::Init()
{
	CleanUp();

	rubixu3 = rubixu->rubixu3;

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	rubixuShader = new Shader("..\\Rubixu\\Shaders\\shader.vs", "..\\Rubixu\\Shaders\\shader.frag");

	(*rubixuShader).Use();
	RenderRubixu();
	
	model = new glm::mat4;
	camera = new Camera(glm::vec3(0.0f, 0.0f, 10.0f));

	rotate3(45.f, 1.f, 1.f, 0.f);
}

void RenderEngine::CleanUp()
{
	if (rubixuShader != NULL) {
		Shader *temp = rubixuShader;
		delete temp;
	}
	if (model != NULL) {
		glm::mat4 *temp = model;
		delete temp;
	}
	if (camera != NULL) {
		Camera *temp = camera;
		delete temp;
	}
}

void RenderEngine::rotate3(float angle, float x, float y, float z)
{
	*model = glm::rotate(*model, glm::radians(angle), glm::vec3(x, y, z));
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
	// 3 values (xyz) per vertice, 3 values (rgb) per color, 2 values for texture
	/*std::vector<GLfloat> vertices(4 * 6 * 3 + 4 * 6 * 3 + 4 * 6 * 2);*/

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

	//Cube cube(glm::vec3(0, 0, 0), glm::quat(glm::vec3(glm::radians(45.f), glm::radians(45.f), 0)), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 1), 1, glm::vec3(1, 0, 0), 2, 1.f);

	
	//rubixu3->L();
	rubixu3->U();
	rubixu3->R();

	std::vector<GLfloat> vertices(4 * 3 * 2 * 6 * 27);
	for (int i = 0; i < 27; i++) {
		std::vector<GLfloat> temp = (*(rubixu3->cubes))[i]->outputVertices();
		for (int j = 0; j < 4 * 3 * 2 * 6; j++) {
			vertices[i * 4 * 3 * 2 * 6 + j] = /*(*((*(rubixu3->cubes))[i]->vertices))*/temp[j];
		}
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, (vertices).size() * sizeof(GLfloat), &vertices.front(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices.front(), GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// Texture attribute
	/*glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);*/

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

	//delete rubixu3;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	std::cout << "...complete" << std::endl;
	
	/*glm::quat test;
	std::cout << test.x << test.y << test.z << test.w;*/

	/*glm::quat myQuaternion;
	myQuaternion = glm::quat(glm::vec3(0, 0, 0));
	std::cout << myQuaternion.x << myQuaternion.y << myQuaternion.z << myQuaternion.w;*/
}

void RenderEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	(*rubixuShader).Use();

	float angle = rubixu->deltaTime * 45.f;
	rotate3(angle, 0.f, 1.f, 0.f);

	

	// model
	GLuint modelLoc = glGetUniformLocation((*rubixuShader).Program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(*model));

	// view
	GLuint viewLoc = glGetUniformLocation((*rubixuShader).Program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	// perspective
	glm::mat4 projection = glm::perspective(camera->Zoom, (float)rubixu->image_width / (float)rubixu->image_height, 0.1f, 100.0f);
	GLuint projectionLoc = glGetUniformLocation((*rubixuShader).Program, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 4 * 3 * 2 * 6 * 27, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	SDL_GL_SwapWindow(rubixu->mainWindow);
}