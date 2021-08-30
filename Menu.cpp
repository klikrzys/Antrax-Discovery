#include "Menu.h";

/*
Bierze konfiguracje ustawienia menu, i przesuwa w zale¿noœci
od podanego parametru "czyDoGory"

1. Bierzemy menu konf
2. Znajdujemy gdzie jest 'true'
3. Zmieniamy na 'false'
4. Dajemy 'true' jedno miejsce dalej
*/
bool* Menu::przesunMenuKonf(bool* konf, int n, bool czyDoGory) {
	// konf = {true, false, false}
	// konf = {false, true, false}
	// konf = {false, false, true}

	int i = 0;

	//wyszukanie aktualnie odpalonej pozycji
	while (konf[i] == false)
	{
		i++;
	}


	konf[i] = false;

	//Nastepny ew. poprzedni element zmieniamy 
	//w zale¿noœci od klikniêtej strza³ki
	if (czyDoGory) {
		if (i == 0) { konf[n - 1] = true; }
		else { konf[i - 1] = true; }
	}
	else {
		if (i < n - 1) { konf[i + 1] = true; }
		else { konf[0] = true; }
	}


	return konf;
}

void Menu::wypiszPlik(string nazwa_pliku) {
	string wiersz;
	ifstream plik(nazwa_pliku);
	if (plik.is_open())
	{
		while (getline(plik, wiersz))
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 9);	
			cout << wiersz << endl;
		}
		plik.close();
	}
	else {
		cout << "Unable to open file XD";
	}
}


void Menu::petla() {
	/*
	ASCII ART
		1. Za³adowaæ logo z pliku tesktowego

		2. Wyswietlic

		3. Sprawdziæ czy u¿ytkownik klikn¹³ strza³kê lub wcisn¹³ ENTER
	*/
	/*  Menu  */
	bool czyMenuTrwa = true;
	int start = 1;
	int ustawienia = 0;
	int wyjscie = 0;

	// start, ustawienia, wyjscie
	int liczbaEtykiet = 3;
	bool menuKonf[] = { true, false, false };
	string menuEtykiety[] = { "start", "wyniki", "wyjscie" };
	string strzalka = "-->";

	string margin;
	for (int i = 0; i < 50; i++) {
		margin += " ";
	}

	while (czyMenuTrwa) {
		wypiszPlik("title.txt");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 11);
		/*rysowanie menu*/
		for (int i = 0; i < liczbaEtykiet; i++) {
			cout << margin;
			if (menuKonf[i]) {
				cout <<strzalka;
			}
			else {
				cout << "   ";
			}
			cout << menuEtykiety[i] << endl;
		}

		int wybor;
		wybor = _getch();

		bool czyEnterWcisniety = false;

		switch (wybor)
		{
		case 80: //REAKCJA NA STRZA£KE W DO£
			przesunMenuKonf(menuKonf, liczbaEtykiet, false);
			break;
		case 72: //REAKCJA NA STRZA£KE W GORE
			przesunMenuKonf(menuKonf, liczbaEtykiet, true);
			break;
		case 13:
			czyEnterWcisniety = true;
			break;
		}


		//REAKCJA NA ENTER
		if (czyEnterWcisniety) {
			// wyszukujemy wybrany indeks
			int index = 0;
			while (!menuKonf[index])
			{
				index++;
			}

			// Reagujemy na wybór
			switch (index)
			{
			case 0: // Start
				this->wynik = 0;
				return;
				break;
			case 1: // Ustawienia
				this->wynik = 1;
				return;
				break;
			case 2: // Wyjscie
				this->wynik = 2;
				return;
				break;
			}
		}

		system("CLS");
	}
}