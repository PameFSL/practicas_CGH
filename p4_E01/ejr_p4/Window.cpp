#include "Window.h"
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>

glm::vec3 pos_camara = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 camara_front = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 camara_up = glm::vec3(0.0f, 1.0f, 0.0f);
float az = 0.0f;

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Practica 4", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas

							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
}


void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (action == GLFW_PRESS) {
		const char* key_name;
		switch (key) {
		case GLFW_KEY_ESCAPE://indica que fue la tecla scape
			glfwSetWindowShouldClose(window, GL_TRUE); //hace salir de la ventana
			break;
		case GLFW_KEY_D:
			//muestra nombre de la tecla 
			key_name = glfwGetKeyName(GLFW_KEY_D, 0);
			printf("se presiono la tecla: %s, %d\n", key_name);
			pos_camara += glm::normalize(glm::cross(camara_front, camara_up))*0.3f;
			break;
		case GLFW_KEY_R:
			key_name = glfwGetKeyName(GLFW_KEY_R, 0);
			printf("se presiono la tecla: %s, %d\n", key_name);
			break;
		case GLFW_KEY_W:
			pos_camara += 0.3f*camara_front;
			break;
		case GLFW_KEY_A:
			pos_camara -= glm::normalize(glm::cross(camara_front, camara_up))*0.3f;
			break;
		case GLFW_KEY_S:
			pos_camara -= 0.3f*camara_front;
			break;
		case GLFW_KEY_Z:
			pos_camara -= glm::vec3(0.0f, 0.0f, 1.0f);
			break;
		case GLFW_KEY_X:
			pos_camara += glm::vec3(0.0f, 0.0f, 1.0f);
			break;
		case GLFW_KEY_Q:
			camara_front += glm::vec3(0.0f, 0.0f, -1.0f);
			pos_camara += glm::vec3(0.0f, 0.0f, -1.0f);
			camara_up += glm::vec3(0.0f, 0.0f, -1.0f);
			break;
		case GLFW_KEY_E:
			pos_camara += 0.3f*camara_up;
			break;
		case GLFW_KEY_T:
			pos_camara -= 0.3f*camara_up;
			break;
		}
	}
}

float Window::regresa_az() {
	return az;
}
glm::mat4 Window::regresa_vista()
{
	glm::mat4 vista = glm::lookAt(pos_camara, pos_camara + camara_front, camara_up);
	return vista;
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
