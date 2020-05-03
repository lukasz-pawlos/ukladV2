#include <iostream>
#include "sWektor.hh"
#include "Macierz.hh"
#include "UkladRownan.hh"
#include "rozmiar.h"
#include "LZespolona.hh"

using namespace std;


int main()
{
  char x;
  cin >> x;

  if (x == 'r') ///DLA DOUBLE
  {
      UkladRownanLiniowych<double, ROZMIAR> B;
      SWektor<double, ROZMIAR> C, D;

      cin >> B;

      C = B.obliczuklad(); //Obliczenie wektora wynikow
      B.wywtrans(); //Ztransponowanie macierzy

      cout << B;

      D = B.wekbl(C); //Obliczenie wektora bledu
      wyswrozw(C, D); // Wyswietlenie rozwiazan

      return 0;
  }
  else if (x == 'z')  ///DLA ZESPOLONYCH
  {
      UkladRownanLiniowych<LZespolona, ROZMIAR> B;
      SWektor<LZespolona, ROZMIAR> C, D;

      cin >> B;

      C = B.obliczuklad(); //Obliczenie wektora wynikow
      B.wywtrans(); //Ztransponowanie macierzy

      cout << B;

      D = B.wekbl(C); //Obliczenie wektora bledu
      wyswrozw(C, D); // Wyswietlenie rozwiazan

      return 0;

  }
  else
  {
      cout << endl << "Nieprawidlowa opcja wywolania!" << endl;
      cout << "Dostepne opcje to: 'r'->(rzeczywiste) lub 'z'->(zespolone)" << endl;

      return 1;
  }

}
