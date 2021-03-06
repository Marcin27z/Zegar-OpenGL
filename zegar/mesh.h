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
	virtual void genVertices() = 0;
	virtual void genIndices() = 0;
	GLuint VBO, EBO, VAO;
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> colors;
	std::vector<glm::vec2> textures;
	std::vector<glm::vec4> normals;
	std::vector<GLuint> indices;
	GLuint texture;
	void assign(Mesh&);
public:
	Mesh();
	~Mesh();
	void scale(float, float, float);
	void scale(float, float, float, float, float, float);
	void draw();
	void setColor(float, float, float);
	void move(float, float, float);
	void rotate(float, float, float);
	void rotate(float, float, float, float, float, float);
	void loadTexture(const char* name);
	void setNormals();
	GLuint loadMipmapTexture(GLuint texId, const char* fname);
};