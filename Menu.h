#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Menu
{
public: //prawo dost�pu: publiczne
	int wynik;
	void petla();
private:
	bool* przesunMenuKonf(bool* konf, int n, bool czyDoGory);
	void wypiszPlik(string nazwa_plik);
};