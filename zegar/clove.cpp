#include "clove.h"
//Clove in cog wheels
Clove::Clove(float width, float height, float depth)
{
	genVertices();
	genIndices();
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	for (int i = 0; i < colors.size(); i++) {
		textures.push_back(glm::vec2(-0.1f, -0.1f));
	}
	scale(width, height, depth);
	this->width = width;
	this->height = height;
	this->depth = depth;
}

Clove::Clove() {

}

Clove::~Clove()
{
}

void Clove::genVertices() {
	vertices.push_back(glm::vec4(-0.5f, 0.5f, -0.5f, 1.0f));
	vertices.push_back(glm::vec4(-0.5f, -0.5f, -0.5f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, -0.5f, -0.5f, 1.0f));
	vertices.push_back(glm::vec4(0.5f, 0.5f, -0.5f, 1.0f));
	vertices.push_back(glm::vec4(-0.15f, 0.15f, 0.5f, 1.0f));
	vertices.push_back(glm::vec4(-0.15f, -0.15f, 0.5f, 1.0f));
	vertices.push_back(glm::vec4(0.15f, -0.15f, 0.5f, 1.0f));
	vertices.push_back(glm::vec4(0.15f, 0.15f, 0.5f, 1.0f));

	setNormals();
}
void Clove::genIndices() {
	indices = {
		0, 1, 3,
		0, 3, 4,
		0, 4, 1,
		7, 4, 3,
		7, 4, 6,
		7, 3, 6,
		5, 4, 1,
		5, 6, 1,
		5, 4, 6,
		2, 6, 1,
		2, 3, 1,
		2, 3, 6

	};
}

Clove& Clove::operator=(Clove other) {
	assign(other);
	return *this;
}