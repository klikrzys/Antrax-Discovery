#pragma once
#include "Byt.h"
#include <string>
#include <conio.h>
#include "Meteor.h"

class Gracz : public Byt
{
public:
	void aktualizuj();
	int GetInput();
	Gracz() = default;
	Gracz(int x, int y, string sciezkaDoWygladu);
	bool czyKoliduje(Meteor m);
};

