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
		0,3,1,
		1,3,2,
		2,3,0,
		0,1,2,
		// segunda piramide
		//2,4,0,
	};
	//segunda fila
	GLfloat vertices[] = {
		-1.0f, 1.0f,0.0f,  //A
		0.0f,0.47f,1.65f,    //k
		-2.0f,0.42f, 1.63f,   //I
		-1.46f,-0.92f,0.0f   //H
	}; GLfloat vertices1[] = {
		-1.0f, 1.0f,0.0f,  //A
		-1.46f,-0.92f,0.0f   //H
		-2.89f,0.43f,0.0f    //E
		-2.0f,0.42f, 1.63f,   //I
	};
	 GLfloat vertices2[] = {
	1.0f,1.0f,0.0f,    //J
	0.0f,0.43f, 1.64f,   //k
	-1.0f, 1.0f,0.0f,  //A
	0.0f,-0.73f,0.0f   //L
};
	 //parte baja
	 //azul
	 GLfloat vertices3[] = {
	0.0f, 1.64f,-1.61f,  //G
	1.0f,1.0f,0.0f,    //J
	-1.0f, 1.0f,0.0f,  //A
	0.0f,-0.31f,-1.14f   //M
	 };

	 //parte baja
	 GLfloat vertices4[] = {
	0.0f, 1.64f,-1.61f,  //G
	-1.0f, 1.0f,0.0f,  //A
	-2.0f,1.64f,-1.61f,    //N
	0.0f,-0.31f,-1.14f   //M
	 };

	 //*********revisar verde*************
	 GLfloat vertices5[] = {
	-2.0f,1.64f,-1.61f,    //N
	-1.0f, -1.0f,0.0f,  //A
	-2.89f,0.43f,0.0f    //E
	-2.0f,-0.3,-1.14f,    //O
	 };
	 GLfloat vertices6[] = {
	-2.0f,1.64f,-1.61f,  //N
	-3.0f,1.0f,0.0f ,   //E
   -4.0f,1.6f,-1.63f,    //P
	-2.96f, -0.11f,-1.66f,  //G
	 };
	 GLfloat vertices7[] = {
	0.0f,0.47f,1.65f,  //K
	-1.0f,-0.13f,3.27f,    //U
   -2.0f,0.42f,1.63f,    //I
	-0.96f, -1.29f,1.64f,  //T
	 };
	 GLfloat vertices8[] = {
	2.0f,1.61f,-1.61f,  //S
	1.0f,1.0f,0.0f,    //J
   0.98f,-0.11f,-1.67f,    //N
	0.0f, 1.64f,-1.61f,  //G
	 };
	
	//Instancia de la piramide
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);
	Mesh *obj2 = new Mesh();
	obj2->CreateMesh(vertices1, indices, 12, 12);
	meshList.push_back(obj2);
	Mesh *obj3 = new Mesh();
	obj3->CreateMesh(vertices2, indices, 12, 12);
	meshList.push_back(obj3);
	Mesh *obj4 = new Mesh();

	//parte inferior
	obj4->CreateMesh(vertices3, indices, 12, 12);
	meshList.push_back(obj4);
	Mesh *obj5 = new Mesh();
	obj5->CreateMesh(vertices4, indices, 12, 12);
	meshList.push_back(obj5);

	//************
	Mesh *obj6 = new Mesh();
	obj6->CreateMesh(vertices5, indices, 12, 12);
	meshList.push_back(obj6);
	Mesh *obj7 = new Mesh();
	obj7->CreateMesh(vertices6, indices, 12, 12);
	meshList.push_back(obj7);
	Mesh *obj8 = new Mesh();
	obj8->CreateMesh(vertices7, indices, 12, 12);
	meshList.push_back(obj8);
	Mesh *obj9 = new Mesh();
	obj9->CreateMesh(vertices8, indices, 12, 12);
	meshList.push_back(obj9);
	/**/
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
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	//glm::mat4 projection = glm::ortho(-1, 1, -1, 1, 1, 10);
	//glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		glm::mat4 view = mainWindow.regresa_vista();
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLoaction();
		uniformProjection = shaderList[0].getProjectLocation();
		uniformView = shaderList[0].getViewLocation();
		uniformColor = shaderList[0].getColorLocation();
		glm::mat4 model(1.0);
		glm::vec3 currentColor = glm::vec3(0.0f, 0.0f, 1.0f);
	
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));

		meshList[0]->RenderMesh();

		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(0.0f,1.0f,0.0f);
		//ejercicio 1: repetir instancias del cubo o cuadrados para replicar una figura
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		//meshList[1]->RenderMesh();
		
		
		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(0.0f, 1.0f, 1.0f);
		
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[2]->RenderMesh();
		

		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(1.0f, 0.0f, 0.0f);
		
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[3]->RenderMesh();

		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(1.0f, 0.0f, 1.0f);
		
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[4]->RenderMesh();

		//segundo nivel
		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(1.0f, 0.4f, 0.0f);
		
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[5]->RenderMesh();

		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(0.4f, 1.0f, 1.0f);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[6]->RenderMesh();

		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(0.0f, 1.0f, 0.3f);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[7]->RenderMesh();

		//tercer nivel
		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad
		currentColor = glm::vec3(0.3f, 1.0f, 0.0f);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[8]->RenderMesh();

		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}