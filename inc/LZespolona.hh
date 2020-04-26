#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona &operator = (double  Liczba);

};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Mnozna,  double  Mnoznik_Liczba);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double  Dzielnik);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
bool operator == (LZespolona Skl1, LZespolona Skl2);
bool operator != (LZespolona Skl1, LZespolona Skl2);

LZespolona sprzezenie(LZespolona Skl);
double  modul (LZespolona Skl);


std::ostream &operator << (std::ostream &StrmWyj, LZespolona  Zesp);

#endif
