#pragma once
#pragma comment(lib, "winmm.lib")
#include "Gracz.h"
#include "Byt.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "config.h"
#include "Meteor.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <windows.h>

using namespace std;

class Gra
{
public:
	void inicjuj();
	int random(int min, int max);
	void rozpocznijGre();
	void rysuj();
	void aktualizuj();
	void oczyscPlansze();
	Gra();
	char plansza[wysokosc][szerokosc];
	vector<Meteor> meteoryty;
	vector<Gracz> Gracze;
	/*
	Stany Gry

		1 = Gra zaczyna
		2 = Tylko mateoryty
		3 = Statki
		4 = Statki i meteoryty
	0 = Koniec gry <---- Koniec pkt ¿ycia, albo wyjscie
	*/
	int stan_gry = 1;
	int getWynik();
private:
	int wynik=0;
	void gotoXY(int x, int y);
	void puscMuzyke();
	string margin;
};