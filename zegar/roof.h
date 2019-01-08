#pragma once
#include "mesh.h"

class Roof : public Mesh {
	virtual void genVertices();
	virtual void genIndices();
	void genNormals();
	void genTextures();
public:
	Roof(float, float, float);
	~Roof();
};

