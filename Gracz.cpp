#include "Gracz.h"

int Gracz::GetInput()
{
	int result=0;

	try
	{
		result = _kbhit();
	}
	catch (string w)//catch przechwyca dany wyj¹tek string
	{
		result = 2;
	}

	if (result != 0)
	{
		unsigned char input = _getch();
		return input;
	}

	return 0;
}

void Gracz::aktualizuj()
{
	int kodKliknietoKlawisza = GetInput();

	if (kodKliknietoKlawisza == 77 && this->x + 3 < szerokosc - this->wyglad[0].size()) { //W prawo
		this->x += 3;
	}
	else if (kodKliknietoKlawisza == 75 && this->x - 3 > 0) { // W lewo
		this->x -= 3;
	}
	
}

Gracz::Gracz(int x, int y, string sciezkaDoWygladu) : Byt(x, y, sciezkaDoWygladu) { }

bool Gracz::czyKoliduje(Meteor m)
{
	int	yl = this->wyglad.size();
	int xl = this->wyglad[0].size();
	
	int xMin = this->getX();
	int yMin = this->getY();
	int xMax = xMin + xl;
	int yMax = yMin + yl;

	vector<vector<char>> meteoWyglad = m.getWyglad();
	for (int ym = 0; ym < meteoWyglad.size(); ym++) {
		for (int xm = 0; xm < meteoWyglad[ym].size(); xm++) {
			int meteoY = m.getY() + ym;
			int meteoX = m.getX() + xm;

			if (xMin < meteoX && xMax > meteoX && yMin < meteoY && yMax > meteoY) {
				return true;
			}
		}
	}
	return false;
}
