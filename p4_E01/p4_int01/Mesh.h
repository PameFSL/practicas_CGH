#pragma once
#include<glew.h>
class Mesh
{
public:
	Mesh();
	void CreateMesh(GLfloat *vertices,unsigned int *indices, unsigned int numOfVertices, unsigned int numberOfIndices, GLfloat *color, unsigned int tam_color);
	void RenderMesh();
	void ClearMesh();
	~Mesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;

};

