#include "node.h"

Node::Node() {
	positionX = 0.0f;
	positionY = 0.0f;
	positionZ = 0.0f;
}

Node::~Node() {

}

float Node::getX() {
	return positionX;
}

float Node::getY() {
	return positionY;
}

float Node::getZ() {
	return positionZ;
}

float Node::getWidth() {
	return width;
}

float Node::getHeight() {
	return height;
}

float Node::getDepth() {
	return depth;
}
