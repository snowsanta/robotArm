#include "Shader.h"

Shader::Shader(const char* vshaderPath, const char* fshaderPath) {
	std::string sourceCode;
	GLint statusFlg;
	char infoLog[1024];
	GLuint vshader, fshader;

	// Compile Vertex shader
	sourceCode = loadSource(vshaderPath);
	const char* vShaderSource = sourceCode.c_str();
	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &vShaderSource, NULL);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &statusFlg);
	if (statusFlg != GL_TRUE)
	{
		glGetShaderInfoLog(vshader, 1024, NULL, infoLog);
		std::cout << "Vertex shader not compiled: "<< infoLog << std::endl;
	}

	// Compile Fragment shader
	sourceCode = loadSource(fshaderPath);
	const char* fShaderSource = sourceCode.c_str();
	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &fShaderSource, NULL);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &statusFlg);
	if (statusFlg != GL_TRUE)
	{
		glGetShaderInfoLog(fshader, 1024, NULL, infoLog);
		std::cout << "Fragment shader not compiled: " << infoLog << std::endl;
	}

	// link shaders
	program = glCreateProgram();
	glAttachShader(program, vshader);
	glAttachShader(program, fshader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &statusFlg);
	if (statusFlg != GL_TRUE)
	{
		glGetProgramInfoLog(program, 1024, NULL, infoLog);
		std::cout << "Shaders not linked: " << infoLog << std::endl;
	}

	// Delete shaders after linking
	glDeleteShader(vshader);
	glDeleteShader(fshader);

}

Shader::~Shader() {
	glDeleteProgram(program);
}

void Shader::Use() {
	glUseProgram(program);
}

void Shader::setUniform3(const char* location, glm::fvec3 value) {
	glUniform3fv(glGetUniformLocation(program, location), 1, glm::value_ptr(value));
}

void Shader::setUniform4(const char* location, glm::mat4 value){
	glUniformMatrix4fv(glGetUniformLocation(program, location), 1, GL_FALSE, glm::value_ptr(value));
}

std::string Shader::loadSource(const char* filepath) {
	std::fstream file(filepath);
	std::string source, temp;

	while (std::getline(file, temp)) {
		source += temp + "\n";
	}

	if (source.size() == 0) {
		std::cout << "Shader file not found or empty" <<  std::endl;
	}

	return source;
}

