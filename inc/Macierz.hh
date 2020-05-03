#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>


///Macierz tworzona jest przez 3 Wektory
///3 Wektory POZIOME


template <typename STyp, int SWymiar>
class SMacierz {
    SWektor<STyp,SWymiar> tab[SWymiar];

public:

    SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const { return tab[Ind]; } //Przeciazenie operatora indeksowania do latwiejszego wczytywania
    SWektor<STyp,SWymiar> &operator [] (unsigned int Ind)       { return tab[Ind]; } //oraz wydawania wartosci z wektora

    STyp  operator () (unsigned int Ind, unsigned int j) const { return tab[Ind][j]; } //Przeciazenie operatora indeksowania do latwiejszego
    STyp &operator () (unsigned int Ind, unsigned int j)       { return tab[Ind][j]; } //wczytywania oraz wydawania wektorow

    void Transpozycja();
    void Zeruj();
    STyp det();

    SMacierz<STyp,SWymiar> operator + (const SMacierz<STyp,SWymiar> &Mac)const;
    SMacierz<STyp,SWymiar> operator - (const SMacierz<STyp,SWymiar> &Mac)const;
    SMacierz<STyp,SWymiar> operator * (const SMacierz<STyp,SWymiar> &Mac)const;
    SMacierz<STyp,SWymiar> operator * (double iloczyn)const;
    SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> &Wek)const;
    SMacierz<STyp,SWymiar> operator / (double dzielnik)const;
    bool operator == (const SMacierz &Mac);
    bool operator != (const SMacierz &Mac);

};

///WCZYTYWANIE MACIERZY
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &StrmWyj, SMacierz<STyp,SWymiar> &Mac)
{


    SWektor<STyp, SWymiar> lacznik;
    for(int i = 0; i<SWymiar; ++i) //Petla wczytujaca wektory do klasy
    {
        StrmWyj >> lacznik;
        Mac[i]=lacznik; //Wektor przekazywany za pomoca metody
    }
    return StrmWyj;
}


///WYPISYWANIE MACIERZY
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrWyj,const SMacierz<STyp,SWymiar> &Mac)
{
    StrWyj << std::endl;
    for(int i = 0; i<ROZMIAR; i++)
    {
        StrWyj << Mac[i] << std::endl;
    }
    return StrWyj;
}


///ZEROWANIE MACIERZY
template <typename STyp, int SWymiar>
void SMacierz<STyp,SWymiar>::Zeruj()
{
    SWektor<STyp,SWymiar> ZERO;
    for (int i = 0; i < SWymiar; ++i) ZERO[i]=0;

    for (int i = 0; i < SWymiar; ++i)
        (*this)[i] = ZERO;

}


///Transpozycja uzyta do mnozenia
template <typename STyp, int SWymiar>
void SMacierz<STyp,SWymiar>::Transpozycja()
{
    SWektor<STyp,SWymiar> C, D;
    SMacierz<STyp,SWymiar> Z;

    for(int i=0; i<ROZMIAR; ++i)
    {
        for(int y=0; y<ROZMIAR; ++y) //Glowna petla ktora, wyciaga wektor z macierzy i wrzuca jego
        {                            //wartosci do wartosci nowo stworzonego wektora
            C = tab[y];
            D[y] = C[i];
        }
        Z[i]=D; //Tutaj ten nowy wektor wchodzi do nowej macierzy
    }

    for(int i=0; i<ROZMIAR; ++i)
    {
        (*this)[i]=Z[i];
    }
}

///WYZNACZNIK
template <typename STyp, int SWymiar>
STyp SMacierz<STyp,SWymiar>::det()
{
    SMacierz<STyp,SWymiar> mac = (*this);

    STyp elem;
    STyp wynik;

    elem=0;
    wynik=1;

    for (int i = 0; i<ROZMIAR-1; i++)
    {
        for (int j = i+1; j<ROZMIAR; j++)
        {
            elem = mac.tab[j][i]/mac.tab[i][i]*(-1);
            for (int k = i; k<=ROZMIAR; k++)
            {
                mac.tab[j][k]=mac.tab[j][k]+(elem*mac.tab[i][k]);
            }
        }
    }

    for (int l = 0; l<ROZMIAR; l++)
    {
        wynik = (mac(l, l) * wynik);

    }
    return wynik;
}

///DODAWANIE MACIERZY
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>:: operator + (const SMacierz<STyp,SWymiar> &Mac)const
{
    SMacierz<STyp,SWymiar> Wynik;
    Wynik.Zeruj();
    for (int i=0; i<ROZMIAR; i++)
    {
       Wynik[i] = this->tab[i] + Mac.tab[i];
    }
    return Wynik;
}
///ODEJMOWANIE MACIERZY
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>:: operator - (const SMacierz<STyp,SWymiar> &Mac)const
{
    SMacierz<STyp,SWymiar> Wynik;
    Wynik.Zeruj();
    for (int i=0; i<ROZMIAR; i++)
    {
       Wynik[i] = this->tab[i] - Mac.tab[i];
    }
    return Wynik;
}


///MNOZENIE MACIERZY
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator * (const SMacierz<STyp,SWymiar> &Mac)const
{
    SMacierz<STyp,SWymiar> Wynik,Mnoznik;
    SWektor<STyp,SWymiar> Wek[ROZMIAR];
    Mnoznik = Mac;
    Mnoznik.Transpozycja();
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            Wek[i][j]=(*this)[i]*Mnoznik[j];
        }
        Wynik[i]=Wek[i];
    }
    return Wynik;
}

///MNOZENIE MACIERZY PRZEZ WEKTOR
template <typename STyp, int SWymiar>
SWektor <STyp,SWymiar> SMacierz <STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &Wek) const
{
    SWektor<STyp,SWymiar> Wynik;
    STyp pom;
    pom=0;

    for (int i = 0; i < SWymiar; ++i) Wynik[i]=0;

    for (int i=0; i<ROZMIAR; i++)
    {
        pom = (*this)[i] * Wek;
        Wynik[i]=pom;
    }
    return Wynik;
}

///MNOZENIE MACIERZY PRZEZ LICZBE
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator * (double iloczyn)const
{
    SMacierz<STyp,SWymiar> Wynik;
    Wynik.Zeruj();

    for (int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = (*this)[i] * iloczyn;
    }
    return Wynik;
}


///DZIELENIE MACIERZY PRZEZ LICZBE
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator / (double dzielnik)const
{
    SMacierz<STyp,SWymiar> Wynik;
    Wynik.Zeruj();

    if (dzielnik !=0)
    {
        for (int i=0; i<ROZMIAR; i++)
        {
            Wynik[i] = (*this)[i] / dzielnik;
        }
        return Wynik;
    }
    else
    {
        std::cerr << "Nie dzielimy przez 0";
    }
}

///ROWNOSC MACIERZY
template <typename STyp, int SWymiar>
bool SMacierz<STyp,SWymiar>::operator == (const SMacierz<STyp,SWymiar> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        if( (*this)[i]!=Mac[i])
        return false;
    }
    return true;
}


///NIEROWNOSC MACIERZY
template <typename STyp, int SWymiar>
bool SMacierz<STyp,SWymiar>::operator != (const SMacierz<STyp,SWymiar> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        if( (*this)[i]==Mac[i])
        return false;
    }
    return true;
}
#endif
