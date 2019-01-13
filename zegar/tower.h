#pragma once
#include "mesh.h"
#include "shprogram.h"
class Tower : public Mesh
{
public:
	enum Faces
	{
		NO = 0,
		BOTTOM = 1, TOP = 2, LEFT = 4, RIGHT = 8, FRONT = 16, BACK = 32,
		ALL = 1 + 2 + 4 + 8 + 16 + 32
	};
	Tower(float, float, float, Faces faces = Faces::ALL);
	~Tower();
private:
	virtual void genVertices();
	virtual void genIndices();
	void genNormals();
	void genTextures();
	Faces faces;
};

