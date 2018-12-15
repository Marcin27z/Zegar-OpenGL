#include "ring.h"
#include "shprogram.h"

void Ring::genVertices() {
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(360.0f / float(n)), glm::vec3(0.0f, 0.0f, 1.0f));

	/* Upper ring outer circle vertices */
	glm::vec4 vectorOuterTop(0.0f, outerRadius, height / 2.0f, 1.0f);
	glm::vec4 transformedVectorOuterTop = vectorOuterTop;
	glm::vec4 normalOuterTop(0.0f, outerRadius + 0.1f, height / 2.0f + 0.1f, 1.0f);
	glm::vec4 transformedNormalOuterTop = normalOuterTop;
	vertices.push_back(vectorOuterTop);
	normals.push_back(normalOuterTop);
	textures.push_back(glm::vec2(-0.1f, -0.1f));
	for (int i = 1; i < n; ++i) {
		transformedVectorOuterTop = rotate * transformedVectorOuterTop;
		transformedNormalOuterTop = rotate * transformedNormalOuterTop;
		vertices.push_back(transformedVectorOuterTop);
		normals.push_back(transformedNormalOuterTop);
		textures.push_back(glm::vec2(-0.1f, -0.1f));
	}
	/* Upper ring inner circle vertices */
	glm::vec4 vectorInnerTop(0.0f, innerRadius, height / 2.0f, 1.0f);
	glm::vec4 transformedVectorInnerTop = vectorInnerTop;
	glm::vec4 normalInnerTop(0.0f, innerRadius - 0.1f, height / 2.0f + 0.1f, 1.0f);
	glm::vec4 transformedNormalInnerTop = normalInnerTop;
	vertices.push_back(vectorInnerTop);
	normals.push_back(normalInnerTop);
	textures.push_back(glm::vec2(-0.1f, -0.1f));
	for (int i = 1; i < n; ++i) {
		transformedVectorInnerTop = rotate * transformedVectorInnerTop;
		transformedNormalInnerTop = rotate * transformedNormalInnerTop;
		vertices.push_back(transformedVectorInnerTop);
		normals.push_back(transformedNormalInnerTop);
		textures.push_back(glm::vec2(-0.1f, -0.1f));
	}
	/* Lower ring outer circle vertices */
	glm::vec4 vectorOuterBottom(0.0f, outerRadius, -height / 2.0f, 1.0f);
	glm::vec4 transformedVectorOuterBottom = vectorOuterBottom;
	glm::vec4 normalOuterBottom(0.0f, outerRadius + 0.1f, -height / 2.0f - 0.1f, 1.0f);
	glm::vec4 transformedNormalOuterBottom = normalOuterBottom;
	vertices.push_back(vectorOuterBottom);
	normals.push_back(normalOuterBottom);
	textures.push_back(glm::vec2(-0.1f, -0.1f));
	for (int i = 1; i < n; ++i) {
		transformedVectorOuterBottom = rotate * transformedVectorOuterBottom;
		transformedNormalOuterBottom = rotate * transformedNormalOuterBottom;
		vertices.push_back(transformedVectorOuterBottom);
		normals.push_back(transformedNormalOuterBottom);
		textures.push_back(glm::vec2(-0.1f, -0.1f));
	}
	/* Lower ring inner circle vertices */
	glm::vec4 vectorInnerBottom(0.0f, innerRadius, -height / 2.0f, 1.0f);
	glm::vec4 transformedVectorInnerBottom = vectorInnerBottom;
	glm::vec4 normalInnerBottom(0.0f, innerRadius - 0.1f, -height / 2.0f - 0.1f, 1.0f);
	glm::vec4 transformedNormalInnerBottom = normalInnerBottom;
	vertices.push_back(vectorInnerBottom);
	normals.push_back(normalInnerBottom);
	textures.push_back(glm::vec2(-0.1f, -0.1f));
	for (int i = 1; i < n; ++i) {
		transformedVectorInnerBottom = rotate * transformedVectorInnerBottom;
		transformedNormalInnerBottom = rotate * transformedNormalInnerBottom;
		vertices.push_back(transformedVectorInnerBottom);
		normals.push_back(transformedNormalInnerBottom);
		textures.push_back(glm::vec2(-0.1f, -0.1f));
	}
}

void Ring::genIndices() {
	/* Upper ring indices*/
	for (int i = 0; i < n - 1; ++i) {
		indices.push_back(i);
		indices.push_back(i + n);
		indices.push_back(i + 1);
		indices.push_back(i + 1);
		indices.push_back(i + n);
		indices.push_back(i + n + 1);
	}
	indices.push_back(n - 1);
	indices.push_back(2 * n - 1);
	indices.push_back(0);
	indices.push_back(0);
	indices.push_back(2 * n - 1);
	indices.push_back(n);
	/* Lower ring indices*/
	for (int i = 2 * n; i < 3 * n - 1; ++i) {
		indices.push_back(i);
		indices.push_back(i + n);
		indices.push_back(i + 1);
		indices.push_back(i + 1);
		indices.push_back(i + n);
		indices.push_back(i + n + 1);
	}
	indices.push_back(3 * n - 1);
	indices.push_back(4 * n - 1);
	indices.push_back(2 * n);
	indices.push_back(2 * n);
	indices.push_back(4 * n - 1);
	indices.push_back(3 * n);
	/* */
	for (int i = 0; i < n - 1; ++i) {
		indices.push_back(i);
		indices.push_back(i + 2 * n);
		indices.push_back(i + 1);
		indices.push_back(i + 1);
		indices.push_back(i + 2 * n);
		indices.push_back(i + 2 * n + 1);
	}
	indices.push_back(n - 1);
	indices.push_back(3 * n - 1);
	indices.push_back(0);
	indices.push_back(0);
	indices.push_back(3 * n - 1);
	indices.push_back(2 * n);
	/* */
	for (int i = 0; i < n - 1; ++i) {
		indices.push_back(i + n);
		indices.push_back(i + 3 * n);
		indices.push_back(i + 1 + n);
		indices.push_back(i + 1 + n);
		indices.push_back(i + 3 * n);
		indices.push_back(i + 3 * n + 1);
	}
	indices.push_back(2 * n - 1);
	indices.push_back(4 * n - 1);
	indices.push_back(n);
	indices.push_back(n);
	indices.push_back(4 * n - 1);
	indices.push_back(3 * n);
}

Ring::Ring(float innerRadius, float outerRadius, float height) {
	this->innerRadius = innerRadius;
	this->outerRadius = outerRadius;
	this->height = height;
	this->width = 2 * outerRadius;
	this->depth = 2 * outerRadius;
	genVertices();
	genIndices();
	for (auto i = 0; i < vertices.size(); ++i) {
		colors.push_back(glm::vec3(0.5f, 0.5f, 0.5f));
	}
}

Ring::~Ring() {

}

float Ring::getOuterRadius() {
	return outerRadius;
}

float Ring::getInnerRadius() {
	return innerRadius;
}
