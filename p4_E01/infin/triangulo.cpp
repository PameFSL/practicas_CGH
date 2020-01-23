#include <stdio.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, shader; //Enteros que los detecte OpenGl

//Vertex Shader
//version de ahsder a utilizar, se declara un layout, vec3 con la posicion, cada shader tiene void main, gl_Position dibuja de acuerdo a VAO VBO los vertices y los renderiza
//Fragment shader color y sombreado a lo que esta en Vertex Shader dibujado en base a vértices
//vSahder in recibe
//fShader  out saca

static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
}";

static const char* fShader = "						\n\
#version 330										\n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vec4(1.0f,0.0f,0.0f,1.0f);	 			\n\
}";



void CrearTriangulo()
{
	//Vertices del triángulo
	/*GLfloat vertices[] = {
		-1.0f, -1.0f,0.0f,
		1.0f,-1.0f, 0.0f,
		0.0f,1.0f,0.0f
	};*/
	/*GLfloat vertices[] = {
		-1.0f,-1.0f,0.0f,
		-1.0f,1.0f,0.0f,
		1.0f,1.0f,0.0f,
		-1.0f,1.0f,0.0f,
		-1.0f,-1.0f,0.0f,
		1.0f,-1.0f,0.0f
	};*/

	GLfloat vertices[] = {
		//Letra I
		-0.95f,0.25f,0.0f,
		-0.65f,0.35f,0.0f,
		-0.65f,0.25f,0.0f,
		-0.95f,0.35f,0.0f,
		-0.65f,0.35f,0.0f,
		-0.95f,0.25f,0.0f,
		-0.95f,-0.25f,0.0f,
		-0.65f,-0.35f,0.0f,
		-0.65f,-0.25f,0.0f,
		-0.95f,-0.35f,0.0f,
		-0.65f,-0.35f,0.0f,
		-0.95f,-0.25f,0.0f,
		-0.85f,0.25f,0.0f,
		-0.85f,-0.25f,0.0f,
		-0.75f,-0.25f,0.0f,
		-0.85f,0.25f,0.0f,
		-0.75f,0.25f,0.0f,
		-0.75f,-0.25f,0.0f,
		//Letra M

	};
	
	glGenVertexArrays(1, &VAO); //generar 1 VAO crea el arreglo
	glBindVertexArray(VAO);//asignar VAO asigna al arreglo los valores

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es estático pues no se modificarán los valores
		//gl_static_draw sirve para indicar que es un objeto estático
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
		//Empieza desde el vertice 0 y cada tres los va procesando
		//Gl_false todos los valores los maneje como posiciones
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0); //Manda a la tarjeta los datos
		glBindVertexArray(0); //Manda a la tarjeta los datos

}
void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Función para agregar los shaders a la tarjeta gráfica
//the Program recibe los datos de theShader
//shadertype vertex o fragment shader


{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader,1, theCode, codeLength);//Se le asigna al shader el código, se asigna el codigo ala tarjeta gráfica
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevención de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n",shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el código a la tarjeta gráfica
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
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gráfica
	 //verificaciones y prevención de errores
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
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);

 //Crear tríangulo
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

		//Llama al shader y lo usa 
		glUseProgram(shader);

		//Desde la localidad 0 va recorriendo cada 3
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES,0,19);
		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}


	return 0;
}