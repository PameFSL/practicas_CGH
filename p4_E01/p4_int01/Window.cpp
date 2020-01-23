#include "Window.h"
float ax = 0.0f;
float ay = 0.0f;
float az = 0.0f;

float ax1 = 0.0f;
float ay1 = 0.0f;
float az1 = 0.0f;

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
	//Inicializaci�n de GLFW
	if (!glfwInit())
	{
		printf("Fall� inicializar GLFW");
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
	//Obtener tama�o de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall� inicializaci�n de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas
							 
							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se est� usando la ventana
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
			ax += 0.3f;
			break;
		case GLFW_KEY_R:
			key_name = glfwGetKeyName(GLFW_KEY_R, 0);
			printf("se presiono la tecla: %s, %d\n", key_name);
			break;
		case GLFW_KEY_W:
			ay -= 0.3f;
			break;
		case GLFW_KEY_A:
			ax -= 0.3f;
			break;
		case GLFW_KEY_S:
			ay += 0.3f;
			break;
		case GLFW_KEY_Z:
			az += 0.3f;
			break;
		case GLFW_KEY_X:
			az -= 0.3f;
			break;

		case GLFW_KEY_O:
			ay -= 0.3f;
			break;
		case GLFW_KEY_K:
			ax -= 0.3f;
			break;
		case GLFW_KEY_P:
			ax += 0.3f;
			break;
		case GLFW_KEY_L:
			ay += 0.3f;
			break;
		case GLFW_KEY_N:
			az += 0.3f;
			break;
		case GLFW_KEY_M:
			az -= 0.3f;
			break;
		}
	}
}

float Window::regresa_ax() {
	return ax;
}
float Window::regresa_ay() {
	return ay;
}
float Window::regresa_az() {
	return az;
}
//********
float Window::regresa_ax1() {
	return ax1;
}
float Window::regresa_ay1() {
	return ay1;
}
float Window::regresa_az1() {
	return az1;
}
Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
