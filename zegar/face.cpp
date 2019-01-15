#include "face.h"
#include <ctime>


Face::Face(float size)
{
	bigRing = new Ring(0.0f, 1.0f, 0.2f);
	centralRing = new Ring(0.0f, 0.2f, 0.4f);
	hourHand = new Cube(0.1f, 0.5f, 0.02f);
	minuteHand = new Cube(0.05f, 0.9f, 0.02f);
	secondHand = new Cube(0.02f, 0.9f, 0.02f);
	hourDashes[0] = new Cube(0.02, 0.1, 0.04);
	hourDashes[1] = new Cube(0.02, 0.1, 0.04);
	hourDashes[2] = new Cube(0.02, 0.1, 0.04);
	hourDashes[3] = new Cube(0.02, 0.1, 0.04);

	/*
		bigRing->setColor(0.165f, 0.169f, 0.180f);
		centralRing->setColor(0.453f, 0.553f, 0.453f);
		hourHand->setColor(0.643f, 0.760f, 0.659f);
		minuteHand->setColor(0.675f, 0.922f, 0.384f);
		secondHand->setColor(0.341f, 1.0f, 0.255f);
		hourDashes[0]->setColor(0.453f, 0.553f, 0.453f);
		hourDashes[1]->setColor(0.453f, 0.553f, 0.453f);
		hourDashes[2]->setColor(0.453f, 0.553f, 0.453f);
		hourDashes[3]->setColor(0.453f, 0.553f, 0.453f);
	*/
	bigRing->setColor(0.829, 0.829, 0.829);
	centralRing->setColor(0.5, 0.5, 0.5);
	hourHand->setColor(0.4, 0.4, 0.4);
	minuteHand->setColor(0.3, 0.3, 0.3);
	secondHand->setColor(0.2, 0.2, 0.2);
	hourDashes[0]->setColor(0.453f, 0.553f, 0.453f);
	hourDashes[1]->setColor(0.453f, 0.553f, 0.453f);
	hourDashes[2]->setColor(0.453f, 0.553f, 0.453f);
	hourDashes[3]->setColor(0.453f, 0.553f, 0.453f);

	hourHand->move(0.0f, 0.25f, 0.12f);
	minuteHand->move(0.0f, 0.5f, 0.14f);
	secondHand->move(0.0f, 0.5f, 0.16f);
	hourDashes[0]->move(0.0f, 0.9f, 0.12f);
	hourDashes[1]->move(0.0f, 0.9f, 0.12f);
	hourDashes[2]->move(0.0f, 0.9f, 0.12f);
	hourDashes[3]->move(0.0f, 0.9f, 0.12f);

	hourDashes[1]->rotate(0.0f, 0.0f, 90.0f, 0.0f, 0.0f, 0.5f);
	hourDashes[2]->rotate(0.0f, 0.0f, 180.0f, 0.0f, 0.0f, 0.5f);
	hourDashes[3]->rotate(0.0f, 0.0f, 270.0f, 0.0f, 0.0f, 0.5f);

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	int hour = aTime->tm_hour % 12;
	int min = aTime->tm_min;
	int sec = aTime->tm_sec;
	secondHand->rotate(0.0f, 0.0f, -sec * 6, 0.0f, 0.0f, 0.5f);
	minuteHand->rotate(0.0f, 0.0f, -min * 6 - sec / 10.0, 0.0f, 0.0f, 0.5f);
	hourHand->rotate(0.0f, 0.0f, -hour * 30 - min / 60.0 * 30, 0.0f, 0.0f, 0.5f);

	addAll(bigRing, centralRing, hourHand, minuteHand, secondHand, hourDashes[0], hourDashes[1], hourDashes[2], hourDashes[3]);
	scale(size, size, size);
}


Face::~Face()
{
}

void Face::draw()
{
	Group::draw();
}

void Face::tick(float deltaTime)
{
	float secondHandTick = 1.0f * deltaTime * 6;
	float minuteHandTick = 1.0f * deltaTime / 10.0;
	float hourHandTick = 1.0f * deltaTime / 600.0;

	secondHand->rotate(0.0f, 0.0f, -secondHandTick, 0.0f, 0.0f, 0.5f);
	minuteHand->rotate(0.0f, 0.0f, -minuteHandTick, 0.0f, 0.0f, 0.5f);
	hourHand->rotate(0.0f, 0.0f, -hourHandTick, 0.0f, 0.0f, 0.5f);

	draw();
}