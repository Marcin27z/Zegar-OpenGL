#pragma once

class Node {
protected:
	float positionX, positionY, positionZ;
	float width, height, depth;
	float velocityX, velocityY, velocityZ; //to be used later
	float angularSpeedX, angularSpeedY, angularSpeedZ; //to be used later
public:
	Node();
	~Node();
	virtual void draw() = 0;
	virtual void move(float, float, float) = 0;
	virtual void rotate(float, float, float) = 0;
	virtual void rotate(float, float, float, float, float, float) = 0;
	float getX();
	float getY();
	float getZ();
	float getWidth();
	float getHeight();
	float getDepth();
};