#pragma once
#include <string>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "config.h"

using namespace std;

class Byt
{
public:
	void rysuj(char(&plansza)[wysokosc][szerokosc]);
	Byt(int, int, string);
	int getX();
	int getY();
	vector<vector<char>> getWyglad();
	int screenX;
	int screenY;
	void aktualizuj();
protected:
	int x;
	int y;
	void inicjujWyglad(string);
	vector<vector<char> > wyglad;
	bool czyJestWidoczny = false;
};