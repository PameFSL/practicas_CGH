#include "Window.h"

//****** para cambiar posicion **********
float fovy = 0.0f;
float fovy2 = 0.0f;
float fovy3 = -2.5f;
//************************************
Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{ //detecta las teclas que manejamos 
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
	mainWindow = glfwCreateWindow(width, height, "practica_3", NULL, NULL);

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
	//************************************
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
	glfwSetWindowUserPointer(mainWindow, this); //identificar si el usuario esta en la ventana correcta al momento de presionar teclas 
}

void Window::createCallbacks()
{
	//
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	//identificar que ventana esta abierta
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	
	/* INTRUCCIONES PARA EL MANEJO DE LAS TECLAS 
			Teclas para mover la camara 
			A: Mueve a la izquierda
			D: Mueve a la derecha
			W: Mueve hacia abajo
			S: Mueve hacia arriba*/

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
			fovy += 0.3;
			break;
		case GLFW_KEY_R:
			key_name = glfwGetKeyName(GLFW_KEY_R, 0);
			printf("se presiono la tecla: %s, %d\n", key_name);
			break;
		case GLFW_KEY_W:
			fovy2 += 0.3;
			break;
		case GLFW_KEY_A:
			fovy -= 0.3;
			break;
		case GLFW_KEY_S:
			fovy2 -= 0.3;
			break;

		}
	}
	//***************
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			//mostro la tecla que presiono de forma alfanumerica 
			theWindow->keys[key] = true;
			printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			printf("se solto la tecla %d'\n", key);
		}
	}
}
float Window::regresa_rx() {
	return fovy;
}
float Window::regresa_ry() {
	return fovy2;
}
float Window::regresa_rz() {
	return fovy3;
}
Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
