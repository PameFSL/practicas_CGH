//Semestre 2015 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Lopez Tendero Rogelio*********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.2f, 0.0f, 0.2f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);	//matriz para indicar que lo siguiente es parte de modelo
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar

	//Para dibujar con la opcion de puntos
	//glPointSize(4);
	//glBegin(GL_POINTS); 

	//Para dibujar con la opcion lineas. Va uniendo dos puntos 
	glLineWidth(4.0);
	//glBegin(GL_LINES); 	

	//Dibuja el punto anterior con el actual
	//glBegin(GL_LINE_STRIP);

	//Dibuja los puntos y cierra la figura
	//glBegin(GL_LINE_LOOP);

	//TRIANGULOS
	//glBegin(GL_TRIANGLES);
	//glBegin(GL_TRIANGLE_STRIP);
	//glBegin(GL_TRIANGLE_FAN);

	//CUADRILATEROS
	//glBegin(GL_QUADS);

	//POLIGONOS
	//glBegin(GL_POLYGON);

		//Esto es una lista de vertices
	/*
		glColor3f(0.5,0.3,0.9);
		glVertex3f(0.0f,0.0f,-0.2f);

		glColor3f(0.0,0.8,0.1);
		glVertex3f(0.0f,3.0f,-0.2f);

		glColor3f(0.4,0.4,0.0);
		glVertex3f(4.0f,4.0f,-0.2f);

		glColor3f(0.0,0.0,1.0);
		glVertex3f(14.0f,0.0f,-0.2f);

		glColor3f(1.0,0.0,0.5);
		glVertex3f(2.0f,-2.0f,-0.2f);
		*/
		//glBegin(GL_LINE_LOOP);


		/*DIBUJANDO LA LETRA C*/
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(3.0f, 3.0f, -0.2f);
	glVertex3f(7.0f, 3.0f, -0.2f);
	glColor3f(0.9, 0.2, 0.0);
	glVertex3f(7.0f, 4.0f, -0.2f);
	glVertex3f(3.0f, 4.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(3.0f, 4.0f, -0.2f);
	glVertex3f(4.0f, 4.0f, -0.2f);
	glColor3f(0.0, 1, 0.0);
	glVertex3f(4.0f, 9.0f, -0.2f);
	glVertex3f(3.0f, 9.0f, -0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.6, 0.0);
	glVertex3f(3.0f, 9.0f, -0.2f);
	glVertex3f(7.0f, 9.0f, -0.2f);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(7.0f, 8.0f, -0.2f);
	glVertex3f(3.0f, 8.0f, -0.2f);
	glEnd();



	//DIBUJANDO LA LETRA R DE ROGELIO
	glBegin(GL_QUADS);
	glVertex3f(8.0f, 3.0f, -0.2f);
	glVertex3f(9.0f, 3.0f, -0.2f);
	glVertex3f(9.0f, 9.0f, -0.2f);
	glVertex3f(8.0f, 9.0f, -0.2f);

	glVertex3f(10.0f, 3.0f, -0.2f);
	glVertex3f(11.0f, 3.0f, -0.2f);
	glVertex3f(11.0f, 6.0f, -0.2f);
	glVertex3f(10.0f, 6.0f, -0.2f);

	glVertex3f(12.0f, 9.0f, -0.2f);
	glVertex3f(11.0f, 9.0f, -0.2f);
	glVertex3f(11.0f, 6.0f, -0.2f);
	glVertex3f(12.0f, 6.0f, -0.2f);

	glVertex3f(9.0f, 7.0f, -0.2f);
	glVertex3f(11.0f, 7.0f, -0.2f);
	glVertex3f(11.0f, 6.0f, -0.2f);
	glVertex3f(9.0f, 6.0f, -0.2f);

	glVertex3f(9.0f, 8.0f, -0.2f);
	glVertex3f(11.0f, 8.0f, -0.2f);
	glVertex3f(11.0f, 9.0f, -0.2f);
	glVertex3f(9.0f, 9.0f, -0.2f);
	glEnd();




	//CODIGO QUE GENERA UNA L de LOPEZ
	glBegin(GL_QUADS);
	glVertex3f(13.0f, 3.0f, -0.2f);
	glVertex3f(14.0f, 3.0f, -0.2f);
	glVertex3f(14.0f, 9.0f, -0.2f);
	glVertex3f(13.0f, 9.0f, -0.2f);

	glVertex3f(14.0f, 3.0f, -0.2f);
	glVertex3f(17.0f, 3.0f, -0.2f);
	glVertex3f(17.0f, 4.0f, -0.2f);
	glVertex3f(14.0f, 4.0f, -0.2f);

	glEnd();


	glFlush();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(0, 20, 0, 10, 0.1, 2); //Guarda los limites de la pantalla que se dibuja

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(500, 300);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;
}

