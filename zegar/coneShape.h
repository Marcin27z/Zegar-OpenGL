#pragma once
#include "mesh.h"
class ConeShape :
	public Mesh
{
private:
	void genVertices();
	void genIndices();
public:
	ConeShape(float, float, float);
	ConeShape();
	~ConeShape();
	ConeShape& operator=(ConeShape other);
};