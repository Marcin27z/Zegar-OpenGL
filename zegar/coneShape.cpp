#include "coneShape.h"
//Cone to create two cones with up-dowm movement in a clock
ConeShape::ConeShape(float width, float height, float depth)
{
	genVertices();
	genIndices();
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

ConeShape::ConeShape() {}

ConeShape::~ConeShape() {}

void ConeShape::genVertices() {
	vertices.push_back(glm::vec4(0.0f, 0.7f, 0.0f, 1.0f)); // 0: up
	vertices.push_back(glm::vec4(-0.3f, 0.0f, 0.3f, 1.0f)); // 1: front left
	vertices.push_back(glm::vec4(0.3f, 0.0f, 0.3f, 1.0f)); // 2: front right
	vertices.push_back(glm::vec4(0.3f, 0.0f, -0.3f, 1.0f)); // 3: back right
	vertices.push_back(glm::vec4(-0.3f, 0.0f, -0.3f, 1.0f)); // 4: back left
	vertices.push_back(glm::vec4(0.0f, -0.7f, 0.0f, 1.0f)); // 5: down

	setNormals();
}

void ConeShape::genIndices() {
	indices = {
		0, 1, 2,
		0, 1, 4,
		0, 4, 3,
		0, 3, 2,
		1, 2, 5,
		1, 4, 5,
		4, 3, 5,
		3, 2, 5
	};
}

ConeShape& ConeShape::operator=(ConeShape other) {
	assign(other);
	return *this;
}