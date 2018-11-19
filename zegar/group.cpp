#include "group.h"

Group::Group() {

}

Group::~Group() {

}

void Group::move(float xMove, float yMove, float zMove) {
	positionX += xMove;
	positionY += yMove;
	positionZ += zMove;
	for (auto && object : objects) {
		(*object).move(xMove, yMove, zMove);
	}
}

void Group::rotate(float xAngle, float yAngle, float zAngle) {
	for (auto && object : objects) {
		(*object).rotate(xAngle, yAngle, zAngle);
	}
}

void Group::rotate(float xAngle, float yAngle, float zAngle, float xPivot, float yPivot, float zPivot) {
	for (auto && object : objects) {
		(*object).rotate(xAngle, yAngle, zAngle, xPivot, yPivot, zPivot);
	}
}

void Group::draw() {
	for (auto && object : objects) {
		(*object).draw();
	}
}

void Group::add(Node *object) {
	objects.push_back(object);
}