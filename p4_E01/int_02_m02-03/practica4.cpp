#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al còdigo
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";

void CreateObject()
{
	unsigned int indices[] = {
		1,2,3,
		3,1,4,
		1,2,4,
		2,3,4
	};

	GLfloat vertices[] = {
		-1.0f, 1.0f,0,
		1.0f,1.0f,0.f,
		0.0f,-1.0f, 0.0f,
		0.0f,0.0f,1.73
	};
// creamos VAO's los cuales nos darán el color de cada vertice
	GLfloat color_triangulo[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.3f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
	};

	Mesh *obj1 = new Mesh();
	//podemos creae mas obj 
	obj1->CreateMesh(vertices, indices, 12, 12, color_triangulo, 16);
	meshList.push_back(obj1);
}

void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CreateObject();
	//CrearCubo();
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	GLuint uniformView = 0;
	glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
//	glm::mat4 projection = glm::ortho(-1, 1, -1, 1, 1, 10);

	//******************************************************
	//movemos la camara para ver todas las caras del triangulo

	//glm::mat4 view = glm::lookAt(glm::vec3(mainWindow.regresa_ax(), mainWindow.regresa_ay(), mainWindow.regresa_az()), glm::vec3(mainWindow.regresa_ax(), mainWindow.regresa_ay(), 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		
		//glm::mat4 view = glm::lookAt(glm::vec3(mainWindow.regresa_ax(), mainWindow.regresa_ay(), mainWindow.regresa_az()+0.5f), glm::vec3(mainWindow.regresa_ax(), mainWindow.regresa_ay(), 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 view = mainWindow.regresa_vista();
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLoaction();
		uniformProjection = shaderList[0].getProjectLocation();
		uniformView = shaderList[0].getViewLocation();
		//********inicializa con 1 unidad 

		glm::mat4 model(1.0);
		model = glm::mat4(1.0);

		// primer triangulo
		model = glm::translate(model, glm::vec3(0.0f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));

		//********** utilizamos los metodos de window para obtener las coordenadas *********
		//model = glm::translate(model, glm::vec3(mainWindow.regresa_ax1(), mainWindow.regresa_ay1(), mainWindow.regresa_az1()));
		model = glm::rotate(model, 90 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		meshList[0]->RenderMesh();
		//
		
		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}