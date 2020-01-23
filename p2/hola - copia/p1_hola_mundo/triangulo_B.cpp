#include <stdio.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>

void cam_color();

//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader;
GLuint EBO;


//Vertex Shader

//********
//agregamos una variable llamada color_letr, la cual recibir� el color
static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
layout (location =1) in vec4 color_letr;			\n\
out vec4 color_V;									\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
color_V = color_letr;								\n\
}";
//color rosa 1.0f,0.0f,1.0f,1.0f)
//color azul  0.0f,0.7f,1.0f,1.0f) 
//color amarillo 1.0f,1.0f,0.0f,1.0f

static const char* fShader = "						\n\
#version 330		                                \n\
in vec4 color_V;                                    \n\
out vec4 col_letra;									\n\
void main()											\n\
{													\n\
	col_letra = color_V;                          	\n\
}";

void CrearTriangulo()
{
	GLfloat vertices[] = {
		//para la P
		-0.7f,0.53f, 0.0f,
		-0.59f,0.53f, 0.0f,
		-0.59f,-0.53f, 0.0f,

		-0.59f,-0.53f, 0.0f,
		-0.7f,-0.53f, 0.0f,
		-0.7f,0.53f, 0.0f,

		-0.59f, 0.15f,0.0f,
		-0.59f, 0.07f,0.0f,
		-0.37f,0.07f, 0.0f,

		-0.59f, 0.15f,0.0f,
		-0.37f,0.07f, 0.0f,
		-0.27f, 0.19f,0.0f,

		-0.41f, 0.16f,0.0f,
		-0.27f,0.19f, 0.0f,
		-0.28f, 0.45f,0.0f,

		-0.43f, 0.44f,0.0f,
		-0.28f,0.45f, 0.0f,
		-0.27f, 0.19f,0.0f,

		-0.6f, 0.43f,0.0f,
		-0.38f, 0.53f,0.0f,
		-0.28f,0.45f, 0.0f,

		-0.6f, 0.53f,0.0f,
		-0.6f, 0.43f,0.0f,
		-0.38f,0.53f, 0.0f,

		//para la S
		0.01f,0.53f, 0.0f,
		-0.07f,0.34f, 0.0f,
		0.18f,0.44f, 0.0f,  

		0.02f,0.38f, 0.0f,
		0.21f,0.3f, 0.0f,
		0.18f,0.45f, 0.0f,  

		-0.2f,0.4f, 0.0f,
		-0.07f,0.34f, 0.0f,
		0.01f,0.53f, 0.0f,

		-0.2f,0.4f, 0.0f,
		-0.07f,0.34f, 0.0f,
		-0.1f,0.18f, 0.0f,   //12

		-0.2f,0.4f, 0.0f,
		-0.19f,0.09f, 0.0f,
		-0.1f,0.18f, 0.0f,

		-0.19f,0.09f, 0.0f,
		0.2f,0.0f, 0.0f,
		-0.1f,0.18f, 0.0f,   //18

		-0.19f,0.09f, 0.0f,
		0.2f,0.0f, 0.0f,
		0.1f,-0.08f, 0.0f,

		0.1f,-0.08f, 0.0f,
		0.2f,0.0f, 0.0f,
		0.21f,-0.23f, 0.0f,   //24

		0.1f,-0.08f, 0.0f,
		0.21f,-0.23f, 0.0f,
		0.13f,-0.49f, 0.0f,  //27

		0.1f,-0.08f, 0.0f,
		0.13f,-0.49f, 0.0f,
		0.04f,-0.47f, 0.0f,   //30

		0.04f,-0.47f, 0.0f,
		0.06f,-0.35f, 0.0f,
		-0.15f,-0.38f, 0.0f,

		-0.24f,-0.34f, 0.0f,
		-0.19f,-0.48f, 0.0f,
		0.13f,-0.49f, 0.0f,    //36

		//para la F

		0.3f,0.5f, 0.0f,
		0.4f,0.5f, 0.0f,
		0.41f,-0.53f, 0.0f,

		0.41f,-0.53f, 0.0f,
		0.31f,-0.52f, 0.0f,
		0.3f,0.5f, 0.0f,

		0.7f,0.5f, 0.0f,
		0.7f,0.39f, 0.0f,
		0.4f,0.5f, 0.0f,

		0.4f,0.5f, 0.0f,
		0.4f,0.4f, 0.0f,
		0.7f,0.39f, 0.0f,

		0.4f,0.14f, 0.0f,
		0.59f,0.14f, 0.0f,
		0.59f,0.04f, 0.0f,

		0.59f,0.04f, 0.0f,
		0.4f,0.14f, 0.0f,
		0.4f,0.04f, 0.0f    //18
	};

	GLfloat color_letra[] = {
		//para la P
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,

		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,  
		
		//para la S
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,
		1.0f,1.0f,0.0f,1.0f,

		//para F

		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,

		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,

		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f,0.7f,1.0f,1.0f,
		0.0f, 0.7f, 1.0f, 1.0f,
		0.0f, 0.7f, 1.0f, 1.0f

	};

	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores
	//atributos de posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(0);
	//**************************************
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_letra), color_letra, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores
	//atributos de posicion
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(1);
	//**************************************

	// atributos de color 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Funci�n para agregar los shaders a la tarjeta gr�fica
//the Program recibe los datos de theShader


{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader, 1, theCode, codeLength);//Se le asigna al shader el c�digo
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevenci�n de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n", shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el c�digo a la tarjeta gr�fica
}


void CompileShaders() {
	shader = glCreateProgram(); //se crea un programa
	if (!shader)
	{
		printf("Error creando el shader");
		return;
	}
	AddShader(shader, vShader, GL_VERTEX_SHADER);//Agregar vertex shader
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);//Agregar fragment shader
	//Para terminar de linkear el programa y ver que no tengamos errores
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gr�fica
	 //verificaciones y prevenci�n de errores
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al linkear es: %s \n", eLog);
		return;
	}
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al validar es: %s \n", eLog);
		return;
	}



}


int main()
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
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 2", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tama�o de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall� inicializaci�n de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);

	//Crear tr�angulo
	CrearTriangulo();
	CompileShaders();


	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow))
	{
		//Recibir eventos del usuario
		glfwPollEvents();

		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 78);
		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}


	return 0;
}