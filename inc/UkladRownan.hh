#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "SWektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>
class UkladRownanLiniowych {

    SMacierz<STyp,SWymiar> mac;
    SWektor<STyp,SWymiar> wek;

  public:

    void wezmU(SWektor<STyp, SWymiar> C, int i) //Wczytuje wektor do macierzy wspolczynnikow
    {
        mac[i]=C;
    }

    void wezwU(STyp z, int p) //Wczytuje liczbe do wektora wyrazow wolnych
    {
         wek[p] = z;
    }

    STyp dajwU(int b) const //Wydaje konkretne wartosci wektora wyrazow wolnych
    {
       return  wek[b];
    }

    SWektor<STyp, SWymiar> dajj(int i) const //Wydaje wektor z macierzy wspolczynnikow
    {
        return mac[i];
    }

    void wywtrans() //Wywoluje transponowanie macierzy wspolczynnikow
    {
        mac.Transpozycja();
    }


    SWektor<STyp,SWymiar> obliczuklad(); //Metoda obliczajaca uklad rownan

    SWektor<STyp,SWymiar> wekbl(const SWektor<STyp,SWymiar> zz); //Metoda obliczajaca wektor bledu

};


///WCZYTYWANIE UKLADU
 template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
    SWektor<STyp, SWymiar> wek;
    STyp liczba;

    for(int i=0; i<SWymiar; ++i) //Wczytanie macierzy wspolczynnikow
    {
        Strm >> wek;
        UklRown.wezmU(wek, i);
    }

    for(int i=0; i<SWymiar; ++i) //Wczytanie wektora wyrazow wolnych
    {
        Strm >> liczba;
        UklRown.wezwU(liczba, i);

    }

    return Strm;
}

///WYPISANIE UKLADU
template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych <STyp,SWymiar> &UklRown)
{
    Strm << std::endl << "Uklad rownan do rozwiazania: " << std::endl << std::endl;
    for(int i=0; i<SWymiar; ++i) // Petla wyswietlajaca uklad rownan
    {
        Strm << "|  " << UklRown.dajj(i) <<  "| | x_" << i+1 << " |";
        if((i==SWymiar/2)) //Wyswietlaj znak '=' wraz z ramka macierzy przy przejsciu przez polowe dlugosci ukladu
        {
            Strm << " = | " << UklRown.dajwU(i) << " |" << std::endl;
        }
        else
        {
            Strm << "   | " << UklRown.dajwU(i) << " |" << std::endl; //W przeciwnym wypadku ramke macierzy bez '='
        }

    }
    Strm << std::endl << std::endl;
    return Strm;
}




///Metoda obliczajaca uklad rownana metoda Cramera
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> UkladRownanLiniowych<STyp,SWymiar>::obliczuklad ()
{
    STyp x, y;
    SWektor<STyp,SWymiar> wynik, tmpglowny;
    SMacierz<STyp,SWymiar> X;

    X = mac; //zrobienie kopii pomocniczej
    y = X.det(); //obliczenie wyznacznika glownego
    for (int i = 0; i<ROZMIAR; ++i)
    {
        tmpglowny = mac[i]; //pobranie wektora z macierzy wspolczynnikow jako kopii
        mac[i]=wek; //wlozenie na jego miejsce wektora wyrazow wolnych
        X = mac; //zaktualizowanie kopii
        x = X.det(); //obliczenie wyznacznika na kopii z uwagi zniszczenie struktury macierzy metoda gaussa
        wynik[i]=x/y; //wlozenie do wektora z wynikami obliczonej wartosci podzielonej, z uwagi na wzor cramera
        mac[i]=tmpglowny; //odlozenie spowrotem na miejsce wektora wczesniej zabranego
    }

    return wynik; //Zwrocenie wektora z wynikiem

}

///WEKTOR BLEDU
template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> UkladRownanLiniowych<STyp, SWymiar>::wekbl(SWektor<STyp, SWymiar> zz)
{
    zz= mac*zz;
    std::cout << wek;
    std::cout << zz;

    return zz - wek; //Od nowego wektora odejmujemy wektor wyrazow wolnych
}

///ROZWIAZANIE
template <typename STyp, int SWymiar>
void wyswrozw(SWektor<STyp, SWymiar> C, SWektor<STyp, SWymiar> B)
{
  std::cout << "Wektor rozwiazan:" << std::endl  << std::endl << "\t     " << C << std::endl << std::endl;
  std::cout << "Wektor bledu:" << std::endl << std::endl << "\tAx-b  =  (  " << B << ")" << std::endl << std::endl;
}





#endif

