#include "tower.h"

void Tower::genVertices()
{

	if (faces & Faces::BOTTOM) {
		// A (bottom)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 0
		vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 1
		vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 2
		// B (bottom)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 3
		vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 4
		vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 5
	}

	if (faces & Faces::TOP) {
		// C (top)
		vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 6
		vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 7
		vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 8
		// D (top)
		vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 9
		vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 10
		vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 11
	}

	if (faces & Faces::LEFT) {
		// E (left)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 12
		vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 13
		vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 14
		// F (left)
		vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 15
		vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 16
		vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 17
	}

	if (faces & Faces::RIGHT) {
		// G (right)
		vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 18
		vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 19
		vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 20
		// H (right)
		vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 21
		vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 22
		vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 23
	}

	if (faces & Faces::FRONT) {
		// I (front)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, -1.0f, 1.0f));  // 24 
		vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 25
		vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 26
		// J (front)
		vertices.push_back(glm::vec4(-1.0f, 1.0f, -1.0f, 1.0f));   // 27
		vertices.push_back(glm::vec4(1.0f, 1.0f, -1.0f, 1.0f));    // 28
		vertices.push_back(glm::vec4(1.0f, -1.0f, -1.0f, 1.0f));   // 29
	}

	if (faces & Faces::BACK) {
		// K (back)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 30
		vertices.push_back(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f));    // 31
		vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 32
		// L (back)
		vertices.push_back(glm::vec4(-1.0f, -1.0f, 1.0f, 1.0f));   // 33
		vertices.push_back(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));     // 34
		vertices.push_back(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f));    // 35	
	}

	setNormals();
}

void Tower::genTextures()
{
	if (faces & Faces::BOTTOM) {
		// A (bottom)
		textures.push_back(glm::vec2(0.2500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.2500f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.5000f, 2.0f / 3.0f));
		// B (bottom)
		textures.push_back(glm::vec2(0.2500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.5000f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.5000f, 1.0f / 3.0f));
	}

	if (faces & Faces::TOP) {
		// C (top)
		textures.push_back(glm::vec2(1.0000f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(1.0000f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.7500f, 1.0f / 3.0f));
		// D (top)
		textures.push_back(glm::vec2(0.7500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(1.0000f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.7500f, 2.0f / 3.0f));
	}

	if (faces & Faces::LEFT) {
		// E (left)
		textures.push_back(glm::vec2(0.2500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.0000f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.2500f, 2.0f / 3.0f));
		// F (left)
		textures.push_back(glm::vec2(0.0000f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.0000f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.2500f, 2.0f / 3.0f));
	}

	if (faces & Faces::RIGHT) {
		// G (right)
		textures.push_back(glm::vec2(0.5000f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.7500f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.5000f, 2.0f / 3.0f));
		// H (right)
		textures.push_back(glm::vec2(0.5000f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.7500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.7500f, 2.0f / 3.0f));
	}

	if (faces & Faces::FRONT) {
		// I (front)
		textures.push_back(glm::vec2(0.2500f, 1.0f / 3.0f));
		textures.push_back(glm::vec2(0.2500f, 0.0000f));
		textures.push_back(glm::vec2(0.5000f, 1.0f / 3.0f));
		// J (front)
		textures.push_back(glm::vec2(0.2500f, 0.0000f));
		textures.push_back(glm::vec2(0.5000f, 0.0000f));
		textures.push_back(glm::vec2(0.5000f, 1.0f / 3.0f));
	}

	if (faces & Faces::BACK) {
		// K (back)
		textures.push_back(glm::vec2(0.2500f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.2500f, 1.0000f));
		textures.push_back(glm::vec2(0.5000f, 1.0000f));
		// L (back)
		textures.push_back(glm::vec2(0.2500f, 2.0f / 3.0f));
		textures.push_back(glm::vec2(0.5000f, 1.0000f));
		textures.push_back(glm::vec2(0.5000f, 2.0f / 3.0f));
	}

}

void Tower::genIndices()
{
	for (int i = 0; i < vertices.size(); i++)
		indices.push_back(i);
}

void Tower::genNormals()
{
	
}

Tower::Tower(float width = 1.0f, float height = 1.0f, float depth = 1.0f, Faces faces)
{
	this->faces = faces;
	genVertices();
	genIndices();
	genTextures();
	genNormals();
	for (int i = 0; i < vertices.size(); i++)
		colors.push_back(glm::vec3(0.2, 0, 0));
	scale(width, height, depth);
	texture = loadMipmapTexture(GL_TEXTURE0, "Textures\\tower.png");
}

Tower::~Tower()
{
}


/*

Group tower;
Roof roof(0.50, 0.50, 0.50);         roof.move(0, 0, 1.25);       tower.add(&roof);
Tower towerLevel0(0.25, 0.25, 0.25);                              tower.add(&towerLevel0);
Tower towerLevel1(0.25, 0.25, 0.25); towerLevel1.move(0, 0, 0.5); tower.add(&towerLevel1);
Tower towerLevel2(0.25, 0.25, 0.25); towerLevel2.move(0, 0, 1.0); tower.add(&towerLevel2);
tower.move(0, 0.3, 0);

*/


