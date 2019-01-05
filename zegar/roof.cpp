#include "roof.h"
#include "shprogram.h"

void Roof::genVertices()
{
	vertices.push_back(glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, -0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, 0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.0f, 0.0f, 0.5f, 1.0f));
}

void Roof::genIndices()
{
	indices = {
		0, 1, 3, // BOTTOM
		1, 2, 3, // BOTTOM

		0, 1, 4, // FRONT

		1, 2, 4, // RIGHT

		2, 3, 4, // BACK

		3, 0, 4, // LEFT
	};
}

void Roof::genNormals()
{
	for (int i = 0; i < sizeof(indices); i += 3)
	{
		//glm::vec3 a();
		//glm::vec3 b();
		//glm::vec3 c();
		//glm::vec3 normal = glm::normalize(glm::cross(b - a, c - a));
	}
	
	normals.push_back(glm::vec4(0, 0, 0, 1));
	normals.push_back(glm::vec4(0, 0, 0, 1));
	normals.push_back(glm::vec4(0, 0, 0, 1));
	normals.push_back(glm::vec4(0, 0, 0, 1));
	normals.push_back(glm::vec4(0, 0, 0, 1));
}

void Roof::genTextures()
{
	textures.push_back(glm::vec2(0.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(0.5f, 0.5f));
}

Roof::Roof(float width = 1.0f, float height = 1.0f, float depth = 1.0f)
{
	genVertices();
	genIndices();
	genTextures();
	genNormals();
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	scale(width, height, depth);
	texture = loadMipmapTexture(GL_TEXTURE0, "Textures\\roof.png");
}

void Roof::draw(const ShaderProgram& shader)
{
	shader.Use();

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
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(shader.get_programID(), "Texture0"), 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

Roof::~Roof()
{
}
