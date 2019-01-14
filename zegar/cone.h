#pragma once

#include "group.h"
#include "ring.h"
#include "clove.h" // to delete
#include "coneShape.h"

class Cone : public Group {
private:

	Ring *ring1;
	Ring *ring2;
	Ring *ring3;
	Ring *ring4;
	Ring *ring5;
	Ring *ring6;
	Ring *ring7;
	ConeShape coneShape;
	float moveCounter;
	bool bound; // 0 means that cone starts moving up, 1 means that cone starts moving down
public:
	Cone(int, float, bool);
	~Cone();
	void draw(float);
};
