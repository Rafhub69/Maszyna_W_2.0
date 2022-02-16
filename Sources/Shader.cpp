#include "Shader.h"
#include <sstream>

struct Shader::ShaderProgramSource
{
	string VertexSource;
	string FragmentSource;
};

	unsigned int Shader::compileShader(unsigned int type, const string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result = 0;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int lenght = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &result);
			char* message = (char*)alloca(lenght * sizeof(char));
			glGetShaderInfoLog(id, lenght, &lenght, message);
			std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment " ) << "\n";
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	unsigned int Shader::createShader(const string& vertexShader, const string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	Shader::ShaderProgramSource Shader::parseShader(const string& filepath)
	{
		std::ifstream stream(filepath);

		enum class shaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		string line;
		std::stringstream ss[2];
		shaderType type = shaderType::NONE;

		while (getline(stream, line))
		{
			if (line.find("#shader") != string::npos)
			{
				if (line.find("vertex") != string::npos)
				{
					type = shaderType::VERTEX;
				} 
				else if (line.find("fragment") != string::npos)
				{
					type = shaderType::FRAGMENT;
				}
				
			} else
			 {
				ss[(int)type] << line << '\n';
			 }
		}

		return {ss[0].str(), ss[1].str() };
	}

	Shader::Shader(const string& filepath)
		:filepath(filepath), m_RendererID(0)
	{
		ShaderProgramSource source = parseShader(filepath);
		m_RendererID = createShader(source.VertexSource, source.FragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetUniform4f(const string& name, float value0, float value1, float value2, float value3)
	{
		glUniform4f(getUniformLocation(name), value0, value1, value2, value3);
	}

	int Shader::getUniformLocation(const string& name)
	{
		return glGetUniformLocation(m_RendererID, name.c_str());
	}
