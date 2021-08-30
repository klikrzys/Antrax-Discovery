#include "Gra.h"

// Tworzy obiekty meteorytów
void Gra::inicjuj()
{
	int meteoNum = random(0, 5);
	string nazwaPliku = "meteo" + to_string(meteoNum) + ".txt";
	this->meteoryty.push_back(Meteor( random(2, szerokosc-2), -5, nazwaPliku));
}

int Gra::random(int min, int max) //range : [min, max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

void Gra::rozpocznijGre() {
	SetConsoleOutputCP(65001);
	puscMuzyke();
	for (int i = 0; i < 50; i++) {
		this->margin += " ";
	}
	this->Gracze.push_back(Gracz(10, wysokosc-3, "statek1.txt"));

	float deltaTime=0;
	int aktualnyPoziom = 0;
	int aktualnaSzybkoscGry = 90;

	int szybkosci[6] = { 80, 65, 57, 50, 42, 30 };

	//zaczynamy petle gry
	clock_t start = clock();
	int n  =  1500;
	while (this->stan_gry != 0) {
		/* Ró¿nica czasu pomiêdzy klatkami */
		if (deltaTime > n) {
			inicjuj();
			start = clock();
		}

		oczyscPlansze(); // Czyscimy dane z 'klatki'
		rysuj();
		aktualizuj();
		cout << this->margin <<"Wynik: " << this->wynik << endl;
		cout << this->margin << "Poziom: " << aktualnyPoziom + 1;


		deltaTime = ((float)clock() - start);

		Sleep(szybkosci[aktualnyPoziom]); // Szybkoœæ klatek
		this->wynik += 10;

		if(this->wynik==2000 || this->wynik == 4500|| this->wynik==9000 || this->wynik==15000 || this->wynik==18000 ){
			aktualnyPoziom++;
			aktualnaSzybkoscGry = szybkosci[aktualnyPoziom];
			n = n - 300;
		}
	}
	system("cls");
	PlaySound(NULL, 0, 0);
	return;
}

void Gra::rysuj()
{
	// Iterujemy tablice obiektow this->scena
	// x, y, wyglad [ [], [] ]
	this->Gracze.at(0).rysuj(this->plansza);
	
	for (size_t i = 0; i < this->meteoryty.size(); ++i) {
		if (this->meteoryty[i].shouldKill && this->meteoryty.size()>1) {
			this->meteoryty.erase(this->meteoryty.begin() + i);
		}
	}
	vector<Meteor> meteoryty = this->meteoryty;
	
	for (size_t i = 0; i < meteoryty.size(); ++i) {		
		meteoryty.at(i).rysuj(this->plansza);
	}

	const int lElementowNaEkranie = wysokosc * (szerokosc + 5);
	char listaZnakow[lElementowNaEkranie] ; // 

	int i = 0;

	for (size_t y = 0; y < wysokosc; ++y) {
		listaZnakow[i] = ' ';
		i++;
		listaZnakow[i] = '|';
		i++;
		for (size_t x = 0; x < szerokosc; ++x) {
			listaZnakow[i] = this->plansza[y][x];
			i++;
		}
		listaZnakow[i] = '|';
		i++;
		listaZnakow[i] = '\n';
		i++;
	}
	gotoXY(0, 0);
	//m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//WriteConsoleOutput(m_hConsole, m_bufScreen, { (short)m_nScreenWidth, (short)m_nScreenHeight }, { 0,0 }, &m_rectWindow);
	cout << listaZnakow << endl;
}

void Gra::aktualizuj(){
	this->Gracze.at(0).aktualizuj();
	
	for (size_t i = 0; i < this->meteoryty.size(); ++i) {
		this->meteoryty[i].aktualizuj();
		if (this->Gracze.at(0).czyKoliduje(this->meteoryty[i])) {
			this->stan_gry = 0; // Przegra³eœ - koniec sprawdzania
			break;
		}
	}
}

void Gra::oczyscPlansze() {
	//this->plansza[wysokosc][szerokosc] = {' '};
	
	for (int x= 0; x < szerokosc; x++) {
		for (int y = 0; y < wysokosc; y++) {
			this->plansza[y][x] = ' ';
		}
	}
	
}

Gra::Gra() {
	this->stan_gry = 1;
	oczyscPlansze();
}

void Gra::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Gra::puscMuzyke()
{
	PlaySound(TEXT("spaceship.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

int Gra::getWynik()
{
	return this->wynik;
}