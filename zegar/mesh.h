#pragma once
#include <SOIL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>
#include "node.h"

class Mesh : public Node {
protected:
	void scale(float, float, float);
	virtual void genVertices() = 0;
	virtual void genIndices() = 0;
	GLuint VBO, EBO, VAO;
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec2> textures; //to be used later
	std::vector<GLuint> indices;
	GLuint texture; //to be used later
public:
	Mesh();
	~Mesh();
	void draw();
	void setColor(float, float, float);
	void move(float, float, float);
	void rotate(float, float, float);
	void rotate(float, float, float, float, float, float);
	GLuint loadMipmapTexture(GLuint texId, const char* fname); //to be used later
};