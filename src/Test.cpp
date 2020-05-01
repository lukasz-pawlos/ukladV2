#include "Test.hh"
using namespace std;

void Test_SzablonWektor_double()
{
  cout << endl
       << " --------- Test klasy Wektor<double," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<double,ROZMIAR>    W, W_wynik,Z;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind] = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;





for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    Z[Ind] = 3;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: Z" << endl
       << "        " << Z << endl
       << endl;

  cout << "  Wyswietlenie wyniku: W+Z" << endl
       << "        " << W+Z << endl
       << endl;

  cout << "  Wyswietlenie wyniku: W-Z" << endl
       << "        " << W-Z << endl
       << endl;

  cout << "  Wyswietlenie wyniku: W*Z" << endl
       << "        " << W*Z << endl
       << endl;

  cout << "  Wyswietlenie wyniku: W*2" << endl
       << "        " << W*2 << endl
       << endl;


cout << "  Wyswietlenie wyniku: W/2" << endl
       << "        " << W/2 << endl
       << endl;




}




void Test_SzablonWektor_LZespolona()
{
  cout << endl
       << " --------- Test klasy Wektor<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;


  SWektor<LZespolona,ROZMIAR>    W,Z, W_wynik;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    W[Ind].re = Ind;      W[Ind].im = Ind;
  }

  cout << "  Wyswietlenie wspolrzednych wektora: W" << endl
       << "        " << W << endl
       << endl;


  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    Z[Ind].re = 2;      Z[Ind].im = 2;
  }
   cout << "  Wyswietlenie wspolrzednych wektora: Z" << endl
       << "        " << Z << endl
       << endl;

    cout << "  Wyswietlenie wspolrzednych wektora: W+Z" << endl
       << "        " << W+Z << endl
       << endl;

    cout << "  Wyswietlenie wspolrzednych wektora: W-Z" << endl
       << "        " << W-Z << endl
       << endl;

    cout << "  Wyswietlenie wspolrzednych wektora: W*Z" << endl
       << "        " << W*Z << endl
       << endl;

    cout << "  Wyswietlenie wspolrzednych wektora: W*2" << endl
       << "        " << W*2 << endl
       << endl;

     cout << "  Wyswietlenie wspolrzednych wektora: W/2" << endl
       << "        " << W/2 << endl
       << endl;
}


void Test_Macierz_Double()
{

     cout << endl
       << " --------- Test klasy Macierz<double," << ROZMIAR << "> ----------" << endl
       << endl;


  Macierz<double,ROZMIAR>    A,B;

    SWektor<double,ROZMIAR>    X,Z;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    X[Ind] = Ind;
    Z[Ind] = 3;
  }

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    A[Ind]=X;
    B[Ind]=Z;
  }
cout <<"MACIERZ A"<< A;
cout <<"MACIERZ B"<< B;

cout<<"DODAWANIE A+B"<<A+B;
cout<<"ODEJMOWANIE A-B"<<A-B;
cout<<"MNOZENIE A*B"<<A*B;
cout<<"MNOZENIE A*2"<<A*2;
cout<<"MNOZENIE A/2"<<A/2;


}


void Test_Macierz_LZespolona()
{

      cout << endl
       << " --------- Test klasy Macierz<LZespolona," << ROZMIAR << "> ----------" << endl
       << endl;

  SWektor<LZespolona,ROZMIAR>    X,Z;
  Macierz<LZespolona,ROZMIAR>  A,B;

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind) {
    X[Ind].re = Ind;      X[Ind].im = Ind;
    Z[Ind].re = 3;      Z[Ind].im = 3;
}

  for (unsigned int Ind = 0; Ind < ROZMIAR; ++Ind)
  {
    A[Ind]=X;
    B[Ind]=Z;
  }



cout <<"MACIERZ A"<< A;
cout <<"MACIERZ B"<< B;

cout<<"DODAWANIE A+B"<<A+B;
cout<<"ODEJMOWANIE A-B"<<A-B;
cout<<"MNOZENIE A*B"<<A*B;
cout<<"MNOZENIE A*2"<<A*2;
cout<<"MNOZENIE A/2"<<A/2;



}






