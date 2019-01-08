#include "tower.h"

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


