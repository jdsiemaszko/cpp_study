#include <iostream>
using namespace std;

typedef bool (*LiniowyPorzadek) (int, int);

// funkcja pomocnicza
void wypisz(int tablica[], int iloscElementow)
{
  int i;
  for(i=0;i<iloscElementow-1;++i)
    cout << tablica[i] << ",";
  cout << tablica[i] << endl;
}

// pierwsza sortujaca
// ostatnim argumentem jest wskaznik do funkcji
// ktora realizuje porownywanie
void sortuj(int tablica[], int iloscElementow, LiniowyPorzadek porownaj)
{
  for(int i=0;i<iloscElementow-1;i++)
  {
    for(int j=i+1;j<iloscElementow;j++)
    {
      if( porownaj(tablica[i],tablica[j]) ) // uzywamy wskaznika do funkcji
      {
        int temp = tablica[i];
        tablica[i] = tablica[j];
        tablica[j] = temp;
      }
    }
  }
}

// przykladowe funkcje porownujace
bool mniejsze(int a, int b)
{
  return a<b;
}

bool wieksze(int a, int b)
{
  return a>b;
}

bool mniejszaWartoscBezwzgledna(int a, int b)
{
  int c = a;
  int d = b;
  if(c<0) c=-c;
  if(d<0) d=-d;
  if(c==d) return a > b;
  return c>d;
}

int main()
{
  int i[] = {7,5,-1,4,5,6,1,-9,1,-4};
  wypisz(i,10);
  sortuj(i,10,mniejsze);
  wypisz(i,10);
  cout << endl;
  
  int j[] = {7,5,-1,4,5,6,1,-9,1,-4};
  wypisz(j,10);
  sortuj(j,10,wieksze);
  wypisz(j,10);
  cout << endl;

  int k[] = {7,5,-1,4,5,6,1,-9,1,-4};
  wypisz(k,10);
  sortuj(k,10,mniejszaWartoscBezwzgledna);
  wypisz(k,10);
  cout << endl;

  return 0;
}