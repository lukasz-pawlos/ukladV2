#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  _Wsp[SWymiar];
  public:
    SWektor() { /*for (STyp &Wsp: _Wsp) Wsp = 0; */}

    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Wek) const;
    STyp operator * (const SWektor<STyp,SWymiar> &Wek) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    SWektor<STyp,SWymiar> operator / (double Dzielnik) const;
    bool operator == (const SWektor<STyp,SWymiar> &Wek) const;
    bool operator != (const SWektor<STyp,SWymiar> &Wek) const;
};

///DODAWANIE WEKTOROW
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Wek) const
{
  SWektor<STyp,SWymiar>  Wynik;
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind]=0;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] + Wek[Ind];
  return Wynik;
}



///ODEJMOWANIE WEKTOROW
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
  SWektor<STyp,SWymiar>  Wynik;
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind]=0;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}

///MNOZENIE WEKTOROW
template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &Wek) const
{
  STyp  Wynik,iloczyn;
  Wynik=0;


  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
  {
    iloczyn=0;
    iloczyn = (*this)[Ind] * Wek[Ind];
    Wynik = Wynik + iloczyn;
  }
  return Wynik;
}


///MNOZENIE PRZEZ LICZBE
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  SWektor<STyp,SWymiar>  Wynik;
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind]=0;


  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;
}

///DZIELENIE PRZEZ LICZBE
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (double Dzielnik) const
{
  SWektor<STyp,SWymiar>  Wynik;
  //Wynik=0;

    if(Dzielnik != 0)
    {
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]/Dzielnik;
  return Wynik;
    }
    else
    {
        std::cerr <<"Nie dzielimy przez zero";
    }
}



///ROWNOSC WEKTOROW
template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator == (const SWektor<STyp,SWymiar> &Wek) const
{
    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
    {
        if((*this)[Ind] != Wek[Ind])
            return false;
    }
    return true;
}

///NIEROWNOSC WEKTOROW
template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator != (const SWektor<STyp,SWymiar> &Wek) const
{
    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
    {
        if((*this)[Ind] == Wek[Ind])
            return false;
    }
    return true;
}


///Wczytywanie wartosci pod atrybuty danego obiektu typu 'Wektor'
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp, SWymiar> &Wek)
{
    STyp lacznik;
    for(int i=0; i<SWymiar; ++i) //Petla potrzebna do zapelnienia komorek tablicy obiektu
    {
        Strm >> lacznik;
        Wek[i]=lacznik; //Metoda klasy 'wektor' wprowadzajaca wartosci do obiektu
    }
    return Strm;
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    StrmWyj << " " << W[Ind];
  }
  return StrmWyj;
}

#endif
