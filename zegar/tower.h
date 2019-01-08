#pragma once
#include "mesh.h"
#include "shprogram.h"
class Tower : public Mesh
{
	virtual void genVertices();
	virtual void genIndices();
	void genNormals();
	void genTextures();
public:
	void draw(const ShaderProgram&);
	Tower(float, float, float);
	~Tower();
};

