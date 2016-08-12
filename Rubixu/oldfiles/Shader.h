#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <GL/glew.h>

class Shader
{
public:
	GLuint Program;
	// Constructor generates the shader on the fly
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
	{
		this->Program = LoadShader(vertexPath, fragmentPath);
	}

	std::string readFile(const char *filePath) {
		std::string content;
		std::ifstream fileStream(filePath, std::ios::in);

		if (!fileStream.is_open()) {
			std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

	GLuint LoadShader(const char *vertexPath, const char *fragmentPath) {
		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Read shaders
		std::string vertShaderStr = readFile(vertexPath);
		std::string fragShaderStr = readFile(fragmentPath);
		const char *vertShaderSrc = vertShaderStr.c_str();
		const char *fragShaderSrc = fragShaderStr.c_str();

		GLint result = GL_FALSE;
		int logLength;

		// Compile vertex shader
		std::cout << "Compiling vertex shader." << std::endl;
		glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
		glCompileShader(vertShader);

		// Check vertex shader
		glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
		glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<GLchar> vertShaderError((logLength > 1) ? logLength : 1);
		glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
		std::cout << &vertShaderError[0] << std::endl;

		// Compile fragment shader
		std::cout << "Compiling fragment shader." << std::endl;
		glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
		glCompileShader(fragShader);

		// Check fragment shader
		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
		glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<GLchar>  fragShaderError((logLength > 1) ? logLength : 1);
		glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
		std::cout << &fragShaderError[0] << std::endl;

		std::cout << "Linking program" << std::endl;
		GLuint program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);

		glGetProgramiv(program, GL_LINK_STATUS, &result);
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> programError((logLength > 1) ? logLength : 1);
		glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
		std::cout << &programError[0] << std::endl;

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);

		return program;
	}

	// Uses the current shader
	void Use()
	{
		glUseProgram(this->Program);
	}
};

#endif