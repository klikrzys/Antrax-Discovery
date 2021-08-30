#include "Byt.h"
#include "Gra.h"
#include "config.h"

void Byt::rysuj(char(&plansza)[wysokosc][szerokosc])
{
	vector<vector<char>> wyglad = this->wyglad;

	for (unsigned int yi = 0; yi < wyglad.size(); yi++) {
		for (unsigned int xi = 0; xi < wyglad[yi].size(); xi++) {
			int actualY = this->getY() + yi;
			int actualX = this->getX() + xi;
			if (actualY < wysokosc && actualY  > 0 && actualX < szerokosc && actualX > 0) {
				plansza[actualY][actualX] = wyglad[yi][xi];
			}
		}
	}
}

/*
void Byt::aktualizuj() {
	cout << "XD";
	return;
}
*/

Byt::Byt(int x, int y, string sciezkaDoWygladu) {
	this->x = x;
	this->y = y;
	this->inicjujWyglad(sciezkaDoWygladu);
}

/*
Zamienia literki z pliku tekstowego na wektor dwuwymiarowy
*/
void Byt::inicjujWyglad(string nazwa_pliku) {
	string wiersz;
	ifstream plik("./"+nazwa_pliku);

	vector<vector<char>> wynik;

	if (plik.is_open())
	{
		// Wyci¹gamy poszczególne wiersze
		while (getline(plik, wiersz))
		{
			vector<char> wektor_wiersz;

			// Wiersz z pliku zamieniamy na wektor
			for (string::size_type i = 0; i < wiersz.size(); i++) {
				wektor_wiersz.push_back(wiersz[i]); // Ka¿d¹ nastêpn¹ literê w wierszu wrzucamy w wektor
			}

			wynik.push_back(wektor_wiersz); // Po zamienieniu wiersza na tablice, dodajemy go do wektora 2D
		}
		plik.close(); // Zamykamy po³¹czenie z plikiem tekstowym
		
		this->wyglad = wynik; // Ustawiamy nasza tablice 2D reprezentuj¹c¹ wygl¹d wewn¹trz obiektu 
	}
	else {
		cout << "Unable to open file XD";
	}
}

int Byt::getX()
{
	return this->x;
}

int Byt::getY()
{
	return this->y;
}

vector<vector<char> > Byt::getWyglad() {
	return this->wyglad;
}
