#include "roof.h"

void Roof::genVertices()
{
	vertices.push_back(glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, -0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, 0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f));
	vertices.push_back(glm::vec4(0.0f, 0.0f, 0.5f, 1.0f));

	setNormals();
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

Roof::~Roof()
{
}
