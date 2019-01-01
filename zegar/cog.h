#pragma once

#include "group.h"
#include "ring.h"
#include "cube.h"
#include "clove.h"

class Cog : public Group {
private:
	Ring *ringOuter;
	Ring *ringInner;
	Cube arms[4];
	std::vector<Clove *> teeth;
	float radius;
	float angularSpeed;
public:
	Cog(int, float);
	~Cog();
	float getRadius();
	void draw(float);
	float getAngularSpeed();
	void setAngularSpeed(float);
	void synchronizeSpeed(const Cog&);
};
