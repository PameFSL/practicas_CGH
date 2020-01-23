#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al c�digo
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
		0,3,1,
		1,3,2,
		2,3,0,
		0,1,2
	};
	GLfloat vertices[] = {
		-0.5f, -0.5f,0.5f,
		0.0f,-0.5f,0.5f,
		0.5f,-0.5f, 0.0f,
		0.0f,0.5f,0.0f
	};
	Mesh *obj1 = new Mesh();
	//podemos creae mas obj 
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);

	//********* creamos otra cara **********
	Mesh *obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj2);

	//********* creamos otra cara **********
	Mesh *obj3 = new Mesh();
	obj3->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj3);
	//********* creamos otra cara **********
	Mesh *obj4 = new Mesh();
	obj4->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj4);
	//********* creamos otra cara **********
	Mesh *obj5 = new Mesh();
	obj5->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj5);
	//********* creamos otra cara **********
	Mesh *obj6 = new Mesh();
	obj6->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj6);

	//********* creamos otra cara **********
	Mesh *obj7 = new Mesh();
	obj7->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj7);
	//********* creamos otra cara **********
	Mesh *obj8 = new Mesh();
	obj8->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj8);
	//********* creamos otra cara **********
	Mesh *obj9 = new Mesh();
	obj9->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj9);

}
//ejercicio 1 para hacer en clase, el cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	// back
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);

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

	//*** para el color ************
	GLuint uniformcolor = 0;
	float c1 = 0.3f;
	float c2 = 0.3f;
	float c3 = 0.3f;
	glm::vec3 color_t = glm::vec3(c1, c1, c3);

	//model es lo que afecta a los vertices, matriz de vista de modelo
	//glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	// proyeccion en 2 dimenciones 
	glm::mat4 projection = glm::ortho(-1, 1, -1, 1, 1, 10);  //solo en proyecciones planos 
	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLoaction();
		uniformProjection = shaderList[0].getProjectLocation();
		uniformView = shaderList[0].getViewLocation();
		uniformcolor = shaderList[0].getColorLocation();
		//********inicializa con 1 unidad 

		glm::mat4 model(1.0);
		model = glm::mat4(1.0);

		// primer triangulo
		model = glm::translate(model, glm::vec3(0.0f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformcolor, 1, glm::value_ptr(color_t));
		meshList[0]->RenderMesh();

		//***************************************
		//creamos los diferentes triangulos 

		//HACIA ABAJO
		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.15f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model,  180* toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		c3 += 0.5f;
		//************** color *******************************
		glm::vec3 color_t = glm::vec3(c1, c1, c3);
		glUniform3fv(uniformcolor, 1, glm::value_ptr(color_t));
		meshList[1]->RenderMesh();

		

		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.15f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[2]->RenderMesh();

		//HACIA ARRIBA
		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.3f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[3]->RenderMesh();


		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.3f, -0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[4]->RenderMesh();

		//HACIA ARRIBA
		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.15f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[5]->RenderMesh();
		//HACIA ARRIBA
		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.15f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[6]->RenderMesh();

		//HACIA ABAJO
//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
		//model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, -1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[7]->RenderMesh();


		//HACIA ARRIBA
		//glm::mat4 model(1.0);
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.3f, -1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		model = glm::rotate(model, 180 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		meshList[8]->RenderMesh();

		//ejercicio 1: repetir instancias del cubo o cuadrados para replicar una figura
		
		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}