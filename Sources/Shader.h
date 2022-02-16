#pragma once
#include "Main.h"

class Shader
{
private:
	struct ShaderProgramSource;
	unsigned int m_RendererID;
	string filepath;

	int getUniformLocation(const string& name);
	ShaderProgramSource parseShader(const string& filepath);
	unsigned int compileShader(unsigned int type, const string& source);
	unsigned int createShader(const string& vertexShader, const string& fragmentShader);

public:
	Shader(const string& filepath);
	~Shader();

	void Bind();
	void Unbind();

	void SetUniform4f(const string& name, float value0, float value1, float value2, float value3);
}; 
