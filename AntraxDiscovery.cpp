#pragma execution_character_set( "utf-8" )
#include "Menu.h"
#include "Gra.h"
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

int random(int min, int max) //range : [min, max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

// dodaje wynik do pliku
void dodajWynik(string imie, string wynik) {
	fstream plik;
	plik.open("wyniki.txt", ios::out | ios::app);
	plik << imie << endl;
	plik << wynik << endl;
}

void wypiszWyniki() {
	string imiona[20];
	string wyniki[20];

	fstream plik;
	plik.open("wyniki.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "nie itnieje taki plik" << endl;
		exit(0);
	}

	string linia;
	int nr_linii = 1;
	int IloscLinii = 0;
	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1: imiona[IloscLinii] = linia; break;
		case 2: wyniki[IloscLinii] = linia; break;
		}

		if (nr_linii == 2) { nr_linii = 1; IloscLinii++; }
		else { nr_linii = 2; }
	}
	plik.close();

	/*
	int n, i, j;
	string tmp, xyz;
	i = 0;
	while (i < nr_linii/2)
	{
		j = 0;
		while (j < nr_linii / 2)
		{
			if (stoi(wyniki[j]) > stoi(wyniki[j + 1]))
			{
				tmp = wyniki[j];
				wyniki[j] = wyniki[j + 1];
				wyniki[j + 1] = tmp;

				xyz = imiona[j];
				imiona[j] = imiona[j + 1];
				imiona[j + 1] = xyz;
			}
			j++;
		}
		i++;
	}
	*/

	cout << "Ksywa           Wyniki" << endl;
	for (int j = 0; j <= IloscLinii; j++)
	{
		string space;
		for (int x = 0; x < 15 - imiona[j].length(); x++) {
			space += " ";
		}

		cout << imiona[j] << space << wyniki[j] << endl;
	}
}

/*
wyniki.txt
1 linijka - imie
2 linijka - wynik
1 linijka - imie
2 linijka - wynik
1 linijka - imie
2 linijka - wynik
*/


int main()
{
	SetConsoleTitle(TEXT("Antrax Discovery"));
	const string teksty[10] = {
		"Jesteś beznadziejnym pilotem...",
		"Argh, nie doleciałes nawet do kolonii khalmer-yu...",
		"[Parę lat później] - Halo, halo baza... Znaleźliśmy resztki statku, jakiś dzban popisywał się wyłączając autopilota i wlecial w meteoryt",
		"Upsi... Ten meteoryt był bliżej niż się wydawało",
		"CO?! JAK TO ROZBIŁEŚ MÓJ DROGOCENNY STATEK!!! \n \n ...Co z tego że był stary, to była pamiątka rodzinna.",
		"Twoja rozgrywka jest daje pokazuje jak źle i rychle kończy się lot pod wpływem...",
		"Mogłeś się bardziej postarać...",
		"No nawet nawet..."
	};
	// Powiększenie okna
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleOutputCP(65001);
	Menu menu;
	
	bool czyDoMenu = true;

	//PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while (czyDoMenu) {
		menu.petla();
	
		system("CLS"); // Czyścimy pozostałości po menu
	
		auto gra = new Gra;
		string imie;
		switch (menu.wynik)
		{
		case 0: // Start
			//PlaySound(NULL, 0, 0);
			SetConsoleTextAttribute(hConsole, 15);
			gra->rozpocznijGre();
			cout << "\n";
			cout << "Twój wynik wynosi: " << gra->getWynik() << endl;
			SetConsoleTextAttribute(hConsole, 9);
			cout << teksty[random(0, 7)];
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "Podaj swoją ksywę kosmiczny fircyku: ";
			cin >> imie;
			if (imie.length() < 15) {
				dodajWynik(imie, to_string(gra->getWynik()));
			}
			system("CLS");

			
			SetConsoleTextAttribute(hConsole, 12);
			cout << "UWAGA! Awaryjne teleportowanie do najbliższej bazy.";

			for (int i = 0; i < 6; i++) {
				Sleep(1250);
				cout << ".";
				if (_kbhit()) {
					break;
				}
			}
			//PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 1: // Najlpesze wyniki
			wypiszWyniki();
			cout << endl << "Wciśnij dowolny klawisz aby iść dalej";
			_getch();
			break;
		case 2: // Wyjscie
			//PlaySound(NULL, 0, 0);
			czyDoMenu = false;
			break;
		}
		system("CLS");
	}
	return 0;
}



/*
[
[".", "."],
[".", "."],
[".", "."]
]




*/

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
