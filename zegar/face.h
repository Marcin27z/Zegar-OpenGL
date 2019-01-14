#pragma once

#include "group.h"
#include "ring.h"
#include "cube.h"

class Face : public Group
{
private:
	Ring *bigRing;
	Ring *centralRing;
	Cube *hourHand;
	Cube *minuteHand;
	Cube *secondHand;
	Cube *hourDashes[4];
	float radius;
public:
	Face(float);
	~Face();
	
	void draw();
	void tick(float);
};

