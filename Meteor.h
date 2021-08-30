#pragma once
#include "Byt.h"
#include <string>
#include <conio.h>
#include "config.h"

class Meteor: public Byt
{
public:
	int random(int min, int max);
	void aktualizuj();
	Meteor(int x, int y, string sciezkaDoWygladu);
	bool shouldKill = false;
private:
	int speed = random(1, 2);
};



