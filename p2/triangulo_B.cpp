#include <stdio.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader, colorBuffer, VBO1;

//Vertex Shader

static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
layout (location =1) in vec4 colorFigure;           \n\
out vec4 vColor;                                    \n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
vColor = colorFigure  ;                              \n\
} ";

static const char* fShader = "						\n\
#version 330		                                \n\
in vec4 vColor;                                     \n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vColor;                          	    \n\
}";



void CrearTriangulo()
{
	GLfloat vertices[] = {
		-0.9f, 0.9f, 0.0f,
		-0.8f, 0.9f, 0.0f,
		-0.8, 0.1f, 0.0f,
		-0.9f, 0.9f, 0.0f,
		-0.8, 0.1f, 0.0f,
		-0.9f, 0.1f, 0.0f,
		-0.8f, 0.9f, 0.0f,
		-0.6f, 0.9f, 0.0f,
		-0.8f, 0.8f, 0.0f,
		-0.6f, 0.9f, 0.0f,
		-0.6f, 0.8f, 0.0f,
		-0.8f, 0.8f, 0.0f,
		-0.8f, 0.2f, 0.0f,
		-0.6f, 0.2f, 0.0f,
		-0.6f, 0.1f, 0.0f,
		-0.8f, 0.2f, 0.0f,
		-0.6f, 0.1f, 0.0f,
		-0.8f, 0.1f, 0.0f, //C
		-0.25f, 0.9f, 0.0f,
		-0.25f, 0.6f, 0.0f,
		-0.4f, 0.1f, 0.0f,
		-0.25f, 0.9f, 0.0f,
		-0.5f, 0.1f, 0.0f,
		-0.4f, 0.1f, 0.0f,
		-0.25f, 0.9f, 0.0f,
		-0.25f, 0.6f, 0.0f,
		-0.1f, 0.1f, 0.0f,
		-0.25f, 0.9f, 0.0f,
		0.0f, 0.1f, 0.0f,
		-0.1f, 0.1f, 0.0f,
		-0.3277f, 0.3407f, 0.0f,
		-0.1722f, 0.3407f, 0.0f,
		-0.1454f, 0.2513f, 0.0f,
		-0.3277f, 0.3407f, 0.0f,
		-0.3548f, 0.2513f, 0.0f,
		-0.1454f, 0.2513f, 0.0f, //A
		-1.0f + 1.05f, 0.9f, 0.0f,
		-0.9f + 1.05f, 0.1f, 0.0f,
		-1.0f + 1.05f, 0.1f, 0.0f,
		-1.0f + 1.05f, 0.9f, 0.0f,
		-0.9f + 1.05f, 0.9f, 0.0f,
		-0.9f + 1.05f, 0.1f, 0.0f,
		-0.9f + 1.05f, 0.6f, 0.0f,
		-0.7f + 1.05f, 0.6f, 0.0f,
		-0.7f + 1.05f, 0.5f, 0.0f,
		-0.9f + 1.05f, 0.6f, 0.0f,
		-0.7f + 1.05f, 0.5f, 0.0f,
		-0.9f + 1.05f, 0.5f, 0.0f,
		-0.7f + 1.05f, 0.9f, 0.0f,
		-0.6f + 1.05f, 0.9f, 0.0f,
		-0.6f + 1.05f, 0.1f, 0.0f,
		-0.7f + 1.05f, 0.9f, 0.0f,
		-0.6f + 1.05f, 0.1f, 0.0f,
		-0.7f + 1.05f, 0.1f, 0.0f, //H
		-0.25f + 1.0f, 0.9f, 0.0f,
		-0.25f + 1.0f, 0.6f, 0.0f,
		-0.4f + 1.0f, 0.1f, 0.0f,
		-0.25f + 1.0f, 0.9f, 0.0f,
		-0.5f + 1.0f, 0.1f, 0.0f,
		-0.4f + 1.0f, 0.1f, 0.0f,
		-0.25f + 1.0f, 0.9f, 0.0f,
		-0.25f + 1.0f, 0.6f, 0.0f,
		-0.1f + 1.0f, 0.1f, 0.0f,
		-0.25f + 1.0f, 0.9f, 0.0f,
		 0.0f + 1.0f, 0.1f, 0.0f,
		-0.1f + 1.0f, 0.1f, 0.0f,
		-0.3277f + 1.0f, 0.3407f, 0.0f,
		-0.1722f + 1.0f, 0.3407f, 0.0f,
		-0.1454f + 1.0f, 0.2513f, 0.0f,
		-0.3277f + 1.0f, 0.3407f, 0.0f,
		-0.3548f + 1.0f, 0.2513f, 0.0f,
		-0.1454f + 1.0f, 0.2513f, 0.0f, //A
	};

	GLfloat colores[] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f, //C
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f,
		0.3921f, 1.0f, 0.8549f, 1.0f, //A
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f,
		0.8980f,0.2235f, 0.2078f, 1.0f, //H
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f,
		0.4f, 0.7333f, 0.4156f, 1.0f
	};

	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colores), colores, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(1);


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
	glShaderSource(theShader,1, theCode, codeLength);//Se le asigna al shader el c�digo
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevenci�n de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n",shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el c�digo a la tarjeta gr�fica
}

void CompileShaders() {
	shader= glCreateProgram(); //se crea un programa
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
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);

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
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES,0,72);
		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}


	return 0;
}