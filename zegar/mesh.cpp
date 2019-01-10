#include "mesh.h"

Mesh::Mesh() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Mesh::draw() {
	auto verticesIterator = vertices.begin();
	auto colorsIterator = colors.begin();
	auto normalsIterator = normals.begin();
	auto texturesIterator = textures.begin();
	GLfloat* tempVertices = new GLfloat[vertices.size() * 3 + colors.size() * 3 + normals.size() * 3 + textures.size() * 2];
	for (auto i = 0; i < vertices.size(); i++) {
		tempVertices[i * 11] = (*verticesIterator).x;
		tempVertices[i * 11 + 1] = (*verticesIterator).y;
		tempVertices[i * 11 + 2] = (*verticesIterator).z;
		tempVertices[i * 11 + 3] = (*colorsIterator).x;
		tempVertices[i * 11 + 4] = (*colorsIterator).y;
		tempVertices[i * 11 + 5] = (*colorsIterator).z;
		tempVertices[i * 11 + 6] = (*texturesIterator).x;
		tempVertices[i * 11 + 7] = (*texturesIterator).y;
		tempVertices[i * 11 + 8] = (*normalsIterator).x;
		tempVertices[i * 11 + 9] = (*normalsIterator).y;
		tempVertices[i * 11 + 10] = (*normalsIterator).z;
		++verticesIterator;
		++colorsIterator;
		++normalsIterator;
		++texturesIterator;
	}

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * 11 * sizeof(GLfloat), tempVertices, GL_STATIC_DRAW);

	delete[] tempVertices;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	GLuint* tempIndices = new GLuint[indices.size()];
	std::copy(indices.begin(), indices.end(), tempIndices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), tempIndices, GL_STATIC_DRAW);

	delete[] tempIndices;

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex color data
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// vertex texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// vertex normal coordinates
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// prepare textures

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void Mesh::setColor(float r, float g, float b) {
	for (auto && color : colors) {
		color = glm::vec3(r, g, b);
	}
}

void Mesh::scale(float xScale, float yScale, float zScale) {
	scale(xScale, yScale, zScale, positionX, positionY, positionZ);
}

void Mesh::scale(float xScale, float yScale, float zScale, float xPivot, float yPivot, float zPivot) {
	width *= xScale;
	height *= yScale;
	depth *= zScale;
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(xScale, yScale, zScale));
	for (auto && vertex : vertices) {
		vertex = scale * vertex;
	}
}

void Mesh::move(float xMove, float yMove, float zMove) {
	positionX += xMove;
	positionY += yMove;
	positionZ += zMove;
	glm::mat4 move = glm::translate(glm::mat4(1.0f), glm::vec3(xMove, yMove, zMove));
	for (auto && vertex : vertices) {
		vertex = move * vertex;
	}
}

void Mesh::rotate(float xAngle, float yAngle, float zAngle) {
	rotate(xAngle, yAngle, zAngle, positionX, positionY, positionZ);
}

void Mesh::rotate(float xAngle, float yAngle, float zAngle, float xPivot, float yPivot, float zPivot) {
	using glm::mat4;
	using glm::vec3;
	glm::mat4 moveCenter = glm::translate(glm::mat4(1.0f), glm::vec3(-xPivot, -yPivot, -zPivot));
	glm::mat4 moveBack = glm::translate(glm::mat4(1.0f), glm::vec3(xPivot, yPivot, zPivot));
	glm::mat4 rotateX = glm::rotate(glm::mat4(1.0f), glm::radians(xAngle), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotateY = glm::rotate(glm::mat4(1.0f), glm::radians(yAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotateZ = glm::rotate(glm::mat4(1.0f), glm::radians(zAngle), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 rotate = moveBack * rotateX * rotateY * rotateZ * moveCenter;
	for (auto && vertex : vertices) {
		vertex = rotate * vertex;
	}
	for (auto && normal : normals) {
		normal = rotate * normal;
	}
}

GLuint Mesh::loadMipmapTexture(GLuint texId, const char* fname) {
	int width, height;
	unsigned char* image = SOIL_load_image(fname, &width, &height, 0, SOIL_LOAD_RGB);
	if (image == nullptr)
		throw std::exception("Failed to load texture file");

	GLuint texture;
	glGenTextures(1, &texture);

	glActiveTexture(texId);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}

void Mesh::setNormals() {
	for (int i = 0; i < vertices.size(); i++) {
		normals.push_back(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	}

	for (int i = 0; i < indices.size() / 3; i++) {
		int a = indices[i * 3];
		int b = indices[i * 3 + 1];
		int c = indices[i * 3 + 2];

		glm::vec3 vecA = glm::vec3(vertices[a].x, vertices[a].y, vertices[a].z);
		glm::vec3 vecB = glm::vec3(vertices[b].x, vertices[b].y, vertices[b].z);
		glm::vec3 vecC = glm::vec3(vertices[c].x, vertices[c].y, vertices[c].z);
		glm::vec3 faceVector = glm::cross(vecC - vecA, vecB - vecA);

		normals[a] = glm::vec4(faceVector, 1.0f);
		vertices[b] = glm::vec4(faceVector, 1.0f);
		vertices[c] = glm::vec4(faceVector, 1.0f);
	}

	for (int i = 0; i < vertices.size(); i++) {
		normals[i] = glm::normalize(vertices[i]);
	}
}

void Mesh::assign(Mesh &other) {
	positionX = other.positionX;
	positionY = other.positionY;
	positionZ = other.positionZ;
	width = other.width;
	height = other.height;
	depth = other.depth;
	VBO = other.VBO;
	VAO = other.VAO;
	EBO = other.EBO;
	vertices = other.vertices;
	colors = other.colors;
	indices = other.indices;
	textures = other.textures;
	normals = other.normals;
	texture = other.texture;
}

