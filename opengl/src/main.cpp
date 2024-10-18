#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <memory>

const int WindowWidth = 800;
const int WindowHeight = 800;

const char* vertex_shader = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
)";

const char* fragment_shader = R"(
#version 330 core
out vec4 FragColor;

void main(){
	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";

const char* fragment_shader1 = R"(
#version 330 core
out vec4 FragColor;

void main(){
	FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
}
)";


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(WindowWidth, WindowHeight, "LearnOpenGL", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}



	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	GLuint fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragment_shader1, NULL);
	glCompileShader(fragmentShader1);

	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	unsigned int shaderProgram, shaderProgram1;
	shaderProgram = glCreateProgram();
	shaderProgram1 = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}


	float vertices[] = {
		-sqrt(3) / 2, -0.5f, 0.0f, // left
		 sqrt(3) / 2, -0.5f, 0.0f, // right
		 0.0f,  1.0f, 0.0f,  // top
	};
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(fragmentShader1);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glViewport(0, 0, WindowWidth, WindowHeight);

	float theta = 3.1415926 / 2;
	float theta_1 = 3.1415926 / 6;
	float scale = 0.6;
	int weight = 1;
	int color = 1;

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		theta -= 0.01f;
		theta_1 -= 0.01f;
		scale += 0.003f * weight;
		if (scale >= 0.6f)
			weight = -1;
		if (scale <= 0.4f)
			weight = 1;
		vertices[0] = cos(theta) * scale;
		vertices[1] = sin(theta) * scale;
		vertices[3] = cos(theta + 3.1415926 * 2 / 3) * scale;
		vertices[4] = sin(theta + 3.1415926 * 2 / 3) * scale;
		vertices[6] = cos(theta + 3.1415926 * 4 / 3) * scale;
		vertices[7] = sin(theta + 3.1415926 * 4 / 3) * scale;

		float vertices_1[] = {
			cos(theta_1) * (1 - scale), sin(theta_1) * (1 - scale), 0.0f, // right
			cos(theta_1 + 3.1415926 * 2 / 3) * (1 - scale), sin(theta_1 + 3.1415926 * 2 / 3) * (1 - scale), 0.0f, // left
			cos(theta_1 + 3.1415926 * 4 / 3) * (1 - scale), sin(theta_1 + 3.1415926 * 4 / 3) * (1 - scale), 0.0f,  // top
		};
		GLuint VAO_1, VBO_1;
		glGenVertexArrays(1, &VAO_1);
		glGenBuffers(1, &VBO_1);
		glBindVertexArray(VAO_1);

		glUseProgram(shaderProgram1);

		glBindBuffer(GL_ARRAY_BUFFER, VBO_1);
		if (color == 1)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
			glUseProgram(shaderProgram1);
		}
		else
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			glUseProgram(shaderProgram);
		}
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		


		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		if (color == 1)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			glUseProgram(shaderProgram);
		}
		else
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
			glUseProgram(shaderProgram1);
		}
		glBindVertexArray(VAO);
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		if (weight == 1)
			color = 1;
		else
			color = 0;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate();
    return 0;
}