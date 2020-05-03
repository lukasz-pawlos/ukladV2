#include "LZespolona.hh"
#include <iomanip>

using namespace std;


/*!
 * Podstawia do liczby zespolonej liczbę rzeczywistą.
 * Powoduje to, że w części urojonej zostanie automatycznie podstawiona
 * wartość 0.
 */
LZespolona LZespolona::operator = (double  Liczba)
{
  this->re = Liczba; this->im = 0;
  return *this;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik=0;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


LZespolona  operator - (LZespolona  Odjemna,  LZespolona  Odjemnik)
{
  LZespolona  Wynik;
  Wynik=0;

  Wynik.re = Odjemna.re - Odjemnik.re;
  Wynik.im = Odjemna.im - Odjemnik.im;
  return Wynik;
}




LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba)
{
  LZespolona  Wynik;
  Wynik=0;

  Wynik.re = Mnozna.re * Mnoznik_Liczba;
  Wynik.im = Mnozna.im * Mnoznik_Liczba;
  return Wynik;
}


LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  Wynik=0;

  Wynik.re = Skl1.re * Skl2.re + (-(Skl1.im * Skl2.im));
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double  Dzielnik)
{
  LZespolona  Wynik;
  Wynik=0;

  if (Dzielnik !=0)
  {
  Wynik.re = Skl1.re / Dzielnik;
  Wynik.im = Skl1.im / Dzielnik;
  return Wynik;
  }
  else
    cerr<< "Nie dzielimy przez zero";
}

LZespolona sprzezenie(LZespolona Skl)
{
    Skl.im = - (Skl.im);
    return Skl;
}

double  modul (LZespolona Skl)
{
  double Wynik;
  Wynik=0;

  Wynik = sqrt(pow(Skl.re, 2) + pow(Skl.im, 2));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
   LZespolona Wynik;
   Wynik=0;
   if(modul(Skl2) != 0)
     {
       Wynik = operator * (Skl1, sprzezenie(Skl2));
       Wynik.re = Wynik.re / pow(modul(Skl2),2);
       Wynik.im = Wynik.im / pow(modul(Skl2),2);
       return Wynik;
     }
     else
       cerr << "Nie dzielimy przez 0"<<endl;
}
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else
    return false;
}
bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re != Skl2.re && Skl1.im != Skl2.im)
    return true;
  else
    return false;
}


/*!
 * Umożliwia wyświetlenie liczby zespolonej w formacie:
 *             (4.5+5.6i)
 * Parametry:
 *    StrmWyj - strumień wyjściowy, do którego ma być wpisany napis
 *              reprezentujący liczbę zespoloną,
 *       Zesp - liczba zespolona, której wartość ma być zapisana w postaci
 *              znakowej w danym strumieniu.
 * Zwraca: Strumień wyjściowy przekazany jako pierwszy parametr.
 */
ostream &operator << (ostream &StrmWyj, LZespolona  Zesp)
{
  return StrmWyj << '(' << Zesp.re << showpos << Zesp.im << "i)" << noshowpos;
}

istream& operator >> (istream& StrWej, LZespolona& liczba)
{
	char tmp;

	StrWej >> tmp;
	if  (tmp != '(')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> liczba.re;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> liczba.im;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != 'i')
	{
        	StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != ')')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	return StrWej;
}
