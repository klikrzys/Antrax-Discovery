#include "Meteor.h"

int Meteor::random(int min, int max) //range : [min, max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

void Meteor::aktualizuj()
{
	this->y += this->speed;

	if (y>wysokosc+5) {
		shouldKill = true;
	}
}

Meteor::Meteor(int x, int y, string sciezkaDoWygladu) : Byt(x, y, sciezkaDoWygladu) { }