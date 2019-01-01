#pragma once
#include "mesh.h"
class Clove :
	public Mesh
{
private:
	void genVertices();
	void genIndices();
public:
	Clove(float, float, float);
	Clove();
	~Clove();
	Clove& operator=(Clove other);
};