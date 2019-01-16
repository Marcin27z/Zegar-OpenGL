#include "cone.h"

Cone::Cone(int teethNumber, float size, bool b) {

	ring1 = new Ring(0.5f, 0.75f, 0.3f);
	ring2 = new Ring(0.5f, 0.75f, 0.3f);
	ring3 = new Ring(0.5f, 0.75f, 0.3f);
	ring4 = new Ring(0.5f, 0.75f, 0.3f);
	ring5 = new Ring(0.5f, 0.75f, 0.3f);
	ring6 = new Ring(0.5f, 0.75f, 0.3f);
	ring7 = new Ring(0.5f, 0.75f, 0.3f);
	ring1->rotate(0.0f, 90.0f, 90.0f);
	ring3->rotate(0.0f, 90.0f, 0.0f);
	ring5->rotate(0.0f, 90.0f, 0.0f);
	ring7->rotate(0.0f, 90.0f, 0.0f);
	ring1->move(0.0f, -3.0f, 0.0f);
	ring2->move(0.0f, -2.0f, 0.0f);
	ring3->move(0.0f, -1.0f, 0.0f);
	ring4->move(0.0f, 0.0f, 0.0f);
	ring5->move(0.0f, 1.0f, 0.0f);
	ring6->move(0.0f, 2.0f, 0.0f);
	ring7->move(0.0f, 3.0f, 0.0f);

	coneShape = ConeShape(3.0f, 4.0f, 3.0f);
	coneShape.move(0.0f, -5.5f, 0.0f);

	addAll(ring1, ring2, ring3, ring4, ring5, ring6, ring7, &coneShape);

	// TODO: for loop to delete
	float ratio = float(teethNumber) / 24.0f;
	for (int i = 0; i < teethNumber; i++) {
		Clove *cube2 = new Clove(0.1f / ratio, 0.29f, 0.1f / ratio);
	}

	scale(size, size, size);
	moveCounter = 0;
	bound = b;
}

Cone::~Cone() {
	delete ring1;
	delete ring2;
	delete ring3;
	delete ring4;
	delete ring5;
	delete ring6;
	delete ring7;
}

void Cone::draw(float deltaTime) {
	if (bound == 0) {
		if (moveCounter < 0.6f) {
			move(0.0f, 1.0f *deltaTime, 0.0f);
			moveCounter += 1.0f * deltaTime;
		}
		else
			bound = 1; // reached upper bound
	}
	if (bound == 1) {
		if (moveCounter > -0.6f) {
			move(0.0f, -1.0f *deltaTime, 0.0f);
			moveCounter -= 1.0f * deltaTime;
		}
		else
			bound = 0; // reached bottom bound
	}
	Group::draw();
}
