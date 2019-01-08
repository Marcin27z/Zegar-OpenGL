#include "tower.h"
#include "shprogram.h"

void Tower::genVertices()
{
	// A (bottom)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 0
	vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 1
	vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 2
	// B (bottom)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 3
	vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 4
	vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 5

	// C (top)
	vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 6
	vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 7
	vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 8
	// D (top)
	vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 9
	vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 10
	vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 11

	// E (left)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 12
	vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 13
	vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 14
	// F (left)
	vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 15
	vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 16
	vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 17

	// G (right)
	vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 18
	vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 19
	vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 20
	// H (right)
	vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 21
	vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 22
	vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 23

	// I (front)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 24 
	vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 25
	vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 26
	// J (front)
	vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 27
	vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 28
	vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 29

	// K (back)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 30
	vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 31
	vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 32
	// L (back)
	vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 33
	vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 34
	vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 35
}

void Tower::genTextures()
{
	// A (bottom)
	textures.push_back(glm::vec2(0.2500f, 0.3333f));
	textures.push_back(glm::vec2(0.2500f, 0.6667f));
	textures.push_back(glm::vec2(0.5000f, 0.6667f));
	// B (bottom)
	textures.push_back(glm::vec2(0.2500f, 0.3333f));
	textures.push_back(glm::vec2(0.5000f, 0.6667f));
	textures.push_back(glm::vec2(0.5000f, 0.3333f));

	// C (top)
	
	// D (top)
	

	// E (left)
	
	// F (left)
	

	// G (right)
	
	// H (right)
	

	// I (front)
	
	// J (front)
	

	// K (back)
	
	// L (back)
	for (int i = 0; textures.size() < vertices.size(); i++)
	{
		textures.push_back(glm::vec2(0, 0));
		//std::cout << ">" << textures.size() << std::endl;
	}
}

void Tower::genIndices()
{
	for (int i = 0; i < vertices.size(); i++)
		indices.push_back(i);
}

void Tower::genNormals()
{
	for(int i = 0; i < vertices.size(); i++)
		normals.push_back(glm::vec4(0, 0, 0, 1));
}



Tower::Tower(float width = 1.0f, float height = 1.0f, float depth = 1.0f)
{
	genVertices();
	genIndices();
	genTextures();
	genNormals();
	for (int i = 0; i < vertices.size(); i++)
		colors.push_back(glm::vec3(0, 0, 1.0));
	scale(width, height, depth);
	texture = loadMipmapTexture(GL_TEXTURE0, "Textures\\tower_r.png");
}


Tower::~Tower()
{
}

void Tower::draw(const ShaderProgram& shader)
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
